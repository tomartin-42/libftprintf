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

#include "libftprintf.h"

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
			pf_string++;
		}
		else
		{
			write (1, pf_string, 1);
			flags.len += 1;
		}
		pf_string++;
	}
	va_end (arg);
}