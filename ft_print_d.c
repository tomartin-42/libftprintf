#include "ft_printf.h"

static void	ft_print_d_unalig (t_flags *flg, char c, int num)
{
	int	nc_width;
	int	nc_zero;
	
	nc_width = 0;
	flg->f_str = ft_itoa (num);
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
	if (flg->negative == true)
		ft_make_string_zero (1, flg, '-');
	ft_make_string_zero (nc_zero, flg, '0');
	ft_to_write (flg->f_str, ft_strlen (flg->f_str), flg);
}

static void	ft_print_d_alig (t_flags *flg, char c, int num)
{
	int	nc_width;
	int	nc_zero;
	
	nc_width = 0;
	flg->f_str = ft_itoa (num);
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
	if (flg->negative == true)
		ft_make_string_zero (1, flg, '-');
	ft_make_string_zero (nc_zero, flg, '0');
	ft_to_write (flg->f_str, ft_strlen (flg->f_str), flg);
	ft_make_string_zero (nc_width, flg, c);
}

void	ft_print_d (t_flags *flg, va_list *pf_arg)
{
	char	c;
	int	num;
	
	num = va_arg (*pf_arg, int);
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
		ft_print_d_unalig (flg, c, num);
	else if (flg->alig == true)
		ft_print_d_alig (flg, c, num);
}
