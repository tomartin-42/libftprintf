#include "ft_printf_bonus.h"

void	ft_dec_to_hex(LL num, char *code, LL base, t_flags *flg)
{
	if (num >= base)
	{
		ft_dec_to_hex(num / base, code, base, flg);
		ft_dec_to_hex(num % base, code, base, flg);
	}
	else
		flg->f_str = ft_stradd_char_empy(flg->f_str, code[num]);
}

char	*ft_stradd_char_empy(char *s1, char c2)
{
	int		i;
	int		j;
	char	*p;

	if (!s1)
	{	
		s1 = malloc (1);
		*s1 = '\0';
	}
	i = ft_strlen(s1) + 1;
	p = malloc(i + 1);
	if (!p)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j] != '\0')
	{
		p[j] = s1[j];
		j++;
	}
	p[j++] = c2;
	p[j] = '\0';
	free (s1);
	return (p);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			neg;
	long long	resp;

	i = 0;
	resp = 0;
	neg = 1;
	while (str[i] == ' ' || (9 <= str[i] && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		resp = resp * 10 + str[i] - '0';
		i++;
		if ((resp * neg) > INT_MAX)
			return (-1);
		if ((resp * neg) < INT_MIN)
			return (0);
	}
	return (resp * neg);
}
