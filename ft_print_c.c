#include "ft_printf.h"

static void ft_print_c_unalig (t_flags *flg, va_list *pf_arg, char c)
{
	char			x;
	unsigned int	add;

	add = 0;
	x = va_arg (*pf_arg, int);
	if (flg->precision >= 1)
		flg->precision = 0;
	add = flg->width;
	if (flg->precision > 0)
	{
		ft_make_string_zero (flg->width - flg->precision + 1, &flg->len, c);
		ft_to_write (&x, flg->precision - 1, flg);
	}
	else
	{
		ft_make_string_zero (add, &flg->len, c);
		ft_to_write (&x, 0, flg);
	}
}

static void ft_print_c_alig (t_flags *flg, va_list *pf_arg, char c)
{
	char			x;
	unsigned int	add;

	add = 0;
	x = va_arg (*pf_arg, int);
	if (flg->precision >= 1)
		flg->precision = 0;
	add = flg->width;
	if (flg->precision > 0)
	{
		ft_to_write (&x, flg->precision - 1, flg);
		ft_make_string_zero (flg->width - flg->precision + 1, &flg->len, c);
	}
	else
	{
		ft_to_write (&x, 0, flg);
		ft_make_string_zero (add, &flg->len, c);
	}
}

void ft_print_c (t_flags *flg, va_list *pf_arg)
{
	char	c;
	
	if (flg->zero == true)
		c = '0';
	else if (flg->zero == false)
		c = ' ';	
	if (flg->alig == false)
		ft_print_c_unalig (flg, pf_arg, c);
	else if (flg->alig == true)
		ft_print_c_alig (flg, pf_arg, c);
}