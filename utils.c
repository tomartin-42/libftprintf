#include "ft_printf.h"

ssize_t  ft_strlen(const char *str)
{
        ssize_t  a;

		if (!str)
			return (0);
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

char	*ft_strdup(char *s)
{
	char	*p;
	int		i;
	//char	*aux;

	i = 0;
	if (!s)
	{
		s = malloc (1);
		*s = '\0';
	}
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
	//aux = p;
	//free (s);
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
