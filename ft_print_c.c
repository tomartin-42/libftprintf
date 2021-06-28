#include "ft_printf.h"

void	ft_print_c (t_flags *flags, va_list *pf_arg)
{
	char	c;
	char	*to_print;

	//imprimeflags (flags);	
	c = (char) va_arg (*pf_arg, int);
	if (flags->width > 0)
		to_print = malloc (flags->width);
	else
		to_print = malloc (1);
	to_print[flags->width - 1] = '\0';
	printf ("[[%s]]\n", to_print);
	ft_make_string_space (to_print);
	if (flags->alig == true)
	{
		ft_make_string_space (to_print);
	}
	if (flags->zero == true && flags->alig == false)			
	{
		ft_make_string_zero (to_print);
	}
	if (flags->alig == false)
	{
		to_print[0] = c;
	}
	if (flags->alig == true)
	{
		to_print[flags->width] = c;
	}
	ft_to_write (to_print, flags->width, flags);
	free (to_print);
}