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

static void	ft_print_xu_unalig (t_flags *flg, char c, LL num)
{
	int						nc_width;
	int						nc_zero;
	
	nc_width = 0;
	ft_dec_to_hex (num, "0123456789ABCDEF", 16, flg);
	if (flg->point == true && flg->precision == 0 && num == 0)
		flg->f_str = ft_strdup ("");
	nc_zero = flg->precision - ft_strlen (flg->f_str);
	if (nc_zero < 0)
		nc_zero = 0;
	nc_width = flg->width - (nc_zero) - ft_strlen (flg->f_str);
	if (nc_width < 0)
		nc_width = 0;
	if (flg->negative == true && nc_width > 0)
		nc_width--;
	ft_make_string_zero (nc_width, flg, c);
	//ft_to_write ("0x", 2, flg);
	ft_make_string_zero (nc_zero, flg, '0');
	ft_to_write (flg->f_str, ft_strlen (flg->f_str), flg);
}

static void	ft_print_xu_alig (t_flags *flg, char c, LL num)
{
	int						nc_width;
	int						nc_zero;
	
	nc_width = 0;
	ft_dec_to_hex (num, "0123456789ABCDEF", 16, flg);
	if (flg->point == true && flg->precision == 0 && num == 0)
		flg->f_str = ft_strdup ("");
	nc_zero = flg->precision - ft_strlen (flg->f_str);
	if (nc_zero < 0)
		nc_zero = 0;
	nc_width = flg->width - (nc_zero) - ft_strlen (flg->f_str);
	if (nc_width < 0)
		nc_width = 0;
	if (flg->negative == true && nc_width > 0)
		nc_width--;
	//ft_to_write ("0x", 2, flg);	
	ft_make_string_zero (nc_zero, flg, '0');
	if (flg->point != true && flg->precision != 0 && num != 0)
		ft_to_write (flg->f_str, ft_strlen (flg->f_str), flg);
	ft_make_string_zero (nc_width, flg, c);
}

void	ft_print_xu (t_flags *flg, va_list *pf_arg)
{
	char	c;
	unsigned long int	num;

	num = va_arg (*pf_arg, unsigned long int);
	if (num < 0)
	{
		flg->negative = true;
		num = num * -1;
	}
	c = ' ';
	if (flg->precision >= flg->width)
	{
		c = '0';
		flg->width = flg->precision;
	}
	if (flg->alig == false)
		ft_print_xu_unalig (flg, c, num);
	else if (flg->alig == true)
		ft_print_xu_alig (flg, c, num);
	free (flg->f_str);
}