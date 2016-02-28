/*
** my_putchar.c for my_putchar in /home/theis_p/git/Piscine_C_J03
** 
** Made by Paul THEIS
** Login   <theis_p@epitech.net>
** 
** Started on  Thu Oct  1 21:49:08 2015 Paul THEIS
** Last update Thu Oct  1 21:51:39 2015 Paul THEIS
*/

int	my_putchar(char c)
{
  write(1, &c, 1);
  return (0);
}
