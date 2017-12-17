/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloulizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 12:49:03 by rloulizi          #+#    #+#             */
/*   Updated: 2017/04/30 15:11:42 by rloulizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		ft_check(char *str);

static size_t	number_pieces(char *file_name)
{ 
	int		fd;
	char	*buf;
	int		ret;
	size_t 	i;

	i = 0;
	if ((fd = open(file_name, O_RDONLY)) == -1)
		return (0);
	else
	{
		buf = ft_strnew(21);
		while (((ret = read(fd, buf, 21))) != 0)
			i++;
		return (i);
		close(fd);
	}
	return (0);
}
char		**ft_read_file(char *file_name)
{
	int		fd;
	char	*buf;
	size_t	ret;
	char 	**tab;
	size_t 	i;
	size_t	nb_piece;

	nb_piece = number_pieces(file_name);
	i = 0;
	if (!(tab = (char**)malloc(sizeof(char *) * nb_piece + 1 )))
		return NULL;
	if ((fd = open(file_name, O_RDONLY)) == -1)
		return (NULL);
	else
	{
		buf = ft_strnew(21);
		while ((ret = read(fd, buf, 21)) != 0)
		{
			if (nb_piece - 1 == i && ret != 20)
				return (NULL);
			tab[i] = ft_strnew(ret);
			tab[i] = ft_strncpy(tab[i], buf, ret);
			if (!ft_check(buf))
			{
				ft_putendl("error in this block:");
				ft_putstr(tab[i]);
				return (NULL);
			}
			i++;
		}
		tab[i] = 0;
		return (tab);
	}
	return (0);
}

void	puttab(char **tab)
{
	int i;

	i = 0;
	while (tab[i] != 0)
	{
		ft_putstr(tab[i]);
		i++;
	}
}

int 		main(int argc, char **argv)
{
	char **tab;

	if (argc == 2)
		if ((tab = ft_read_file(argv[1])))
			puttab(tab);
}
