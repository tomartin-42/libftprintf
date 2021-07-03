/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 10:11:44 by tomartin          #+#    #+#             */
/*   Updated: 2021/06/23 10:30:35 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf (const char *pf_string, ...)
{
	va_list arg;
	t_flags	flags;

	flags.len = 0;			
	va_start (arg, pf_string);
	while (*pf_string)
	{
		if (*pf_string == '%')
		{
			ft_procesing (pf_string, &flags, &arg);
			pf_string = pf_string + ft_skip (pf_string, &flags);
		}
		else
		{
			write (1, pf_string, 1);			flags.len += 1;
		}
		pf_string++;
	}
	va_end (arg);
	return (flags.len);
}

int	ft_skip (const char *string, t_flags *flags)
{
	int	offset;

	offset = 0;
	if (ft_strchr ("%", *string))
	{
		string++;
		while (ft_strchr ("1234567890*-.", *string))
		{
			string++;
			offset++;
		}
		if (ft_strchr ("cspdiuxX", *string))
		{
			string++;
			offset++;
		}
	}
	return (offset);
}

void	ft_procesing (const char *pf_string, t_flags *flags, va_list *pf_arg)
{
	ft_init_flags (flags);
	ft_get_flags (pf_string, flags, pf_arg);
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