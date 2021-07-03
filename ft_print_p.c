#include "ft_printf.h"

void	ft_print_p (t_flags *flg, va_list *pf_arg)
{
    unsigned long long int    pnt;
    char            *spnt;

    pnt = va_arg (*pf_arg, unsigned long long int);
    //printf ("[[%d]]-[[%s]]", pnt, pnt);
    //flg->f_str = ft_strdup ("0x");
    ft_dec_to_hex (pnt, "0123456789abcdef", 16, flg);
    printf ("[[%s]]]\n", flg->f_str);
}