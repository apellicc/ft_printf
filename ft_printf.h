/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellicc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 06:08:14 by apellicc          #+#    #+#             */
/*   Updated: 2016/08/09 01:15:08 by apellicc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct		s_en
{
	va_list			a;
	int				r;
	char			c;
	char			f;
	int				w;
	int				pr;
	int				p;
	int				d;
	int				z;
	int				m;
	int				s;
	int				print;
}					t_en;

void				ft_print_flag(t_en *e);
char				*ft_convert(long long int n, int base, char *str, int i);
char				*ft_itoa_base(long long int n, int base);
char				*ft_uitoa_base(unsigned long long int n, int base);
void				ft_is_d(int *i, t_en *e);
void				ft_is_u(int *i, t_en *e);
void				ft_is_o(int *i, t_en *e);
void				ft_is_p(int *i, t_en *e);
void				ft_is_x(int *i, t_en *e);
void				ft_is_x2(int *i, t_en *e);
void				ft_is_s(int *i, t_en *e);
void				ft_is_s2(int *i, t_en *e);
void				ft_is_c(int *i, t_en *e);
void				ft_is_c2(int *i, t_en *e);
void				ft_is_percent(int *i, t_en *e);
void				ft_check_flag(char *f, int *i, t_en *e);
void				ft_check_width(char *f, int *i, t_en *e);
void				ft_check_precision(char *f, int *i, t_en *e);
void				ft_check_modify_type(char *f, int *i, t_en *e);
void				ft_check_specifier(char *f, int *i, t_en *e);
void				ft_select_print(char *f, int *i, t_en *e);
void				ft_check(char *f, int *i, t_en *e);
void				ft_parse(char *f, t_en *e);
void				ft_ini(t_en *e);
int					ft_printf(const char *format, ...);
int					ft_putstr_capitalizer(char *str);
int					ft_putstr_minimizer(char *str);
void				ft_print_w(t_en *e, long long int n);
void				ft_nprint_w(t_en *e);
void				ft_is_invalid(char *f, int *i, t_en *e);
int					ft_putwchar(wchar_t value);
int					ft_putswchar(wchar_t *value);
int					ft_wcharlen(wchar_t value);
int					ft_swcharlen(wchar_t *value);

#endif
