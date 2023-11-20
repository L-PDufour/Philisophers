/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 08:30:18 by ldufour           #+#    #+#             */
/*   Updated: 2023/11/20 13:05:00 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
#include <malloc/_malloc.h>
#include <pthread.h>
#include <stdio.h>
#include <sys/_pthread/_pthread_t.h>

void	exit_prg_at_error(char *str)
{
	printf("Error\n");
	if (str)
		printf("%s\n", str);
	exit(EXIT_FAILURE);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

long	ft_atol(const char *str)
{
	long	result;

	result = 0;
	if (!str || ft_strlen(str) == 0 || ft_strlen(str) > 10)
		exit_prg_at_error("Invalid numbers");
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == 45)
		exit_prg_at_error("Invalid numbers");
	while (ft_isdigit(*str))
	{
		result = (result * 10) + (*str - '0');
		str++;
	}
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

t_prg	*init_struct(void)
{
	static t_prg	*prg;

	prg = NULL;
	if (!prg)
	{
		prg = (t_prg *)malloc(sizeof(t_prg));
		if (!prg)
		{
			printf("Malloc failure\n");
			exit(EXIT_FAILURE);
		}
	}
	return (prg);
}

void	malloc_forks(t_prg *prg)
{
	// int	i;
	// i = 0;
	// while (i < prg->nb_of_philo)
	// {
	prg->fork = malloc(sizeof(pthread_mutex_t) * prg->nb_of_philo);
	if (!prg->fork)
		exit_prg_at_error("Malloc failure");
	// i++;
	// }
}

long long	timeInMilliseconds(void)
{
	static struct timeval	start = {0, 0};
	struct timeval			end;

	if (start.tv_sec == 0 && start.tv_usec == 0)
		gettimeofday(&start, NULL);
	gettimeofday(&end, NULL);
	return (((long long)end.tv_sec) * 1000 + (end.tv_usec / 1000))
		- (((long long)start.tv_sec) * 1000 + (start.tv_usec / 1000));
}

void	malloc_thread(t_prg *prg)
{
	// int	i;
	//
	// i = 0;
	// while (i < prg->nb_of_philo)
	// {
	prg->philo = malloc(sizeof(pthread_t) * prg->nb_of_philo);
	if (!prg->philo)
		exit_prg_at_error("Malloc failure");
	// i++;
	// }
}

void	ft_philosophers(void)
{
	printf("test\n");
}
// Ajouter un statut pour proteger les forks
int	main(int argc, char **argv)
{
	t_prg	*prg;
	int		i;

	i = 0;
	if (argc == 5 || argc == 6)
	{
		prg = init_struct();
		parsing_arguments(prg, argc, argv);
		malloc_forks(prg);
		malloc_thread(prg);
		while (i < prg->nb_of_philo)
		{
			pthread_create(&prg->philo[i], NULL, (void *)&ft_philosophers, NULL);
			i++;
		}
		i = 0;
		while (i < prg->nb_of_philo)
		{
			pthread_join(prg->philo[i], NULL);
			i++;
		}
		printf("%i\n", prg->nb_of_philo);
		// while (1)
		// 	printf("timepstamp in %lli\n", timeInMilliseconds());
	}
	else
		exit_prg_at_error("Invalid arguments");
	return (0);
}
