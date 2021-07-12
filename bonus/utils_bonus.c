#include "ft_printf_bonus.h"

ssize_t	ft_strlen(const char *str)
{
	ssize_t	a;

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
	return (p);
}

char	*ft_strdup_free(char *s, int f)
{
	char	*p;
	int		i;

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
	if (f == 1)
		free (s);
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
