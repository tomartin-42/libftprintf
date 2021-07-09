#include "ft_printf.h"

static void	ft_subprint_ua (t_flags *flg, int nc_zero, int nc_width, char c)
{
	ft_make_string_zero (nc_width, flg, c);
	ft_to_write (flg->f_str, nc_zero, flg);
}

static void	ft_subprint_a (t_flags *flg, int nc_zero, int nc_width, char c)
{
	ft_to_write (flg->f_str, nc_zero, flg);
	ft_make_string_zero (nc_width, flg, c);
}

static void	ft_print_s_unalig (t_flags *flg, char c)
{
	int	nc_zero;
	int	nc_width;

	nc_width = 0;
	if (flg->precision > ft_strlen (flg->f_str) || flg->point == false)
		nc_zero = ft_strlen (flg->f_str);
	else
		nc_zero = flg->precision;
	if (nc_zero < 0)
		nc_zero = 0;
	nc_width = flg->width - nc_zero;
	if (nc_width < 0)
		nc_width = 0;
	ft_subprint_ua (flg, nc_zero, nc_width, c);
}

static void	ft_print_s_alig (t_flags *flg, char c)
{
	int	nc_zero;
	int	nc_width;

	nc_width = 0;
	if (flg->precision > ft_strlen (flg->f_str) || flg->point == false)
		nc_zero = ft_strlen (flg->f_str);
	else
		nc_zero = flg->precision;
	if (nc_zero < 0)
		nc_zero = 0;
	nc_width = flg->width - nc_zero;
	if (nc_width < 0)
		nc_width = 0;
	ft_subprint_a (flg, nc_zero, nc_width, c);
}

void	ft_print_s (t_flags *flg, va_list *pf_arg)
{
	char	c;

	c = ' ';
	flg->f_str = va_arg (*pf_arg, char *);
	if (flg->f_str == NULL)
		flg->f_str = ft_strdup ("(null)");
	if (flg->alig == false)
		ft_print_s_unalig (flg, c);
	else if (flg->alig == true)
		ft_print_s_alig (flg, c);
}
