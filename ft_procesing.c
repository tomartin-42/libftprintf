#include "ft_printf.h"

void	ft_procesing (const char *pf_string, t_flags *flags, va_list *pf_arg)
{
	ft_init_flags (flags);
	ft_get_flags (pf_string, flags, pf_arg);
}

// this function get the flags and save in the struct
void	ft_get_flags (const char *str, t_flags *flg, va_list *pf_arg)
{
	int		offset;
	bool	check;

	check = false;
	offset = 0;
	str++;
	while (!ft_strchr ("cspdiuxX", *str))
	{
		if (*str == '-')
		{
			flg->alig = true;
			offset++;
		}
		else if (ft_strchr("123456789*", *str) && flg->point == false)
			flg->width = ft_get_whidt (str, &offset, pf_arg);
		else if (*str == '0' && check == false)
		{
			flg->zero = true;
			offset++;
		}
		else if (*str == '.')
		{
			flg->point = true;
			flg->precision = ft_get_precision (str, &offset, pf_arg);
			offset++;
		}
		str = str + offset;
		offset = 0;
		check = true;
	}
	ft_write_type (str, flg, pf_arg);
}

// this fuction get the number of whidt and add the value
// at flags_struct
int	ft_get_whidt (const char *string, int *offset, va_list *pf_arg)
{
	char	*s_precision;
	int		answ;

	answ = 0;
	s_precision = ft_strdup ("");
	while (ft_isdigit (*string) || *string == '*')
	{
		if (*string == '*')
		{
			answ = va_arg (*pf_arg, int);
			if (answ < 0)
				return (answ * -1);
			else 
				return (answ);
		}
		s_precision = ft_stradd_char (s_precision, *string);
		string++;
		*offset += 1;
	}
	answ = ft_atoi (s_precision);
	free (s_precision);
	return (answ);
}

// this fuction get the number of precision and add the value
// at flags_struct
int	ft_get_precision (const char *string, int *offset, va_list *pf_arg)
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
			answ = va_arg (*pf_arg, int);
			if (answ < 0)
				return (answ * -1);
			else 
				return (answ);
		}
		s_precision = ft_stradd_char (s_precision, *string);
		string++;
		*offset += 1;
	}
	answ = ft_atoi (s_precision);
	free (s_precision);
	return (answ);
}

void ft_write_type (const char *pf_string, t_flags *flags, va_list *pf_arg)
{
	if (*pf_string == 'c')
		ft_print_c (flags, pf_arg);
 	else if (*pf_string == 's')
 		ft_print_s (flags, pf_arg);
 	else if (*pf_string == 'p')
		 ft_print_p (flags, pf_arg);
 	else if (*pf_string == 'd')
 		flags->type = 'd';
}
