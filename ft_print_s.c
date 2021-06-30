#include "ft_printf.h"

void ft_print_s (t_flags *flg, va_list *pf_arg)
{
	char	*str;

	str = va_arg (*pf_arg, char *);
	printf ("{{{{%s}}}}\n", str);
}