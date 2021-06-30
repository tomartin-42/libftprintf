#include "ft_printf.h"

void	ft_make_string_zero (int num)
{
	if (num < 0)
		num = num * -1;
	while (num-- > 1)
	{
		write (1, "0", 1);
	}
}

void	ft_make_string_space (int num)
{
	if (num < 0)
		num = num * -1;
	while (num-- > 1)
	{
		write (1, " ", 1);
	}
}

int		ft_to_write (char *to_print, int leng, t_flags *flags)
{
	int	i;
	i = 0;

	while (i <= leng)
	{
		write (1, &to_print[i], 1);
		i++;
	}
	flags->len = flags->len + i;
	return (i);
}