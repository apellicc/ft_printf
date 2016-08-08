/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellicc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 06:08:14 by apellicc          #+#    #+#             */
/*   Updated: 2016/08/08 07:43:58 by apellicc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>

typedef struct		s_en
{
	va_list			a; /*ap*/ 
	int				r; /*ret*/
	char			c; /*conversion*/
	char			f; /*flags*/
	int				tm; /*taille minimun*/
	int				pr; /*precision*/
	int				p; // plus
	int				d; // diese
	int				z; // zero
	int 			m; // moins
	int 			s; //space
}					t_en;

