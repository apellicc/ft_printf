/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellicc <apellicc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 16:03:30 by apellicc          #+#    #+#             */
/*   Updated: 2015/12/17 17:08:08 by apellicc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_intlen(long long int n)
{
	int	size;
	unsigned long long i;

	size = 0;
	i = n;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		i = -n;
		size++;
	}
	while (i > 9)
	{
		i = i / 10;
		size++;
	}
	size++;
	return (size);
}
