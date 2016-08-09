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
	va_list			a; /*ap*/
	int				r; /*ret*/
	char			c; /*conversion*/
	char			f; /*flags*/
	int				w; /*taille minimun*/
	int				pr; /*precision*/
	int				p; // plus
	int				d; // diese
	int				z; // zero
	int 			m; // moins
	int 			s; //space
	int 			print;
}					t_en;

void	ft_print_flag(t_en *e);
char	*ft_convert(long int n, int base, char *str, int i);
char	*ft_itoa_base(long int n, int base);
void	ft_is_d(int *i, t_en *e);
void	ft_is_D(int *i, t_en *e);
void	ft_is_i(int *i, t_en *e);
void	ft_is_u(int *i, t_en *e);
void	ft_is_U(int *i, t_en *e);
void	ft_is_o(int *i, t_en *e);
void	ft_is_O(int *i, t_en *e);
void	ft_is_p(int *i, t_en *e);
void	ft_is_x(int *i, t_en *e);
void	ft_is_X(int *i, t_en *e);
void	ft_is_s(int *i, t_en *e);
void	ft_is_S(int *i, t_en *e);
void	ft_is_c(int *i, t_en *e);
void	ft_is_C(int *i, t_en *e);
void	ft_is_percent(int *i, t_en *e);
void	ft_check_flag(char *f, int *i, t_en *e);
void	ft_check_width(char *f, int *i, t_en *e);
void	ft_check_precision(char *f, int *i, t_en *e);
void	ft_check_modify_type(char *f, int *i, t_en *e);
void	ft_check_specifier(char *f, int *i, t_en *e);
void	ft_select_print(int *i, t_en *e);
void	ft_check(char *f, int *i, t_en *e);
void	ft_parse(char *f, t_en *e);
void	ft_ini(t_en *e);
int		ft_printf(const char *format, ...);
int		ft_putstr_capitalizer(char *str);
int		ft_putstr_minimizer(char *str);


#endif
