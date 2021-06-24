# include "libftprintf.h"

char	*ft_strjoin(char const *s1, char const s2)
{
	int		i;
	int		j;
	char	*p;

	if (!s1 || !s2)
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
	p[j++] = s2;
	p[j] = '\0';
	return (p);
}