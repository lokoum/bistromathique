/*
** my_strncpy.c for my_strncpy in /home/theis_p/git/Piscine_C_J06
** 
** Made by Paul THEIS
** Login   <theis_p@epitech.net>
** 
** Started on  Mon Oct  5 10:08:42 2015 Paul THEIS
** Last update Thu Oct 22 22:14:35 2015 Paul THEIS
*/

char    *my_strncpy(char *dest, char *src, int n)
{
  int	count;

  count = 0;
  while (src[count] != '\0' && count < n)
    {
      dest[count] = src[count];
      count++;
    }
  dest[count] = '\0';
  return (dest);
}
