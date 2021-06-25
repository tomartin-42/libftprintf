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
	t_list	flags;

	while (*pf_string)
	{
		if (*pf_string != '%')
			ft_init_flags (&flags);
			//viene el tomate;
		else
		{
			write (1, pf_string, 1);
			falgs.len++;
		}
	}
}
