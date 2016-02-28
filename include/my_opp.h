/*
** my_opp.h for opp in /home/theis_p/Piscine_C_bistromathique
** 
** Made by Paul THEIS
** Login   <theis_p@epitech.net>
** 
** Started on  Mon Oct 26 17:17:27 2015 Paul THEIS
** Last update Sun Nov  1 21:36:04 2015 troncy_l
*/

#ifndef MY_OPP_H_
# define MY_OPP_H_

typedef struct	s_opp
{
  int		opp;
  t_nbr		*(*do_this)(t_nbr *nbr1, t_nbr *nb2, t_info *info);
}		t_opp;

extern t_opp	gl_opptab[];

#endif /* !MY_OPP_H_ */
