#include "ft_printf.h"

static void	ft_print_por_unalig (t_flags *flg, char c, char num)
{	
	ft_make_string_zero (flg->width - 1, flg, c);
	ft_to_write (&num, 1, flg);
}

static void	ft_print_por_alig (t_flags *flg, char c, char num)
{
	c = ' ';
	ft_to_write (&num, 1, flg);
	ft_make_string_zero (flg->width - 1, flg, c);
}

void	ft_print_por (t_flags *flg)
{
	char	c;
	unsigned int	num;

	num = '%';
	c = ' ';
	if (flg->zero == true)
		c = '0';
	if (flg->alig == false)
		ft_print_por_unalig (flg, c, num);
	else if (flg->alig == true)
		ft_print_por_alig (flg, c, num);
	free (flg->f_str);
}