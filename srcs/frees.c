/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzhakhan <dzhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:23:31 by dzhakhan          #+#    #+#             */
/*   Updated: 2024/09/23 10:23:32 by dzhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	free_map(int ***arr)
{
	int	i;

	i = 0;
	if (arr && *arr)
	{
		while ((*arr)[i])
		{
			free((*arr)[i]);
			i++;
		}
		free((*arr));
		*arr = NULL;
	}
}

void	free_split(char ***arr)
{
	int	i;

	i = 0;
	if (arr && *arr)
	{
		while ((*arr)[i])
		{
			free((*arr)[i]);
			i++;
		}
		free(*arr);
		*arr = NULL;
	}
}
