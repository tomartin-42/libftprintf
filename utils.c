#include "ft_printf.h"

ssize_t  ft_strlen(const char *str)
{
        ssize_t  a;

        a = 0;
        while (str[a] != '\0')
                a++;
        return (a);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != (char)c)
		i++;
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	char	*p;
	int		i;

	i = 0;
	while (s[i])
		i++;
	p = (char *)malloc (i + 1);
	if (!p)
		return (NULL);
	i = 0;
	while (s[i])
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

int	ft_isdigit(int c)
{
	int	resp;

	resp = 1;
	if (c < '0' || c > '9')
		resp = 0;
	return (resp);
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*p;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2);
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
	while (s2[i] != '\0')
		p[j++] = s2[i++];
	p[j] = '\0';
	return (p);
}

char	*ft_stradd_char(char const *s1, char c2)
{
	int		i;
	int		j;
	char	*p;

	if (!s1 || !c2)
		return (NULL);
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
	return (p);
}

long int ft_dec_to_hex(long int num)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (num > 16)
	{
		ft_dec_to_hex(num / 16);
		ft_dec_to_hex(num % 16);
	}
	else
		write (1, &hex[num], 1);

}