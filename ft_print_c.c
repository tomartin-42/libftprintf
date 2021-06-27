#include "ft_printf.h"

void	ft_print_c (t_flags *flags, va_list *pf_arg)
{
	char	c;
	char	*to_print;

	c = va_arg (*pf_arg, char);
	if (flags->width != 0 && flags->zero == false && flags->alig == false)
		to_print = malloc (flags->width);

}