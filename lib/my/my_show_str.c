/*
** my_show_str.c for my_show_str in /home/theis_p/git/Piscine_C_J07
** 
** Made by Paul THEIS
** Login   <theis_p@epitech.net>
** 
** Started on  Tue Oct  6 17:26:27 2015 Paul THEIS
** Last update Tue Oct  6 18:57:32 2015 Paul THEIS
*/

int     my_showstr(char *str)
{
  int   i;

  i = 0;
  while (str[i])
    {
      if (str[i] <= 31 || str[i] >= 128)
	{
        my_putchar('\\');
	if (str[i] < 15)
	  my_putchar('0');
	my_putnbr_base(str[i], "0123456789abcdef");
        }
      else
	my_putchar(str[i]);
      i++;
    }
}

int     my_putnbr_nbase(int nbr, int nbase, char *base)
{
  if (nbr / nbase != 0)
    {
      my_putnbr_nbase(nbr / nbase, nbase, base);
    }
  my_putchar(base[nbr % nbase]);
}

int     my_putnbr_base(int nbr, char *base)
{
  int   nbase;

  nbase = my_strlen(base);
  if (nbr < 0)
    {
      my_putchar('-');
      nbr = -nbr;
    }
  my_putnbr_nbase(nbr, nbase, base);
}

