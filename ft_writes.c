#include "ft_printf.h"

void	ft_make_string_zero (char *string, int leng)
{
	while (leng != 0)
	{
		string[leng] = '0';
		leng--;
	}
}

void	ft_make_string_space (char *string, int leng)
{
	while (leng != 0)
	{
		string[leng] = ' ';
		leng--;
	}
}

int		ft_to_write (char *to_print, int leng, t_flags *flags)
{
	int	i;
	i = 0;
	while (i <= leng)
	{
		write (1, to_print, 1);
		i++;
	}
	flags->len = flags->len + i;
	return (i);
}