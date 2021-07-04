#include "ft_printf.h"

static int	ft_get_nc_str (t_flags *flg)
{
	if (flg->precision == 0)
		return (0);
	else if (flg->precision < ft_strlen (flg->f_str))
		return (flg->precision);
	else if (flg->precision >= ft_strlen (flg->f_str))
		return (ft_strlen (flg->f_str));
	return (0);
}

static void	ft_print_d_unalig (t_flags *flg, va_list *pf_arg, char c)
{
	int	num;
	int	nc_str;
	int	nc_width;
	
	num = va_arg (*pf_arg, int);
	ft_dec_to_hex (num, "0123456789", 10, flg);
	nc_str = ft_strlen (flg->f_str);
	if (flg->point == true)
		nc_str = ft_get_nc_str (flg);
	nc_width = flg->width - (nc_str - 1);
	if (nc_width < 0)
		nc_width = 0;
	ft_make_string_zero (nc_width, &flg->len, c);
	ft_to_write (flg->f_str, nc_str, flg);
}

static void	ft_print_d_alig (t_flags *flg, va_list *pf_arg, char c)
{
	int		num;
	int		nc_str;
	int		nc_width;

	num = va_arg (*pf_arg, int);
	ft_dec_to_hex (num, "0123456789", 10, flg);
	nc_str = ft_strlen (flg->f_str);
	if (flg->point == true)
		nc_str = ft_get_nc_str (flg);
	nc_width = flg->width - (nc_str - 1);
	if (nc_width < 0)
		nc_width = 0;
	ft_to_write (flg->f_str, nc_str, flg);
	ft_make_string_zero (nc_width, &flg->len, c);
}

void	ft_print_d (t_flags *flg, va_list *pf_arg)
{
	char	c;

	c = ' ';
	if (flg->alig == false && flg->zero == true)
		c = '0';
	if (flg->alig == false)
		ft_print_d_unalig (flg, pf_arg, c);
	else if (flg->alig == true)
		ft_print_d_alig (flg, pf_arg, c);
}
