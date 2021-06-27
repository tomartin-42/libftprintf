#include "ft_printf.h"

void	ft_print_c (t_flags *flags, va_list *pf_arg)
{
	char	c;
	char	*to_print;

	c = va_arg (*pf_arg, char);
	if (flags->width > 0)
		to_print = malloc (flags->width);
	else
		to_print = malloc (1);
	if (flags->zero == true && flags->alig == false)
		ft_make_string_zero (to_print, flags->width);
	if (flags->alig == true)
	{
		ft_make_string_space (to_print, flags->width);
		to_print[0] = c;
	}
	else
		to_print[flags->width] = c;
	ft_to_write (to_print, flags->width, flags);
	free (to_print);
}