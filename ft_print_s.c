#include "ft_printf.h"

static void ft_print_s_unalig (t_flags *flg, va_list *pf_arg, char c)
{
	char	*str;
	int	    nc_str;
	int		nc_width;

	str = va_arg (*pf_arg, char *);
	nc_str = ft_strlen (str);
	if (flg->point == true)
	{
		if (flg->precision == 0)
			nc_str = 0;
		else if (flg->precision < ft_strlen (str))
			nc_str = flg->precision;
		else if (flg->precision >= ft_strlen (str))
			nc_str = ft_strlen (str);
	}
	nc_width = flg->width - (nc_str - 1);
	if (nc_width < 0)
		nc_width = 0;
	ft_make_string_zero (nc_width, flg, c);
	ft_to_write (str, nc_str , flg);
}

static void ft_print_s_alig (t_flags *flg, va_list *pf_arg, char c)
{
	char	*str;
	int	    nc_str;
	int		nc_width;

	str = va_arg (*pf_arg, char *);
	nc_str = ft_strlen (str);
	if (flg->point == true)
	{
		if (flg->precision == 0)
			nc_str = 0;
		else if (flg->precision < ft_strlen (str))
			nc_str = flg->precision;
		else if (flg->precision >= ft_strlen (str))
			nc_str = ft_strlen (str);
	}
	nc_width = flg->width - (nc_str - 1);
	if (nc_width < 0)
		nc_width = 0;
	ft_to_write (str, nc_str , flg);
	ft_make_string_zero (nc_width, flg, c);
}

void ft_print_s (t_flags *flg, va_list *pf_arg)
{
	char	c;
	
	c = ' ';
	if (flg->alig == false && flg->zero == true)
		c = '0';
	if (flg->alig == false)
		ft_print_s_unalig (flg, pf_arg, c);
	else if (flg->alig == true)
		ft_print_s_alig (flg, pf_arg, c);
}