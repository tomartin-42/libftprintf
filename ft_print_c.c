#include "ft_printf.h"

void	ft_print_c (t_flags *flags, va_list *pf_arg)
{
	char	c;
	char	*to_print;
	c = va_arg (*pf_arg, int);
	if (flags->width > 0)
	{
		*to_print =(char *) malloc (sizeof (char) * flags->width);
	}
	else
	{
		*to_print =(char *) malloc (sizeof (char) * 1);
	}
	to_print[flags->width] = '\0';
	if (flags->alig == false)
	{
		ft_make_string_space (to_print);
	}
	if (flags->zero == true && flags->alig == false)			
	{
		ft_make_string_zero (to_print);
	}
	if (flags->alig == false && flags->width > 0)
	{
		to_print[flags->width - 1] = c;
	}
	if (flags->alig == true || flags->width <= 0)
	{
		to_print[0] = c;
	}
	ft_to_write (to_print, flags->width, flags);
	//free (to_print);
}