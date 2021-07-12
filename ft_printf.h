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
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_flag{
	char	*f_str;
	int		len;
	int		width;
	int		precision;
	char	type;
	bool	bwidth;
	bool	alig;
	bool	zero;
	bool	point;
	bool	pad;
	bool	space;
	bool	plus;
	bool	negative;
}	t_flags;

# define LL unsigned long long int
# define CC const char

void	ft_do_it (const char *pf_string, t_flags *flags, va_list *arg);
ssize_t	ft_strlen (const char *str);
int		ft_printf (const char *strg, ...);
void	ft_init_flags (t_flags *flags);
void	ft_procesing (const char *pf_string, t_flags *flags, va_list *pf_arg);
int		ft_proces_flags (const char *str, t_flags *flg, va_list *pf_arg);
void	ft_get_flags (const char *string, t_flags *flags, va_list *pf_arg);
char	*ft_strchr (const char *s, int c);
char	*ft_strdup (char *s);
char	*ft_strdup_free(char *s, int f);
int		ft_get_whidt (CC *string, int *offset, va_list *pf_arg, t_flags *flg);
int		ft_get_prec (CC *string, int *offset, va_list *pf_arg, t_flags *flg);
int		ft_getx_whidt (va_list *pf_arg, t_flags *flg);
int		ft_getx_precision (va_list *pf_arg, t_flags *flg);
char	*ft_itoa (long int n);

int		ft_isdigit (int c);
int		ft_atoi (const char *str);
char	*ft_stradd_char_empy(char *s1, char c2);
void	ft_write_type (const char *pf_string, t_flags *flags, va_list *pf_arg);
void	ft_dec_to_hex(LL num, char *code, LL base, t_flags *flg);
void	ft_print_c (t_flags *flg, va_list *pf_arg);
void	ft_print_s (t_flags *flg, va_list *pf_arg);
void	ft_print_p (t_flags *flg, va_list *pf_arg);
void	ft_print_d (t_flags *flg, va_list *pf_arg);
void	ft_print_u (t_flags *flg, va_list *pf_arg);
void	ft_print_x (t_flags *flg, va_list *pf_arg);
void	ft_print_xu (t_flags *flg, va_list *pf_arg);
void	ft_print_por (t_flags *flg);

void	ft_make_string_zero (int num, t_flags *flg, char c);
void	ft_to_write (char *to_print, int leng, t_flags *flags);

int		ft_skip (const char *pf_string);

#endif
