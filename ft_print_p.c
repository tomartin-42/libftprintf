#include "ft_printf.h"

static void	ft_subprint_ua (t_flags *flg, int nc_zero, int nc_width, char c)
{
	if (flg->zero == true)
	{	
		if (flg->width > 0 && flg->point == false)
			ft_make_string_zero (nc_width, flg, c);
		else
			ft_make_string_zero (nc_width, flg, c);
		ft_to_write ("0x", 2, flg);
		ft_make_string_zero (nc_zero, flg, '0');
		ft_to_write (flg->f_str, ft_strlen (flg->f_str), flg);
	}
	else
	{
		ft_make_string_zero (nc_width, flg, c);
		ft_to_write ("0x", 2, flg);
		ft_make_string_zero (nc_zero, flg, '0');
		ft_to_write (flg->f_str, ft_strlen (flg->f_str), flg);
	}
}

static void	ft_subprint_a (t_flags *flg, int nc_zero, int nc_width, char c)
{
	if (flg->zero == true)
	{	
		ft_to_write ("0x", 2, flg);
		ft_make_string_zero (nc_zero, flg, '0');
		ft_to_write (flg->f_str, ft_strlen (flg->f_str), flg);
		if (flg->width > 0 && flg->point == true)
			nc_width = 0;
		ft_make_string_zero (nc_width, flg, c);
	}
	else
	{
		ft_to_write ("0x", 2, flg);
		ft_make_string_zero (nc_zero, flg, '0');
		ft_to_write (flg->f_str, ft_strlen (flg->f_str), flg);
		if (flg->width > 0 && flg->point == true)
			nc_width = 0;
		ft_make_string_zero (nc_width, flg, c);
	}
}

static void	ft_print_p_unalig (t_flags *flg, char c, LL num)
{
	int		nc_width;
	int		nc_zero;

	nc_width = 0;
		ft_dec_to_hex (num, "0123456789abcdef", 16, flg);
	nc_zero = flg->precision - ft_strlen (flg->f_str);
	if (nc_zero < 0)
		nc_zero = 0;
	nc_width = flg->width - ft_strlen (flg->f_str) - nc_zero - 2;
	if (nc_width < 0)
		nc_width = 0;
	ft_subprint_ua (flg, nc_zero, nc_width, c);
}

static void	ft_print_p_alig (t_flags *flg, char c, LL num)
{
	int						nc_width;
	int						nc_zero;

	nc_width = 0;
		ft_dec_to_hex (num, "0123456789abcdef", 16, flg);
	nc_zero = flg->precision - ft_strlen (flg->f_str);
	if (nc_zero < 0)
		nc_zero = 0;
	nc_width = flg->width - ft_strlen (flg->f_str) - 2;
	if (nc_width < 0)
		nc_width = 0;
	ft_subprint_a (flg, nc_zero, nc_width, c);
}

void	ft_print_p (t_flags *flg, va_list *pf_arg)
{
	char	c;
	LL		num;

	c = ' ';
	if (flg->zero == true)
		c = '0';
	if (flg->f_str == NULL)
		flg->f_str = ft_strdup ("");
	num = va_arg (*pf_arg, LL);
	if (flg->alig == false)
		ft_print_p_unalig (flg, c, num);
	else if (flg->alig == true)
		ft_print_p_alig (flg, c, num);
	free (flg->f_str);
}
