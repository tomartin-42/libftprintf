# include "ft_printf.h"

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

void ft_dec_to_hex(long int num, char *code, int base, t_flags *flg)
{
	if (num > base)
	{
		ft_dec_to_hex(num / base, code, base, flg);
		ft_dec_to_hex(num % base, code, base, flg);
	}
	else
		flg->f_str = ft_stradd_char_empy(flg->f_str, code[num]);
}

char	*ft_stradd_char_empy(char const *s1, char c2)
{
	int		i;
	int		j;
	char	*p;

	if (!s1 || !c2)
	s1 = ft_strdup ("");
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