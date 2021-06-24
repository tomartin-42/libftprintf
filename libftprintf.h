/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 10:21:01 by tomartin          #+#    #+#             */
/*   Updated: 2021/06/23 10:24:33 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stddef.h>
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>

ssize_t	ft_strlen(const char *str);
int		ft_printf (const char *strg, ...);

#endif
