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
	ft_init_flags (&flags);
	va_start (arg, pf_string);
	while (*pf_string)
	{
		if (*pf_string == '%')
		{
			ft_procesing (pf_string, &flags, &arg);
		}
		else
		{
			ft_skip (pf_string, &flags);
		}
		pf_string++;
	}
	va_end (arg);
	return (flags.len);
}

int	ft_skip (char *string, t_flags *flags)
{

	if (ft_strchr ("%", *string))
	{
		string++;
		while (ft_strchr ("1234567890*-.", *string))
			string++;
		if (ft_strchr ("cspdiuxX", *string))
			string++;
	}
	write (1, string, 1);
	flags->len += 1;
	return (flags->len);
}