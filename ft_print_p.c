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
	unsigned long long int	num;
	int						nc_width;
	int						nc_zero;
	
	nc_width = 0;
	num = va_arg (*pf_arg, unsigned long long int);
	if (num < 0)
	{
		flg->negative = true;
		num = num * -1;
	}
	ft_dec_to_hex (num, "0123456789abcdef", 16, flg);
	nc_zero = flg->precision - ft_strlen (flg->f_str);
	if (nc_zero < 0)
		nc_zero = 0;
	nc_width = flg->width - (nc_zero) - ft_strlen (flg->f_str) - 2;
	if (nc_width < 0)
		nc_width = 0;
	if (flg->negative == true && nc_width > 0)
		nc_width--;
	ft_make_string_zero (nc_width, flg, c);
	//if (flg->negative == true)
	//	ft_make_string_zero (1, flg, '-');
	ft_to_write ("0x", 2, flg);
	ft_make_string_zero (nc_zero, flg, '0');
	ft_to_write (flg->f_str, ft_strlen (flg->f_str), flg);
}

static void	ft_print_p_alig (t_flags *flg, va_list *pf_arg, char c)
{
	unsigned long long int	num;
	int						nc_width;
	int						nc_zero;
	
	nc_width = 0;
	num = va_arg (*pf_arg, unsigned long long int);
	if (num < 0)
	{
		flg->negative = true;
		num = num * -1;
	}
	ft_dec_to_hex (num, "0123456789abcdef", 16, flg);
	nc_zero = flg->precision - ft_strlen (flg->f_str);
	if (nc_zero < 0)
		nc_zero = 0;
	nc_width = flg->width - (nc_zero) - ft_strlen (flg->f_str) - 2;
	if (nc_width < 0)
		nc_width = 0;
	if (flg->negative == true && nc_width > 0)
		nc_width--;
	//if (flg->negative == true)
	//	ft_make_string_zero (1, flg, '-');
	ft_to_write ("0x", 2, flg);	
	ft_make_string_zero (nc_zero, flg, '0');
	ft_to_write (flg->f_str, ft_strlen (flg->f_str), flg);
	ft_make_string_zero (nc_width, flg, c);
}

void	ft_print_p (t_flags *flg, va_list *pf_arg)
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
		ft_print_p_unalig (flg, pf_arg, c);
	}
	else if (flg->alig == true)
	{
		//printf ("HOLA3\n");
		ft_print_p_alig (flg, pf_arg, c);
	}
}


/*
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
*/