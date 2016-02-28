/*
** debugator.h for debugator in /home/theis_p/git/Piscine_C_infinadd
** 
** Made by Paul THEIS
** Login   <theis_p@epitech.net>
** 
** Started on  Tue Oct 20 21:36:26 2015 Paul THEIS
** Last update Thu Oct 29 17:50:49 2015 Paul THEIS
*/

#ifndef DEBUGATOR_H_
# define DEBUGATOR_H_

void	debug_putstr_ascii(char *name, char *str, int len);
void	my_putstr_ascii(char *str, int len);
void	debug_putstr(char *name, char *str);
void	debug_put_nbr(char *name, int nbr);
void	debug_info(t_info *info);
void	debug_nbr(t_nbr *nbr);
void	debug_node(t_node *node);
void	debug_stack(t_stack *stack);

#endif /* !DEBUGATOR_H_ */
