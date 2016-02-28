/*
** my_strcapitalize.c for my_strcapitalize in /home/theis_p/git/Piscine_C_J06
** 
** Made by Paul THEIS
** Login   <theis_p@epitech.net>
** 
** Started on  Mon Oct  5 15:42:21 2015 Paul THEIS
** Last update Mon Oct 12 14:21:36 2015 Paul THEIS
*/

int     get(char *c)
{
  if (c == 0)
    return (1);
  if (*c >= '0' && *c <= '9')
    {
      return (0);
    }
  if (*c >= 'a' && *c <= 'z')
    {
      return (0);
    }
  if (*c >= 'A' && *c <= 'Z')
    {
      return (0);
    }
  else
    return (1);
}

char    *my_strcapitalize(char *str)
{
  char  *tmp;
  char  *c;

  c = str;
  if (*str >= 'a' && *str <= 'z')
    {
      *str = *str - 32;
      str = str + 1;
    }
  while (*str != '\0')
    {
      if (*str >= 'a' && *str <= 'z')
        {
	  tmp = (str - 1);
          if (get(tmp) == 1)
            {
              *str = *str - 32;
            }
        }
      str = str + 1;
    }
  return (c);
}
