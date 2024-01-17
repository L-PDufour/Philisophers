/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 08:30:18 by ldufour           #+#    #+#             */
/*   Updated: 2024/01/17 08:42:27 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
#include <pthread.h>

void	clean_process(t_prg *prg)
{
	int	i;

	i = 0;
	while (i < prg->nb_of_philo)
	{
		pthread_mutex_destroy(&prg->philosophers[i].r_fork);
		free(prg->philosophers[i].l_fork);
		free(&prg->philosophers[i]);
		i++;
	}
	pthread_mutex_destroy(&prg->print);
	free(prg);
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

/*
*	void philo_is_eating(t_prg *prg)
*	{
*		if (prg->philo[i])
*			if (prg->fork[i] == unlock && prg->fork[i + 1] ==
unlock) *				prg->fork[i] == lock *
prg->fork[i + 1] == lock *				printf (i is eating)
*				usleep(time_to_eat)
*				prg->fork[i] == unlock
*				prg->fork[i + 1] == unlock
*			philo[i + 1] must sleep time_to_sleep
*			if fork lock than think and wait
*			check if philo is not dead (time_before_last_meal)
*			if (nbr_of_meals) check if nbr of meals == 0
(nbr_of_meals--) *			check if philo can eat (fork lock) else
think and wait *			if eated then check for sleep


}
*
*/

// • Any state change of a philosopher must be formatted as follows:
// Replace timestamp_in_ms with the current timestamp in milliseconds
// and X with the philosopher number.

void	key_logger(t_prg *prg, t_philosophers *philosohers, int number)
{
	pthread_mutex_lock(&prg->print);
	prg->time = timeInMilliseconds();
	if (philosohers->state == EAT)
		printf("%li philosopher[%i] is eating\n", prg->time, number);
	else if (philosohers->state == DIE)
		printf("%li philosopher[%i] died\n", prg->time, number);
	else if (philosohers->state == SLEEP)
		printf("%li philosopher[%i] is sleeping\n", prg->time, number);
	else if (philosohers->state == FORKING)
		printf("%li philosopher[%i] has taken a fork\n", prg->time, number);
	else if (philosohers->state == THINK)
		printf("%li philosopher[%i] is thinking\n", prg->time, number);
	else
		printf("%li philosopher[%i] is testin\n", prg->time, number);
	pthread_mutex_unlock(&prg->print);
}

void	*dispatch(void *arg)
{
	t_prg	*prg;
	int		i;

	prg = (t_prg *)arg;
	i = 0;
	key_logger(prg, prg->philosophers, i);
	return (NULL);
}

void	thread_create(t_prg *prg)
{
	int	i;

	i = 0;
	while (i < prg->nb_of_philo)
	{
		pthread_create(prg->philosophers[i].threads, NULL, dispatch, prg);
		i++;
	}
}

// void	thread_join(t_prg *prg)
// {
// 	int	i;
//
// 	i = 0;
// 	while (i < prg->nb_of_philo)
// 	{
// 		pthread_join(prg->threads[i], NULL);
// 		i++;
// 	}
// }

void	mutex_init(t_prg *prg)
{
	int	i;

	i = 0;
	pthread_mutex_init(&prg->print, NULL);
	while (i < prg->nb_of_philo)
	{
		pthread_mutex_init(&prg->philosophers[i].r_fork, NULL);
		pthread_mutex_init(prg->philosophers[i].l_fork, NULL);
		i++;
	}
}

t_prg	*init_struct(int argc, char **argv)
{
	static t_prg	*prg;
	int				i;

	i = 0;
	prg = NULL;
	if (!prg)
		prg = (t_prg *)safe_malloc(sizeof(t_prg));
	parsing_arguments(prg, argc, argv);
	prg->philosophers = (t_philosophers *)safe_malloc(prg->nb_of_philo
			* sizeof(t_philosophers));
	mutex_init(prg);
	while (i < prg->nb_of_philo)
	{
		prg->philosophers[i].l_fork = (pthread_mutex_t *)safe_malloc(sizeof(pthread_mutex_t));
		if (i == prg->nb_of_philo - 1)
			prg->philosophers[i].l_fork = &prg->philosophers[0].r_fork;
		else
			prg->philosophers[i].l_fork = &prg->philosophers[i + 1].r_fork;
		i++;
	}
	return (prg);
}

t_prg	*program_init(int argc, char **argv)
{
	int		i;
	t_prg	*prg;

	// TODO: deplacer ma statique de init_struct ici
	i = 0;
	prg = init_struct(argc, argv);
	return (prg);
}

int	main(int argc, char **argv)
{
	t_prg	*prg;
	int		i;

	i = 0;
	prg = NULL;
	if (argc == 5 || argc == 6)
	{
		prg = program_init(argc, argv);
		// printf("%i\n", prg->nb_of_philo);
		// thread_join(prg);
		// mutex_destroy(prg);
		while (i < prg->nb_of_philo)
		{
			key_logger(prg, &prg->philosophers[i], i);
			i++;
		}
	}
	else
		exit_prg_at_error("Invalid arguments");
	clean_process(prg);
	return (0);
}
