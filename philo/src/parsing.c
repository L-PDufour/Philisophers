/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 08:01:56 by ldufour           #+#    #+#             */
/*   Updated: 2023/11/23 08:01:56 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

static int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

static long	ft_atol(const char *str)
{
	long	result;
	int		i;

	i = 0;
	result = 0;
	if (!str || ft_strlen(str) == 0 || ft_strlen(str) > 10)
		exit_prg_at_error("Invalid numbers");
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			exit_prg_at_error("Invalid numbers");
		result = (result * 10) + (*str - '0');
		i++;
	}
	if (result > INT_MAX)
		exit_prg_at_error("Invalid numbers");
	return (result);
}

void	parsing_arguments(t_prg *philo, int argc, char **argv)
{
	philo->nb_of_philo = ft_atol(argv[1]);
	if (philo->nb_of_philo == 0)
		exit_prg_at_error("Need one philosophers");
	philo->time_to_die = ft_atol(argv[2]);
	philo->time_to_eat = ft_atol(argv[3]);
	philo->time_to_sleep = ft_atol(argv[4]);
	if (argc == 6)
		philo->nb_of_meals = ft_atol(argv[5]);
}


