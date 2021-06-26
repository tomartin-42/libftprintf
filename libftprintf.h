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
# include <stdbool.h>

typedef struct s_flag{
    bool	alig;
	bool	zero;
	bool	point;
	bool	pad;
	bool	space;
	bool	plus;
    int		width;
	int		len;
	char	*f_str;

}	t_flags;

ssize_t	ft_strlen(const char *str);
int		ft_printf (const char *strg, ...);
void ft_init_flags (t_flags *flags);
void ft_procesing (const char *pf_string, t_flags *flags, va_list *pf_arg);



#endif
