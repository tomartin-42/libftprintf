#include "ft_printf.h"

void	ft_procesing (const char *pf_string, t_flags *flags, va_list *pf_arg)
{
	ft_get_flags (pf_string, flags, pf_arg);
}

// this function get the flags and save in the struct
void	ft_get_flags (const char *string, t_flags *flags, va_list *pf_arg)
{
	int	offset;

	while (!ft_strchr ("cspdiuxX", *string))
	{
		if (*string == '-')
		{
			flags->alig = true;
			flags->zero = false;
		}
		else if (*string == '0')
			flags->zero = true;
		else if (ft_strchr("123456789*", *string))
		{
			flags->width = ft_get_whidt (string, &offset, pf_arg);
			string = string + offset - 1;
		}
		else if (*string == '.')
		{
			flags->point = true;
			flags->precision = ft_get_precision (string, &offset, pf_arg);
			string = string + offset - 1;
		}
		 string++;
	}
	ft_write_type (string, flags, pf_arg);

}

// this fuction get the number of whidt and add the value
// at flags_struct
int	ft_get_whidt (const char *string, int *offset, va_list *pf_arg)
{
	char	*s_whidt;
	int		answ;

	(*offset) = 0;
	if (*string == '*')
		return (va_arg (*pf_arg, int));
	answ = 0;
	s_whidt = ft_strdup ("");
	while (ft_isdigit (*string))
	{
		s_whidt = ft_stradd_char (s_whidt, *string);
		string++;
		(*offset)++;
	}
	answ = ft_atoi (s_whidt);
	free (s_whidt);
	return (answ);
}

// this fuction get the number of precision and add the value
// at flags_struct
int	ft_get_precision (const char *string, int *offset, va_list *pf_arg)
{
	char	*s_precision;
	int		answ;

	(*offset) = 0;
	answ = 0;
	string++;
	s_precision = ft_strdup ("");
	while (ft_isdigit (*string) || *string == '*')
	{
		if (*string == '*')
		{
			(*offset) = 1;
			return (va_arg (*pf_arg, int));
		}
		s_precision = ft_stradd_char (s_precision, *string);
		string++;
		(*offset)++;
	}
	answ = ft_atoi (s_precision);
	free (s_precision);
	return (answ);
}

void ft_write_type (const char *pf_string, t_flags *flags, va_list *pf_arg)
{
	if (*pf_string == 'c')
	{
		ft_print_c (flags, pf_arg);
	}
 	else if (*pf_string == 's')
 		flags->type = 's';
 	else if (*pf_string == 'p')
 		flags->type = 'p';
 	else if (*pf_string == 'd')
 		flags->type = 'd';
}
