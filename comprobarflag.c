#include "ft_printf.h"

void imprimeflags (t_flags *flags)
{
	printf("*********************\n");
	printf("alig = %d\n", flags->alig);
	printf("zero = %d\n", flags->zero);
	printf("point = %d\n", flags->point);
	printf("pad = %d\n", flags->pad);
	printf("space = %d\n", flags->space);
	printf("plus = %d\n", flags->plus);
	printf("width = %d\n", flags->width);
	printf("bwidth = %d\n", flags->bwidth);
	printf("precision = %d\n", flags->precision);
	printf("len = %d\n", flags->len);
	printf("str = %d - %s\n", ft_strlen (flags->f_str), flags->f_str);	
	printf("*********************\n");

}