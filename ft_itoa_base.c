/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloulizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 16:23:20 by rloulizi          #+#    #+#             */
/*   Updated: 2017/09/11 13:48:00 by rloulizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		get_size(long int nb, int base, int *len)
{
	if (nb >= base)
	{
		get_size(nb / base, base, len);
		get_size(nb % base, base, len);
	}
	else
		(*len)++;
}

static void		ft_fill_str(char *str, long int n, int *index, int base)
{
	if (n >= base)
	{
		ft_fill_str(str, n % base, index, base);
		ft_fill_str(str, n / base, index, base);
	}
	else
	{
		if (n > 9)
		{
			str[*index] = 'a' - 10 + n;
			*index = *index + 1;
		}
		else
		{
			str[*index] = 48 + n;
			*index = *index + 1;
		}
	}
}

char			*ft_itoa_base(long int n, int base)
{
	char	*str;
	int		i;
	int		len;

	len = 0;
	i = 0;
	if (n < 0)
	{
		n = n * - 1;
		get_size(n, base, &len);
		str = (char *)malloc(sizeof(char) * len + 2);
		str[len] = '-';
		str[len + 1] = '\0';
	}
	else
	{
		get_size(n, base, &len);
		str = (char*)malloc(sizeof(char) * len + 1);
		str[len] = '\0';
	}
	ft_fill_str(str, n, &i, base);
	return (ft_strrev(str));
}
