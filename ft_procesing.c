# include "ft_printf.h"

 void ft_procesing (const char *pf_string, t_flags *flags, va_list *pf_arg)
{
	ft_get_flags (pf_string, flags);
}

// this function get the flags and save in the struct
void ft_get_flags (const char *string, t_flags *flags)
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
		else if (ft_strchr("123456789", *string))
		{
			flags->width = ft_get_whidt (string, &offset);
			string = string + offset;
		}
		else if (*string == '.')
			flags->point = true;
 		string++;
	}
	imprimeflags (flags);
}

// this fuction get the number of whidt and add the value
// at flags_struct
int ft_get_whidt (const char *string, int *offset)
{
	char	*s_whidt;
	int		answ;

	printf ("[[%s]]\n", string);
	(*offset) = 0;
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