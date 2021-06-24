# include "libftprintf.h"

long int ft_change_base(long int num, char *code, int base)
{
	if (num > base)
	{
		ft_change_base(num / base, code, base);
		ft_change_base(num % base, code, base);
	}
	else
		write (1, &code[num], 1);
}