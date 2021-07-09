#include "ft_printf.h"

// Inicialice the flags structure
void	ft_init_flags (t_flags *flags)
{
	flags->alig = false;
	flags->zero = false;
	flags->point = false;
	flags->pad = false;
	flags->space = false;
	flags->plus = false;
	flags->bwidth = false;
	flags->negative = false;
	flags->width = 0;
	flags->precision = 0;
	flags->type = '0';
	flags->f_str = NULL;
}

int	ft_getx_whidt (va_list *pf_arg, t_flags *flg)
{
	int	answ;

	answ = 0;
	answ = va_arg (*pf_arg, int);
	if (answ < 0)
	{
		flg->alig = true;
		answ = answ * -1;
	}
	return (answ);
}

int	ft_getx_precision (va_list *pf_arg, t_flags *flg)
{
	int	answ;

	answ = 0;
	answ = va_arg (*pf_arg, int);
	if (answ < 0)
		flg->point = false;
	return (answ);
}
