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
	int	nc_width;
	int	nc_zero;
	
	nc_width = 0;
	num = va_arg (*pf_arg, int);
	if (num < 0)
		{
			flg->negative = true;
			num = num * -1;
		}
	flg->f_str = ft_itoa (num);
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

static void	ft_print_d_alig (t_flags *flg, va_list *pf_arg, char c)
{
	int	num;
	int	nc_width;
	int	nc_zero;
	
	nc_width = 0;
	num = va_arg (*pf_arg, int);
	if (num < 0)
		{
			flg->negative = true;
			num = num * -1;
		}
	flg->f_str = ft_itoa (num);
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
	//imprimeflags(flg);
	c = ' ';
	if (flg->precision >= flg->width)
	{
		//printf ("HOLA1\n");
		c = '0';
		flg->width = flg->precision;
	}
	if (flg->alig == false)
	{
		//printf ("HOLA2\n");
		ft_print_d_unalig (flg, pf_arg, c);
	}
	else if (flg->alig == true)
	{
		//printf ("HOLA3\n");
		ft_print_d_alig (flg, pf_arg, c);
	}
}
