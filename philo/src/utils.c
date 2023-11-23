/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 08:07:08 by ldufour           #+#    #+#             */
/*   Updated: 2023/11/23 09:02:52 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/*
 * Inspiration from Oceano
 */

void	*safe_malloc(size_t bytes)
{
	void	*ret;

	ret = malloc(bytes);
	if (!ret)
		exit_prg_at_error("Malloc failure");
	return (ret);
}

void	exit_prg_at_error(char *str)
{
	printf("Error\n");
	if (str)
		printf("%s\n", str);
	exit(EXIT_FAILURE);
}


