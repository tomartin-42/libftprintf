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

static void	ft_print_p_unalig (t_flags *flg, va_list *pf_arg, char c)
{
	unsigned long long int	pnt;
	int						nc_str;
	int						nc_width;
	char					*head;

	head = "0x";
	pnt = va_arg (*pf_arg, unsigned long long int);
	ft_dec_to_hex (pnt, "0123456789abcdef", 16, flg);
	nc_str = ft_strlen (flg->f_str);
	if (flg->point == true)
		nc_str = ft_get_nc_str (flg);
	nc_width = flg->width - (nc_str - 1) - 2;
	if (nc_width < 0)
		nc_width = 0;
	if (flg->zero == false)
	{
		ft_make_string_zero (nc_width, flg, c);
		ft_to_write (head, 2, flg);
	}
	else
	{
		ft_to_write (head, 2, flg);
		ft_make_string_zero (nc_width, flg, c);
	}
	ft_to_write (flg->f_str, nc_str, flg);
}

static void	ft_print_p_alig (t_flags *flg, va_list *pf_arg, char c)
{
	unsigned long long int	pnt;
	int						nc_str;
	int						nc_width;
	char					*head;

	head = "0x";
	pnt = va_arg (*pf_arg, unsigned long long int);
	ft_dec_to_hex (pnt, "0123456789abcdef", 16, flg);
	nc_str = ft_strlen (flg->f_str);
	if (flg->point == true)
		nc_str = ft_get_nc_str (flg);
	nc_width = flg->width - (nc_str - 1) - 2;
	if (nc_width < 0)
		nc_width = 0;
	ft_to_write (head, 2, flg);
	ft_to_write (flg->f_str, nc_str, flg);
	ft_make_string_zero (nc_width, flg, c);
}

void	ft_print_p (t_flags *flg, va_list *pf_arg)
{
	char	c;

	c = ' ';
	if (flg->alig == false && flg->zero == true)
		c = '0';
	if (flg->alig == false)
		ft_print_p_unalig (flg, pf_arg, c);
	else if (flg->alig == true)
		ft_print_p_alig (flg, pf_arg, c);
}
