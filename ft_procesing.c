#include "ft_printf.h"

// this function get the flags and save in the struct
void	ft_get_flags (const char *str, t_flags *flg, va_list *pf_arg)
{
	int		off;

	off = 0;
	str++;
	while (!ft_strchr ("cspdiuxX", *str))
	{
		off = ft_proces_flags (str, flg, pf_arg);
		str = str + off;
		off = 0;
		if (!ft_strchr ("cspdiuxX0123456789*.-", *str))
		{
			str += 1;
		}	
	}
	if (flg->width > 0)
		flg->bwidth = true;
	ft_write_type (str, flg, pf_arg);
}

int	ft_proces_flags (const char *str, t_flags *flg, va_list *pf_arg)
{
	int		off;

	off = 0;
	if (*str == '-' && flg->alig == false)
	{
		flg->alig = true;
		off++;
	}
	//else if (ft_strchr("123456789*", *str) && flg->point == false)
	else if (ft_strchr("123456789*", *str))
		flg->width = ft_get_whidt (str, &off, pf_arg, flg);
	else if (*str == '0')
	{
		if (flg->zero == false)
			flg->zero = true;
		off++;
	}
	else if (*str == '.')
	{
		flg->point = true;
		flg->precision = ft_get_prec (str, &off, pf_arg, flg);
		off++;
	}
	return (off);
}

// this fuction get the number of whidt and add the value
// at flags_struct
int	ft_get_whidt (const char *string, int *off, va_list *pf_arg, t_flags *flg)
{
	char	*s_whidt;
	int		answ;

	answ = 0;
	s_whidt = ft_strdup ("");
	while (ft_isdigit (*string) || *string == '*')
	{
		if (*string == '*')
		{
			*off += 1;
			answ = ft_getx_whidt (pf_arg, flg);
			return (answ);
		}
		s_whidt = ft_stradd_char (s_whidt, *string);
		string++;
		*off += 1;
	}
	answ = ft_atoi (s_whidt);
	free (s_whidt);
	return (answ);
}

// this fuction get the number of precision and add the value
// at flags_struct
int	ft_get_prec (const char *string, int *off, va_list *pf_arg, t_flags *flg)
{
	char	*s_precision;
	int		answ;

	answ = 0;
	string++;
	s_precision = ft_strdup ("");
	while (ft_isdigit (*string) || *string == '*')
	{
		if (*string == '*')
		{
			*off += 1;
			answ = ft_getx_precision (pf_arg, flg);
			return (answ);
		}
		s_precision = ft_stradd_char (s_precision, *string);
		string++;
		*off += 1;
	}
	answ = ft_atoi (s_precision);
	free (s_precision);
	return (answ);
}
