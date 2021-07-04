#include "ft_printf.h"

static void ft_print_p_unalig (t_flags *flg, va_list *pf_arg, char c)
{
	unsigned long long int	pnt;
	int						nc_str;
	int						nc_width;
	char					*head;

	head = "0x";
    pnt = va_arg (*pf_arg, unsigned long long int);
    ft_dec_to_hex (pnt, "0123456789abcdef", 16, flg);
	nc_str = ft_strlen (flg->f_str);
	printf ("[[[[%s]]]]\n", flg->f_str);
	if (flg->point == true)
	{
		if (flg->precision == 0)
			nc_str = 0;
		else if (flg->precision < ft_strlen (flg->f_str))
			nc_str = flg->precision;
		else if (flg->precision >= ft_strlen (flg->f_str))
			nc_str = ft_strlen (flg->f_str);
	}
	nc_width = flg->width - (nc_str - 1);
	ft_make_string_zero (nc_width, &flg->len, c);
	ft_to_write (flg->f_str, nc_str , flg);
}

static void ft_print_p_alig (t_flags *flg, va_list *pf_arg, char c)
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
	{
		if (flg->precision == 0)
			nc_str = 0;
		else if (flg->precision < ft_strlen (flg->f_str))
			nc_str = flg->precision;
		else if (flg->precision >= ft_strlen (flg->f_str))
			nc_str = ft_strlen (flg->f_str);
	}
	nc_width = flg->width - (nc_str - 1);
	ft_to_write (flg->f_str, nc_str , flg);
	ft_make_string_zero (nc_width, &flg->len, c);

}

void	ft_print_p (t_flags *flg, va_list *pf_arg)
{
   /* unsigned long long int    pnt;
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
		ft_print_p_alig (flg, pf_arg, c);*/
	char	c;
	imprimeflags (flg);
	c = ' ';
	if (flg->alig == false && flg->zero == true)
		c = '0';
	if (flg->alig == false)
		ft_print_p_unalig (flg, pf_arg, c);
	else if (flg->alig == true)
		ft_print_p_alig (flg, pf_arg, c);
}
