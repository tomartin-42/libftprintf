#include "ft_printf.h"

static void	ft_print_c_unalig (t_flags *flg, va_list *pf_arg, char c, char num)
{	
	ft_make_string_zero (flg->width - 1, flg, c);
	ft_to_write (&num, 1, flg);
}

static void	ft_print_c_alig (t_flags *flg, va_list *pf_arg, char c, char num)
{
	ft_to_write (&num, 1, flg);
	ft_make_string_zero (flg->width - 1, flg, c);
}

void	ft_print_c (t_flags *flg, va_list *pf_arg)
{
	char	c;
	unsigned int	num;

	num = va_arg (*pf_arg, unsigned int);
	//if (num < 0)
	//{
	//	flg->negative = true;
		//num = num * -1;
	//}
	c = ' ';
	//if (flg->precision >= flg->width)
	//{
		//c = '0';
	//	flg->width = flg->precision;
	//}
	if (flg->alig == false)
		ft_print_c_unalig (flg, pf_arg, c, num);
	else if (flg->alig == true)
		ft_print_c_alig (flg, pf_arg, c, num);
	free (flg->f_str);
}
