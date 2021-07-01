#include "ft_printf.h"

void	ft_print_p (t_flags *flg, va_list *pf_arg)
{
    long long    pnt;

    pnt = av_arg (pf_arg, long long);

    printf ("[[[%p]]]\n", pnt);

}