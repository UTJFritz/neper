/* This file is part of the Neper software package. */
/* Copyright (C) 2003-2021, Romain Quey. */
/* See the COPYING file in the top-level directory. */

#include"nev_show_tesr_.h"

void
nev_show_tesr (char **argv, int *pi, struct PRINT *pPrint)
{
  (*pi)++;
  ut_string_int (argv[(*pi)], &((*pPrint).showtesr));
  if ((*pPrint).showtesr < 0 || (*pPrint).showtesr > 1)
  {
    ut_print_message (2, 0, "-showtesr: bad value.\n");
    abort ();
  }

  return;
}

void
nev_show_tesr_cell (char **argv, int *pi, struct TESR Tesr,
                    struct PRINT *pPrint)
{
  int i, j, status, varqty = 0;
  double res;
  char **vars = NULL;
  double *vals = NULL;
  int **pshowarray = NULL;
  char *entity = NULL;

  (*pi)++;

  if (Tesr.Dim == 2)
  {
    pshowarray = &(*pPrint).showface;
    ut_string_string ("face", &entity);
  }
  else if (Tesr.Dim == 3)
  {
    pshowarray = &(*pPrint).showpoly;
    ut_string_string ("cell", &entity);
  }

  (*pshowarray) = ut_realloc_1d_int (*pshowarray, Tesr.CellQty + 1);
  ut_array_1d_int_zero ((*pshowarray) + 1, Tesr.CellQty);

  // checking for a general expression
  status = nev_show_genexpr (argv[(*pi)], Tesr.CellId, *pshowarray, Tesr.CellQty);

  if (status != 0)
  {
    ut_math_vars (argv[(*pi)], &vars, &varqty);
    vals = ut_alloc_1d (varqty);

    for (i = 1; i <= Tesr.CellQty; i++)
    {
      for (j = 0; j < varqty; j++)
      {
        status = neut_tesr_var_val_one (Tesr, entity, i, vars[j], vals + j, NULL);

        if (status)
          ut_print_exprbug (vars[j]);
      }

      status = ut_math_eval (argv[(*pi)], varqty, vars, vals, &res);
      if (!status)
        (*pshowarray)[i] = res;
      else
        ut_print_exprbug (argv[(*pi)]);
    }
  }

  (*pshowarray)[0] = ut_array_1d_int_sum ((*pshowarray) + 1, Tesr.CellQty);

  ut_free_2d_char (&vars, varqty);
  ut_free_1d (&vals);
  ut_free_1d_char (&entity);

  return;
}

void
nev_show_tesr_edge (char **argv, int *pi, struct PRINT *pPrint)
{
  (*pi)++;

  ut_string_string (argv[(*pi)], &(*pPrint).showedgestring);

  return;
}

void
nev_show_tesr_vox (char *option, char **argv, int *pi, struct TESR Tesr,
                   struct PRINT *pPrint)
{
  int i, j, k, varqty, status;
  char *expr = NULL;
  char **vars = NULL;

  (*pi)++;

  ut_string_string (argv[(*pi)], &expr);
  if (!strcmp (expr, "all"))
    ut_string_string ("1", &expr);
  else if (!strcmp (expr, "none"))
    ut_string_string ("0", &expr);

  if (!strcmp (option, "-showvox"))
    ut_string_string (expr, &(*pPrint).showvoxstring);
  else if (!strcmp (option, "-showvoidvox"))
    ut_string_string (expr, &(*pPrint).showvoidvoxstring);
  else
    abort ();

  if (!(*pPrint).showvox)
    (*pPrint).showvox =
      ut_alloc_3d_int (Tesr.size[0] + 1, Tesr.size[1] + 1, Tesr.size[2] + 1);

  ut_math_vars (argv[(*pi)], &vars, &varqty);

  for (k = 1; k <= Tesr.size[2]; k++)
    for (j = 1; j <= Tesr.size[1]; j++)
      for (i = 1; i <= Tesr.size[0]; i++)
        if ((!strcmp (option, "-showvox") && Tesr.VoxCell[i][j][k])
         || (!strcmp (option, "-showvoidvox") && !Tesr.VoxCell[i][j][k]))
        {
          int l, pos;
          double res;
          double *vals = ut_alloc_1d (varqty);

          neut_tesr_pos3_vox (Tesr, i, j, k, &pos);
          for (l = 0; l < varqty; l++)
          {
            status = neut_tesr_var_val_one (Tesr, "vox", pos, vars[l], vals +
                                            l, NULL);
            if (status)
              ut_print_exprbug (vars[j]);
          }

          if (!ut_math_eval (expr, varqty, vars, vals, &res))
            (*pPrint).showvox[i][j][k] = res;
          else
            ut_print_exprbug (expr);

          ut_free_1d (&vals);
        }

  ut_free_2d_char (&vars, varqty);
  ut_free_1d_char (&expr);

  return;
}
