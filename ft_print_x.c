#include "ft_printf.h"

static void	ft_print_x_unalig (t_flags *flg, char c, LL num)
{
	int						nc_width;
	int						nc_zero;
	
	nc_width = 0;
	ft_dec_to_hex (num, "0123456789abcdef", 16, flg);
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

static void	ft_print_x_alig (t_flags *flg, char c, LL num)
{
	int						nc_width;
	int						nc_zero;
	
	nc_width = 0;
	ft_dec_to_hex (num, "0123456789abcdef", 16, flg);
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

void	ft_print_x (t_flags *flg, va_list *pf_arg)
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
		ft_print_x_unalig (flg, c, num);
	else if (flg->alig == true)
		ft_print_x_alig (flg, c, num);
	free (flg->f_str);
}