#include "ft_printf.h"

static void ft_print_c_unalig (t_flags *flg, va_list *pf_arg, char c)
{
	char	chr;
	int	    nc_str;
	int		nc_width;

	chr = va_arg (*pf_arg, int);
	nc_str = 1;
	if (flg->point == true)
	{
		if (flg->precision == 0)
			nc_str = 0;
		else if (flg->precision < 1)
			nc_str = flg->precision;
		else if (flg->precision >= 1)
			nc_str = 1;
	}
	nc_width = flg->width - (nc_str - 1);
	ft_make_string_zero (nc_width, flg, c);
	ft_to_write (&chr, nc_str , flg);
}

static void ft_print_c_alig (t_flags *flg, va_list *pf_arg, char c)
{
	char	chr;
	int	    nc_str;
	int		nc_width;

	chr = va_arg (*pf_arg, int);
	nc_str = 1;
	if (flg->point == true)
	{
		if (flg->precision == 0)
			nc_str = 0;
		else if (flg->precision < 1)
			nc_str = flg->precision;
		else if (flg->precision >= 1)
			nc_str = 1;
	}
	nc_width = flg->width - (nc_str - 1);
	ft_to_write (&chr, nc_str , flg);
	ft_make_string_zero (nc_width, flg, c);
}

void ft_print_c (t_flags *flg, va_list *pf_arg)
{
	char	c;
	
	c = ' ';
	if (flg->alig == false && flg->zero == true)
		c = '0';
	if (flg->alig == false)
		ft_print_c_unalig (flg, pf_arg, c);
	else if (flg->alig == true)
		ft_print_c_alig (flg, pf_arg, c);
}