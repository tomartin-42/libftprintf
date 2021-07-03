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
		//printf ("[[[%d - %d - %d]]]\n", add, flg->width, flg->precision);

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
	/*char			*str;
	unsigned int	add;

	add = 0;
	str = va_arg (*pf_arg, char *);
	if (flg->precision >= ft_strlen (str))
		flg->precision = 0;
	add = flg->width - (ft_strlen (str) - 1);
	if (flg->precision > 0)
	{
		ft_to_write (str, flg->precision - 1, flg);
		ft_make_string_zero (flg->width - flg->precision + 1, &flg->len, c);
	}
	else
	{
		ft_to_write (str, ft_strlen (str) - 1 , flg);
		ft_make_string_zero (add, &flg->len, c);
	}*/
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
		//printf ("[[[%d - %d - %d]]]\n", add, flg->width, flg->precision);

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
	if (flg->alig == false)
		ft_print_s_unalig (flg, pf_arg, c);
	else if (flg->alig == true)
		ft_print_s_alig (flg, pf_arg, c);
}