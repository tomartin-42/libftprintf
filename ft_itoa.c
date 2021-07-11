#include "ft_printf.h"

static int	ft_lenitoa (long n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n = n * -1;
		i++;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*ft_reverse (char *str)
{
	int		i;
	int		j;
	char	box;
	char	*aux;

	i = 0;
	j = 0;
	if (str[i++] == '-')
		j++;
	while (str[i])
		i++;
	i--;
	while (j < i)
	{
		box = str[j];
		str[j] = str[i];
		str[i] = box;
		j++;
		i--;
	}
	aux = str;
	free (str);
	return (aux);
}

char	*ft_itoa (long int n)
{
	char	*a;
	int		i;
	long	ln;
	char	*c;

	c = "0\0";
	if (n == 0)
		//return (ft_strdup("0"));
		return (c);
	ln = n;
	a = malloc (ft_lenitoa(ln) + 1);
	if (!a)
		return (NULL);
	i = 0;
	if (ln < 0)
	{
		ln = ln * -1;
		a[i++] = '-';
	}
	while (ln > 0)
	{
		a[i++] = '0' + ln % 10;
		ln = ln / 10;
	}
	a[i] = '\0';
	return (ft_reverse(a));
}
