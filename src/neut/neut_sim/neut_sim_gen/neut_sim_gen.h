/* This file is part of the Neper software package. */
/* Copyright (C) 2003-2013, Romain Quey. */
/* See the COPYING file in the top-level directory. */

#ifndef NEUT_SIM_GEN_H
#define NEUT_SIM_GEN_H

#include"neut.h"

/// tells if a simulation is void
extern int neut_sim_isvoid (struct SIM Sim);

/// read a simulation report file
extern void neut_sim_fscanf (char *dir, struct SIM *pSim, char *mode);

/// writes a simulation report file
extern void neut_sim_fprintf (char *dir, struct SIM Sim, char *mode);

/// returns the actual simulation file of a file
extern int neut_sim_res_file (struct SIM Sim, char *entity, char *file, char *simfile);

/// returns the actual simulation file of a file
extern void neut_sim_res_fepxfile (struct SIM Sim, char *res, int core, char *filename);

/// returns the result of a filename
extern void neut_sim_file_res (char *file, char *res);

/// returns the type of simulation, fepx, merge or sim
extern int neut_sim_name_type (char *name, char **ptype, char **pname, int *prestart);

/// tells if a result exist, for a given entity
/// \return 0 if does not exist, 1 if exists, 2 if exists as a subresult, 3 if exists as an element result (for an elset)
extern int neut_sim_res_exist (struct SIM Sim, char *entity, char *res, char **pres, int *pcol);

/// is entity node?
extern int neut_sim_entityisnode (char *entity);

/// is entity elt?
extern int neut_sim_entityiselt (char *entity);

/// is entity elset?
extern int neut_sim_entityiselset (char *entity);

/// is entity mesh?
extern int neut_sim_entityismesh (char *entity);

/// returns the results/* directory of an entity
extern void neut_sim_entity_dir (char *entity, char **pdir);

extern void neut_sim_entity_res (struct SIM Sim, char *entity, char ***pres, int *presqty);

/// returns the type of a result: int, real, ori, vector, tensor
extern int neut_sim_knownres_type (char *res, char **ptype, int *pcolqty);

/// returns the type of a result: int, real, ori, vector, tensor
extern int neut_sim_res_type (struct SIM Sim, char *entity, char *res, char **ptype, int *pcolqty);

/// returns the result name and file column from a result: strain11 -> strain and 1
extern int neut_sim_res_rescol (struct SIM Sim, char *entity, char *res, char **pres, int *pcol);

/// tells if a result exist in a SIM
extern int neut_sim_testres (struct SIM Sim, char *entity, char *res);

/// writes at terminal about the simulation
extern void neut_sim_verbose (struct SIM Sim);

// get the input file names
extern void neut_sim_input_files (struct SIM Sim, char ***pfullfiles, char ***pfiles, int *pfileqty);

#endif /* NEUT_SIM_GEN_H */
