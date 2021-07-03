#include "ft_printf.h"

static void ft_print_s_unalig (t_flags *flg, va_list *pf_arg, char c)
{
	char	*str;
	int	    add;

	add = 0;
	str = va_arg (*pf_arg, char *);
    add = flg->width - (ft_strlen (str) - 1);
	if (flg->precision == 0)
		str = ft_strdup ("");
    if (add < 0)
        add = 0;
    if (flg->alig == false)
    {
		ft_make_string_zero (add, &flg->len, c);
		ft_to_write (str, ft_strlen (str) - 1 , flg);
    }
    else
    {
        ft_make_string_zero (add, &flg->len, c);
        ft_to_write (str, ft_strlen (str) - 1 , flg);
    }
}

static void ft_print_s_alig (t_flags *flg, va_list *pf_arg, char c)
{
	char	*str;
	int	    add;

	add = 0;
	str = va_arg (*pf_arg, char *);
    add = flg->width - (ft_strlen (str) - 1);
	if (flg->precision == 0)
		str = ft_strdup ("");
    if (add < 0)
        add = 0;
    if (flg->alig == true)
    {
		ft_to_write (str, ft_strlen (str) - 1 , flg);
		ft_make_string_zero (add, &flg->len, c);
    }
    else
    {
        ft_to_write (str, ft_strlen (str) - 1 , flg);
        ft_make_string_zero (add, &flg->len, c);
    }
}

void ft_print_s (t_flags *flg, va_list *pf_arg)
{
	char	c;

	c = ' ';
	if (flg->alig == false && flg->zero == true)
		c = '0';
	if (flg->alig == false)
		ft_print_s_unalig (flg, pf_arg, c);
	else if (flg->alig == true)
		ft_print_s_alig (flg, pf_arg, c);
}