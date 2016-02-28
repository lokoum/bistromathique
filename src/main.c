/*
** main.c for bistromator in /home/theis_p/Piscine_C_bistromathique
** 
** Made by Paul THEIS
** Login   <theis_p@epitech.net>
** 
** Started on  Sat Oct 31 13:36:51 2015 Paul THEIS
** Last update Sun Nov  1 23:03:10 2015 Paul THEIS
*/

#include "main.h"

char		*read_this(unsigned int sizemax)
{
  unsigned int	size;
  char		*str;
  char		buffer[BUFF_SIZE];
  unsigned int	i;
  unsigned int	n;

  if ((str = malloc(sizemax + 1)) == NULL)
    perrator(ERROR_MSG, NULL, 0);
  n = 0;
  while (n < sizemax && (size = read(0, buffer, BUFF_SIZE)) > 0)
    {
      i = 0;
      while (i < size && n < sizemax)
        {
          str[n] = buffer[i];
          ++i;
          ++n;
        }
    }
  str[n] = '\0';
  return (str);
}

int		init(t_info *info, char **av)
{
  info->base = av[1];
  if (my_strlen(av[2]) != 7)
    perrator(SYNTAXE_ERROR_MSG, NULL, my_strlen(av[2])+'0');
  info->struc = av[2];
  info->baselen = my_strlen(info->base);
  if ((info->expr = read_this(my_getnbr_u(av[3]))) == NULL)
    perrator(SYNTAXE_ERROR_MSG, NULL, 0);
  if ((info->size = my_strlen(info->expr)) <= 0)
    return (perrator(SYNTAXE_ERROR_MSG, NULL, 0));
  if (checkator_syntax(info) != 0)
    perrator(SYNTAXE_ERROR_MSG, NULL, 0);
  return (0);
}

int		main(int ac, char **av)
{
  t_info	*info;
  char		*res;

  if (ac != 4)
    perrator(SYNTAXE_ERROR_MSG, NULL, 0);
  if ((info = malloc(sizeof(t_info))) == NULL)
    perrator(ERROR_MSG, NULL, 0);
  if ((info->var = malloc(sizeof(t_var))) == NULL)
    perrator(ERROR_MSG, NULL, 0);
  if ((init(info, av)) != 0)
    return (1);
  res = str_to_list(info, 0, info->size - 1);
  if (res[0] == info->struc[OP_SUB_IDX] && res[1] == info->base[0])
    my_putchar(info->base[0]);
  else
    my_putstr(res);
  free(info->expr);
  free(info->var);
  free(info);
  free(res);
  return (0);
}
