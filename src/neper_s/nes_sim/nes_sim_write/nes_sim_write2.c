/* This file is part of the Neper software package. */
/* Copyright (C) 2003-2013, Romain Quey. */
/* See the COPYING file in the top-level directory. */

#include "nes_sim_write_.h"

void
nes_sim_write_inputs (struct IN_S In, struct SIM *pSim)
{
  int i, filenameqty = 4;
  char **filename = ut_alloc_1d_pchar (filenameqty);
  char *dir = ut_string_paste (In.simdir, "/inputs");

  ut_string_string ((*pSim).tess, filename);
  ut_string_string ((*pSim).msh, filename + 1);
  ut_string_string ("simulation.config", filename + 2);
  ut_string_string ("*.sh", filename + 3);

  if ((*pSim).bcs)
  {
    filename = ut_realloc_1d_pchar (filename, ++filenameqty);
    filename[filenameqty - 1] = NULL;
    ut_string_string ((*pSim).bcs, filename + filenameqty - 1);
  }
  if ((*pSim).ori)
  {
    filename = ut_realloc_1d_pchar (filename, ++filenameqty);
    filename[filenameqty - 1] = NULL;
    ut_string_string ((*pSim).ori, filename + filenameqty - 1);
  }
  if ((*pSim).phase)
  {
    filename = ut_realloc_1d_pchar (filename, ++filenameqty);
    filename[filenameqty - 1] = NULL;
    ut_string_string ((*pSim).phase, filename + filenameqty - 1);
  }

  ut_dir_openmessage (dir, "w");
  ut_sys_mkdir ("%s/inputs", In.simdir);

  for (i = 0; i < filenameqty; i++)
    nes_sim_write_inputs_file (In, *pSim, filename[i]);

  ut_dir_closemessage (dir, "w");

  if ((*pSim).ElsetQty == 0)
    neut_sim_init_elsetqty (pSim);

  neut_sim_fprintf (In.simdir, *pSim, "W");

  ut_free_1d_char (&dir);
  ut_free_2d_char (&filename, filenameqty);

  return;
}

void
nes_sim_write_results (struct IN_S In, struct SIM *pSim)
{
  char *dir = ut_string_paste (In.simdir, "/results");

  ut_dir_openmessage (dir, "w");
  ut_sys_mkdir (dir);

  if ((*pSim).NodeResQty)
    nes_sim_write_results_entity (In, pSim, "node");

  if ((*pSim).EltResQty)
    nes_sim_write_results_entity (In, pSim, "element");

  ut_free_1d_char (&dir);

  return;
}

void
nes_sim_write_restart (char *indir, char *outdir, struct SIM Sim)
{
  int i;
  char *dir = ut_string_paste (outdir, "/restart");
  char *filename = ut_alloc_1d_char (1000);
  char *infile = ut_alloc_1d_char (1000);
  char *outfile = ut_alloc_1d_char (1000);

  ut_dir_openmessage (dir, "w");
  ut_sys_mkdir (dir);

  sprintf (filename, "rst%d.control", Sim.RestartId);
  sprintf (infile, "%s/%s", indir, filename);
  sprintf (outfile, "%s/restart/%s", outdir, filename);

  ut_print_message (0, 4, "%s...\n", filename);
  ut_file_cp (infile, outfile);

  ut_print_message (0, 4, "rst%d.field.core*...\n", Sim.RestartId);
  for (i = 1; i <= Sim.PartQty; i++)
  {
    sprintf (filename, "rst%d.field.core%d", Sim.RestartId, i);
    sprintf (infile, "%s/%s", indir, filename);
    sprintf (outfile, "%s/restart/%s", outdir, filename);

    ut_file_cp (infile, outfile);
  }

  ut_free_1d_char (&dir);
  ut_free_1d_char (&filename);
  ut_free_1d_char (&infile);
  ut_free_1d_char (&outfile);

  return;
}
