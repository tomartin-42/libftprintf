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

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stddef.h>
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct s_flag{
	char	*f_str;
	int		len;
    int		width;
    bool	alig;
	bool	zero;
	bool	point;
	bool	pad;
	bool	space;
	bool	plus;

}	t_flags;

# define INT_MIN -2147483648
# define INT_MAX 2147483647

ssize_t	ft_strlen(const char *str);
int		ft_printf (const char *strg, ...);
void 	ft_init_flags (t_flags *flags);
void 	ft_procesing (const char *pf_string, t_flags *flags, va_list *pf_arg);
void 	ft_get_flags (char *string, t_flags *flags);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
int		ft_get_whidt (char *string);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_stradd_char(char const *s1, char c2);



// BORRAR ---------------------------
void imprimeflags (t_flags *flags);
//BORRAR -----------------------------

#endif
