#include "ft_printf.h"

static void ft_procesin_point (t_flags *flg, int nc_str, int nc_width)
{
	char	*substr;
	int		i;

	i = 0;
	if (flg->width < flg->precision)
		i = flg->precision;
	else
		i = flg->width;
	substr = malloc (i);
	i = 0;
	while (i++ < flg->width)
		substr = ft_stradd_char (substr, ' ');
	substr[i] = '\0'; 
	i = flg->width - flg->precision;
	if (i <= 0)
		i = flg->precision;
	while (i++ < flg->precision)
	{
		substr[i] = '0';
		printf ("[[%s]]\n", substr);
	}
}

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
	int	nc_zero;
	
	nc_width = 0;
	num = va_arg (*pf_arg, int);
	if (num < 0)
		{
			flg->negative = true;
			num = num * -1;
		}
	flg->f_str = ft_itoa (num);
	if (flg->negative == true)
		nc_width--;
	nc_zero = flg->precision - ft_strlen (flg->f_str) + 1;
	nc_width = flg->width - nc_zero - ft_strlen (flg->f_str);
	ft_make_string_zero (nc_width, &flg->len, c);
	if (flg->negative == true)
		ft_make_string_zero (2, flg->len, '-');
	ft_make_string_zero (nc_zero, flg->len, '0');
	ft_to_write (flg->f_str, ft_strlen (flg->f_str), flg);
	// if (flg->precision > ft_strlen (flg->f_str))
	// {
	// 	c = '0';
	// 	ft_make_string_zero (flg->precision - nc_str + 1, &flg->len, c);
	// 	c = ' ';
	// }
}

static void	ft_print_d_alig (t_flags *flg, va_list *pf_arg, char c)
{
	int		num;
	int		nc_str;
	int		nc_width;

	num = va_arg (*pf_arg, int);
	flg->f_str = ft_itoa (num);
	nc_str = ft_strlen (flg->f_str);
	//if (flg->point == true)
	//	nc_str = ft_get_nc_str (flg);
	nc_width = flg->width - (nc_str - 1);
	if (nc_width < 0)
		nc_width = 0;
	//ft_procesin_point (flg, nc_str, nc_width);
	ft_to_write (flg->f_str, nc_str, flg);
	ft_make_string_zero (nc_width, &flg->len, c);
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
