#include "ft_printf.h"

static void ft_print_p_unalig (t_flags *flg, va_list *pf_arg, char c)
{
	char	*str;
	int	    add;

	add = 0;
	str = flg->f_str;

    add = flg->width - (ft_strlen (str) + 1);
    if (add < 0)
        add = 0;
    if (c == '0')
    {
        write (1, "0x", 2);
        flg->len += 2;
		ft_make_string_zero (add, &flg->len, c);
		ft_to_write (str, ft_strlen (str) - 1 , flg);
    }
    else
    {
        ft_make_string_zero (add, &flg->len, c);
        write (1, "0x", 2);
        flg->len += 2;
        ft_to_write (str, ft_strlen (str) - 1 , flg);
    }
}

static void ft_print_p_alig (t_flags *flg, va_list *pf_arg, char c)
{
	char	*str;
	int	    add;

	add = 0;
	str = flg->f_str;
    c = ' ';
    add = flg->width - (ft_strlen (str) + 1);
    if (add < 0)
        add = 0;
    write (1, "0x", 2);
    flg->len += 2;
    ft_to_write (str, ft_strlen (str) - 1 , flg);
    ft_make_string_zero (add, &flg->len, c);

}

void	ft_print_p (t_flags *flg, va_list *pf_arg)
{
    unsigned long long int    pnt;
    char            *spnt;
	char	c;

    pnt = va_arg (*pf_arg, unsigned long long int);
    ft_dec_to_hex (pnt, "0123456789abcdef", 16, flg);
    //flg->f_str = ft_strjoin ("0x", flg->f_str);
    //printf ("%s", flg->f_str);
	
	if (flg->zero == true)
		c = '0';
    else if (flg->zero == false)
		c = ' ';	
	if (flg->alig == false)
    {
		ft_print_p_unalig (flg, pf_arg, c);
    }
	else if (flg->alig == true)
		ft_print_p_alig (flg, pf_arg, c);
}
