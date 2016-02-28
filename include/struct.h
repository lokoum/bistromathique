/*
** struct.h for bistromatique in /home/theis_p/Piscine_C_bistromathique
** 
** Made by Paul THEIS
** Login   <theis_p@epitech.net>
** 
** Started on  Sun Nov  1 15:12:48 2015 Paul THEIS
** Last update Sun Nov  1 23:10:43 2015 Paul THEIS
*/

#ifndef STRUCT_H_
# define STRUCT_H_

typedef struct		s_nbr
{
  char			*nbr;
  int			len;
  char			is_neg;
}			t_nbr;

typedef struct		s_var
{
  int			a;
  int			b;
  int			c;
  int			d;
  int			e;
}			t_var;

typedef struct		s_info
{
  char			*expr;
  char			*base;
  char			*struc;
  int			baselen;
  int			size;
  t_var			*var;
}			t_info;

typedef struct		s_node
{
  char			*str;
  int		      i;
  struct s_node		*next;
  struct s_node		*prev;
}			t_node;

typedef struct		s_stack
{
  int			i;
  int			start;
  int			end;
  int			side;
  struct s_stack	*next;
  struct s_stack	*prev;
}			t_stack;

#endif /* !STRUCT_H_ */
