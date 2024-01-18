/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 08:01:56 by ldufour           #+#    #+#             */
/*   Updated: 2024/01/17 13:42:55 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
#include <limits.h>
#include <stdarg.h>

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
		result = (result * 10) + (str[i] - '0');
		if (!ft_isdigit(str[i]) || result > INT_MAX)
			exit_prg_at_error("Invalid numbers");
		i++;
	}
	return (result);
}

void	parsing_arguments(t_data *philo, int argc, char **argv)
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

void	log_printf(const char *format, ...)
{
	FILE	*logFile;
	va_list	args;

	logFile = fopen("logfile", "a");
	if (logFile == NULL)
	{
		fprintf(stderr, "Error opening log file!\n");
		return ;
	}
	va_start(args, format);
	vfprintf(logFile, format, args);
	va_end(args);
	fclose(logFile);
}

void	print_philo_info(t_data *philo)
{
	log_printf("Number of philosophers: %d\n", philo->nb_of_philo);
	log_printf("Time to die: %ld\n", philo->time_to_die);
	log_printf("Time to eat: %ld\n", philo->time_to_eat);
	log_printf("Time to sleep: %ld\n", philo->time_to_sleep);
	if (philo->nb_of_meals)
		log_printf("Number of meals: %d\n", philo->nb_of_meals);
	else
		log_printf("Number of meals: Unlimited\n");
}
