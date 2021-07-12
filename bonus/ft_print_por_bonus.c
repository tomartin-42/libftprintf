#include "ft_printf_bonus.h"

static void	ft_print_por_unalig (t_flags *flg, char c, char num)
{	
	char	*p;

	p = &num;
	ft_make_string_zero (flg->width - 1, flg, c);
	ft_to_write (p, 1, flg);
}

static void	ft_print_por_alig (t_flags *flg, char c, char num)
{
	char	*p;

	p = &num;
	c = ' ';
	ft_to_write (p, 1, flg);
	ft_make_string_zero (flg->width - 1, flg, c);
}

void	ft_print_por (t_flags *flg)
{
	char			c;
	unsigned int	num;

	num = '%';
	c = ' ';
	if (flg->zero == true)
		c = '0';
	if (flg->alig == false)
		ft_print_por_unalig (flg, c, num);
	else if (flg->alig == true)
		ft_print_por_alig (flg, c, num);
}
