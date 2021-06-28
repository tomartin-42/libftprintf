#include "ft_printf.h"

void	ft_make_string_zero (char *string)
{
	int	i;

	i = 0;
	while (string[i] != '\0')
		string[i++] = '0';
}

void	ft_make_string_space (char *string)
{
	int	i;

	i = 0;
	while (string[i] != '\0')
	{
		printf ("OOOOOO\n");
		string[i++] = ' ';
	}
}

int		ft_to_write (char *to_print, int leng, t_flags *flags)
{
	int	i;
	i = 0;

	while (i <= leng)
	{
		write (1, &to_print[i], 1);
		i++;
	}
	flags->len = flags->len + i;
	return (i);
}