/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 08:30:18 by ldufour           #+#    #+#             */
/*   Updated: 2023/11/20 15:31:41 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
#include <limits.h>
#include <pthread.h>

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
	prg->fork = malloc(sizeof(pthread_mutex_t) * prg->nb_of_philo);
	if (!prg->fork)
		exit_prg_at_error("Malloc failure");
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
	prg->philo = malloc(sizeof(pthread_t) * prg->nb_of_philo);
	if (!prg->philo)
		exit_prg_at_error("Malloc failure");
}

void	mutex_destroy(t_prg *prg)
{
	int	i;

	i = 0;
	while (i < prg->nb_of_philo)
	{
		pthread_mutex_destroy(&prg->fork[i]);
		i++;
	}
}
void	mutex_init(t_prg *prg)
{
	int	i;

	i = 0;
	while (i < prg->nb_of_philo)
	{
		pthread_mutex_init(&prg->fork[i], NULL);
		i++;
	}
}

// void *action(void *data)
// {
//  t_cowboy cowboy;
//
//  cowboy = *(t_cowboy *)data;

void	thread_init(t_prg *prg, int argc, char **argv)
{
	int	i;

	i = 0;
	prg = init_struct();
	parsing_arguments(prg, argc, argv);
	malloc_forks(prg);
	malloc_thread(prg);
	mutex_init(prg);
}

/*
*	void philo_is_eating(t_prg *prg)
*	{
*		if (prg->philo[i])
*			if (prg->fork[i] == unlock && prg->fork[i + 1] == unlock)
*				prg->fork[i] == lock
*				prg->fork[i + 1] == lock
*				printf (i is eating)
*				usleep(time_to_eat)
*				prg->fork[i] == unlock
*				prg->fork[i + 1] == unlock
*			philo[i + 1] must sleep time_to_sleep
*			if fork lock than think and wait
*			check if philo is not dead (time_before_last_meal)
*			if (nbr_of_meals) check if nbr of meals == 0 (nbr_of_meals--)
*			check if philo can eat (fork lock) else think and wait
*			if eated then check for sleep


}
*
*/

void	*dispatch(void *arg)
{
	t_prg	prg;

	prg = *(t_prg *)arg;
	return (NULL);
}

void	thread_create(t_prg *prg)
{
	int	i;

	i = 0;
	while (i < prg->nb_of_philo)
	{
		pthread_create(&prg->philo[i], NULL, dispatch, NULL);
		i++;
	}
}
void	thread_join(t_prg *prg)
{
	int	i;

	i = 0;
	while (i < prg->nb_of_philo)
	{
		pthread_join(prg->philo[i], NULL);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_prg	*prg;
	int		i;

	i = 0;
	prg = NULL;
	if (argc == 5 || argc == 6)
	{
		thread_init(prg, argc, argv);
		// printf("%i\n", prg->nb_of_philo);
		// while (1)
		// 	printf("timepstamp in %lli\n", timeInMilliseconds());
		// pthread_mutex_destroy(&mutex);
		// printf("Total drinks served: %d\\n", g_drinks_served);
		thread_join(prg);
		mutex_destroy(prg);
	}
	else
		exit_prg_at_error("Invalid arguments");
	return (0);
}
