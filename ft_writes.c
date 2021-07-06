#include "ft_printf.h"

void	ft_make_string_zero (int num, t_flags *flg, char c)
{
	if (num < 0)
		num = num * -1;
	while (num-- > 0)
	{
		write (1, &c, 1);
		flg->len += 1;
	}
}

void		ft_to_write (char *to_print, int leng, t_flags *flags)
{
	int	i;
	i = 0;

	if (leng < 0)
		leng = leng * -1;
	while (i < leng)
	{
		write (1, &to_print[i], 1);
		i++;
		flags->len += 1;	
	}
}