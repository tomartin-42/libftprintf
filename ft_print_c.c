#include "ft_printf.h"

void	ft_print_c (t_flags *flags, va_list *pf_arg)
{
	char	c;
	imprimeflags (flags);
	c = va_arg (*pf_arg, int);
	if (flags->width < 1)
	{
		write (1, &c, 1);
	}
	else if (flags->alig == false && flags->width > 0 && flags->zero == false)
	{
		write (1, &c, 1);
		ft_make_string_space (flags->width);
	}
	else if (flags->zero == true && flags->alig == false && flags->width > 0)			
	{
		ft_make_string_zero (flags->width);
		write (1, &c, 1);
	}
	else if (flags->alig == true && flags->width > 0)
	{
		write (1, &c, 1);
		ft_make_string_space (flags->width);
	}
	else if (flags->alig == true || flags->width <= 0)
	{
	}
}