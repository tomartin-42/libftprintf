#include "ft_printf.h"

static void	ft_subprint_ua (t_flags *flg, int nc_zero, int nc_width, char c)
{
	if (flg->zero == true)
	{	if (flg->width > 0 && flg->point == false)
			ft_make_string_zero (nc_width, flg, '0');
		else
			ft_make_string_zero (nc_width, flg, c);
		ft_make_string_zero (nc_zero, flg, '0');
		ft_to_write (flg->f_str, ft_strlen (flg->f_str), flg);
	}
	else
	{
		printf("[[[%d - %d]]]\n", nc_width, nc_zero);
		ft_make_string_zero (nc_width, flg, c);
		if (flg->point == true && flg->precision < ft_strlen (flg->f_str))
		{
			ft_to_write (flg->f_str, nc_zero, flg);
		}
		else
		{
			ft_to_write (flg->f_str, ft_strlen (flg->f_str), flg);
		}
	}
}

static void ft_print_s_unalig (t_flags *flg, va_list *pf_arg, char c)
{
	int	    nc_zero;
	int		nc_width;

	nc_width = 0;
	if (flg->precision < ft_strlen (flg->f_str))
		nc_zero = flg->precision;
	else
		nc_zero = ft_strlen (flg->f_str);
	if (nc_zero < 0)
		nc_zero = 0;
	nc_width = flg->width - ft_strlen (flg->f_str);
	if (nc_width < 0)
		nc_width = 0;
	ft_subprint_ua (flg, nc_zero, nc_width, c);
}

static void ft_print_s_alig (t_flags *flg, va_list *pf_arg, char c)
{
	int	    nc_str;
	int		nc_width;

	if (flg->point == true)
	{
		if (flg->precision == 0)
			nc_str = 0;
		else if (flg->precision < ft_strlen (flg->f_str))
			nc_str = flg->precision;
		else if (flg->precision >= ft_strlen (flg->f_str))
			nc_str = ft_strlen (flg->f_str);
	}
	nc_width = flg->width - (nc_str - 1);
	if (nc_width < 0)
		nc_width = 0;
	ft_to_write (flg->f_str, nc_str , flg);
	ft_make_string_zero (nc_width, flg, c);
}

void ft_print_s (t_flags *flg, va_list *pf_arg)
{
	char	c;

	c = ' ';
	flg->f_str = va_arg (*pf_arg, char *);
	//if (str < 0)
	c = ' ';
	if (flg->alig == false && flg->zero == true)
		c = '0';
	if (flg->alig == false)
		ft_print_s_unalig (flg, pf_arg, c);
	else if (flg->alig == true)
		ft_print_s_alig (flg, pf_arg, c);
}