# include "ft_printf.h"

// Inicialice the flags structure
void ft_init_flags (t_flags *flags)
{
	flags->alig = false;
	flags->zero = false;
	flags->point = false;
	flags->pad = false;
	flags->space = false;
	flags->plus = false;
	flags->len = 0;
}