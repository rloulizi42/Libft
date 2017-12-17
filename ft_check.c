/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloulizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 14:44:19 by rloulizi          #+#    #+#             */
/*   Updated: 2017/04/30 15:11:41 by rloulizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int			ft_check_norme(char *str)
{
	int	diese;
	int	dot;
	int	n;
	int	i;

	diese = 0;
	dot = 0;
	n = 0;
	i = 0;
	if (str == NULL)
		return (0);
	while (i < 20)
	{
		if (str[i] == '#')
			diese++;
		if (str[i] == '.')
			dot++;
		if (str[i] == '\n' && ((i+1) % 5 == 0))
			n++;
		i++;
	}
	if (diese == 4 && dot == 12 && n == 4)
		return (1);
	return (0);
}

static int		ft_check_valide_i_and_o(char *str)
{
	int i;

	i = 0;
	if (str == NULL)
		return (0);
	while (i < 21)
	{
		if (str[i] == '#' && str[i + 1] == '#' && str[i + 2] == '#' && str[i + 3] == '#')
			return (1);
		else if (str[i] == '#' && str[i + 5] == '#' && str[i + 10] == '#' && str[i + 15] == '#')
			return (1);
		else if (str[i] == '#' && str[i + 1] == '#' && str[i + 5] == '#' && str[i + 6] == '#')
			return (1);
		i++;
	}
	return (0);
}

static int		ft_check_valide_l(char *str)
{
	int i;

	i = 0;
	if (str == NULL)
		return (0);
	while (i < 21)
	{
		if (str[i] == '#' && str[i + 1] == '#' && str[i + 5] == '#' && str[i + 10] == '#')
			return (1);
		else if (str[i] == '#' && str[i + 1] == '#' && str[i + 6] == '#' && str[i + 11] == '#')
			return (1);
		else if (str[i] == '#' && str[i + 5] == '#' && str[i + 10] == '#' && str[i + 11] == '#')
			return (1);
		else if (str[i] == '#' && str[i + 5] == '#' && str[i + 9] == '#' && str[i + 10] == '#')
			return (1);
		i++;
	}
	return (0);
}

static int		ft_check_valide_s(char *str)
{
	int i;

	i = 0;
	if (str == NULL)
		return (0);
	while (i < 21)
	{
		if (str[i] == '#' && str[i + 1] == '#' && str[i + 6] == '#' && str[i + 7] == '#')
			return (1);
		else if (str[i] == '#' && str[i + 1] == '#' && str[i + 4] == '#' && str[i + 5] == '#')
			return (1);
		else if (str[i] == '#' && str[i + 4] == '#' && str[i + 5] == '#' && str[i + 9] == '#')
			return (1);
		else if (str[i] == '#' && str[i + 5] == '#' && str[i + 6] == '#' && str[i + 11] == '#')
			return (1);
		i++;
	}
	return (0);
}

static int		ft_check_valide_t(char *str)
{
	int i;

	i = 0;
	if (str == NULL)
		return (0);
	while (i < 21)
	{
		if (str[i] == '#' && str[i + 4] == '#' && str[i + 5] == '#' && str[i + 6] == '#')
			return (1);
		else if (str[i] == '#' && str[i + 1] == '#' && str[i + 2] == '#' && str[i + 6] == '#')
			return (1);
		else if (str[i] == '#' && str[i + 5] == '#' && str[i + 6] == '#' && str[i + 10] == '#')
			return (1);
		else if (str[i] == '#' && str[i + 4] == '#' && str[i + 5] == '#' && str[i + 10] == '#')
			return (1);
		i++;
	}
	return (0);
}

static int		ft_check_valide_j(char *str)
{
	int i;

	i = 0;
	if (str == NULL)
		return (0);
	while (i < 21)
	{
		if (str[i] == '#' && str[i + 5] == '#' && str[i + 6] == '#' && str[i + 7] == '#')
			return (1);
		else if (str[i] == '#' && str[i + 3] == '#' && str[i + 4] == '#' && str[i + 5] == '#')
			return (1);
		else if (str[i] == '#' && str[i + 1] == '#' && str[i + 2] == '#' && str[i + 5] == '#')
			return (1);
		else if (str[i] == '#' && str[i + 1] == '#' && str[i + 2] == '#' && str[i + 7] == '#')
			return (1);
		i++;
	}
	return (0);
}


int		ft_check(char *str)
{
	int i;

	i = 0;
	if (str == NULL)
		return (0);
	while (i < 21)
	{
		if ((ft_check_norme(str)) && ((ft_check_valide_i_and_o(str))
				   || (ft_check_valide_l(str)) || (ft_check_valide_s(str)) 
				   || (ft_check_valide_t(str)) || (ft_check_valide_j(str))))
						   return (1);
		i++;
	}
	return (0);
}
