/*
** checkator.h for checkator in /home/troncy_l/prog/rendu/bistromator
** 
** Made by troncy_l
** Login   <troncy_l@epitech.net>
** 
** Started on  Thu Oct 29 14:32:24 2015 troncy_l
** Last update Sun Nov  1 12:02:47 2015 Paul THEIS
*/

#ifndef CHECKATOR_H_
# define CHECKATOR_H_

int	check_nbr(t_info *info, int i);
int	check_opp(t_info *info, int i);
int	check_opp2(t_info *info, int i);
int	check_bracket(t_info *info, int i);
int	check_strucbase(t_info *info, int i);
int	countbracket(int bracket, t_info *info, int i);
int	next_check(t_info *info, int i);
int	checkator_syntax(t_info *info);

#endif /* !CHECKATOR_H_ */
