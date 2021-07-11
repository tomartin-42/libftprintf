#include "ft_printf.h"

static void	ft_print_c_unalig (t_flags *flg, char c, char num)
{	
	char	*p;

	p = &num;
	ft_make_string_zero (flg->width - 1, flg, c);
	ft_to_write (p, 1, flg);
}

static void	ft_print_c_alig (t_flags *flg, char c, char num)
{
	char	*p;

	p = &num;
	ft_to_write (p, 1, flg);
	ft_make_string_zero (flg->width - 1, flg, c);
}

void	ft_print_c (t_flags *flg, va_list *pf_arg)
{
	char			c;
	unsigned int	num;

	num = va_arg (*pf_arg, unsigned int);
	c = ' ';
	if (flg->alig == false)
		ft_print_c_unalig (flg, c, num);
	else if (flg->alig == true)
		ft_print_c_alig (flg, c, num);
}
