/*
** s_opp.h for s_opp in /home/theis_p/Piscine_C_bistromathique
** 
** Made by Paul THEIS
** Login   <theis_p@epitech.net>
** 
** Started on  Mon Oct 26 17:51:15 2015 Paul THEIS
** Last update Sun Nov  1 11:43:04 2015 Paul THEIS
*/

#ifndef S_OPP_H_
# define S_OPP_H_

t_opp gl_opptab[] = {{OP_ADD_IDX, &do_add},
		     {OP_SUB_IDX, &do_sub},
		     {OP_MUL_IDX, &do_mul},
		     {OP_DIV_IDX, &do_div},
		     {OP_MOD_IDX, &do_mod}};

#endif /* !S_OPP_H_ */
