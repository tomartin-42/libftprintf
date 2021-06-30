#include "ft_printf.h"

void ft_print_s (t_flags *flg, va_list *pf_arg)
{
	char			*str;
	unsigned int	add;

	str = va_arg (*pf_arg, char *);

	add = 0;
		add = flg->width - (ft_strlen (str) - 1);
		ft_make_string_space (add, flg->len);
		ft_to_write (str, (ft_strlen (str)-1) - (flg->precision), flg);
	//imprimeflags (flg);
}