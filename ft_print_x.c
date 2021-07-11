#include "ft_printf.h"

static void	ft_subprint_ext (t_flags *flg, int nc_width)
{
	ft_to_write (flg->f_str, 1, flg);
	ft_make_string_zero (nc_width, flg, '0');
	ft_to_write (flg->f_str + 1, ft_strlen (flg->f_str) - 1, flg);
}

static void	ft_subprint_ua (t_flags *flg, int nc_zero, int nc_width, char c)
{
	if (flg->negative == true)
	{
		if (flg->zero == true && flg->point == false)
			ft_subprint_ext (flg, nc_width);
		else
		{
			ft_make_string_zero (nc_width, flg, c);
			ft_to_write (flg->f_str, 1, flg);
			ft_make_string_zero (nc_zero, flg, '0');
			ft_to_write (flg->f_str + 1, ft_strlen (flg->f_str) - 1, flg);
		}
	}
	else
	{
		if (flg->zero == true && flg->point == false)
			c = '0';
		ft_make_string_zero (nc_width, flg, c);
		ft_make_string_zero (nc_zero, flg, '0');
		ft_to_write (flg->f_str, ft_strlen (flg->f_str), flg);
	}
}

static void	ft_subprint_a (t_flags *flg, int nc_zero, int nc_width, char c)
{
	if (flg->negative == true)
	{	
		ft_to_write (flg->f_str, 1, flg);
		ft_make_string_zero (nc_zero, flg, '0');
		ft_to_write (flg->f_str + 1, ft_strlen (flg->f_str) - 1, flg);
		ft_make_string_zero (nc_width, flg, c);
	}
	else
	{
		ft_make_string_zero (nc_zero, flg, '0');
		ft_to_write (flg->f_str, ft_strlen (flg->f_str), flg);
		ft_make_string_zero (nc_width, flg, c);
	}
}

static void	ft_print_x_alig (t_flags *flg, char c, LL num)
{
	int	nc_width;
	int	nc_zero;

	nc_width = 0;
	if (num == 0 && flg->point == true)
		;
	else
		ft_dec_to_hex (num, "0123456789abcdef", 16, flg);
	nc_zero = flg->precision - ft_strlen (flg->f_str);
	if (flg->negative == true)
	{
		nc_width--;
		nc_zero++;
	}
	if (nc_zero < 0)
		nc_zero = 0;
	nc_width = flg->width - ft_strlen (flg->f_str) - nc_zero;
	if (nc_width < 0)
		nc_width = 0;
	if (flg->alig == false)
		ft_subprint_ua (flg, nc_zero, nc_width, c);
	else if (flg->alig == true)
		ft_subprint_a (flg, nc_zero, nc_width, c);
}

void	ft_print_x (t_flags *flg, va_list *pf_arg)
{
	char			c;
	unsigned int	num;

	c = ' ';
	num = va_arg (*pf_arg, unsigned int);
	ft_print_x_alig (flg, c, num);
	free (flg->f_str);
}
