/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 08:30:18 by ldufour           #+#    #+#             */
/*   Updated: 2024/01/18 10:53:13 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
#include <pthread.h>
#include <unistd.h>

void	*dispatch(void *arg);
void	key_logger(t_data *data, t_state state, int number)
{
	pthread_mutex_lock(&data->print);
	data->time = timeInMilliseconds();
	if (state == EAT)
		printf("%li philosopher[%i] is eating\n", data->time, number);
	else if (state == DIE)
		printf("%li philosopher[%i] died\n", data->time, number);
	else if (state == SLEEP)
		printf("%li philosopher[%i] is sleeping\n", data->time, number);
	else if (state == FORKING)
		printf("%li philosopher[%i] has taken a fork\n", data->time, number);
	else if (state == THINK)
		printf("%li philosopher[%i] is thinking\n", data->time, number);
	else
		printf("%li philosopher[%i] is testin\n", data->time, number);
	pthread_mutex_unlock(&data->print);
}

void	dinner_start(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_of_philo)
	{
		pthread_create(&data->philo->threads, NULL, dispatch, &data);
		i++;
	}
	i = 0;
	while (i < data->nb_of_philo)
	{
		pthread_join(data->philo->threads, NULL);
		i++;
	}
}
// TODO: Je ne suis pas sur de bien faire ma routine. dispatch & dinner_start
void	*dispatch(void *arg)
{
	t_data	*data;
	int		i;
	t_state	state;

	data = (t_data *)arg;
	i = 0;
	// if (i == 0)
	// {
	pthread_mutex_lock(&data->philo[0].r_fork);
	pthread_mutex_lock(data->philo[0].l_fork);
	key_logger(data, EAT, 0);
	usleep(data->time_to_eat);
	pthread_mutex_unlock(&data->philo[0].r_fork);
	pthread_mutex_unlock(data->philo[0].l_fork);
	// }
	key_logger(data, SLEEP, i);
	return (NULL);
}

void	clean_process(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_of_philo)
	{
		safe_mutex_handle(&data->philo[i].r_fork, DESTROY);
		i++;
	}
	safe_mutex_handle(&data->print, DESTROY);
	free(data->philo);
	free(data);
}

void	philo_init(t_data *data)
{
	int		i;
	t_philo	*philo;

	i = 0;
	while (i < data->nb_of_philo)
	{
		philo = &data->philo[i];
		philo->full = false;
		philo->dead = false;
		safe_mutex_handle(&philo->r_fork, INIT);
		if (i == data->nb_of_philo - 1)
			philo->l_fork = &data->philo[0].r_fork;
		else
			philo->l_fork = &data->philo[i + 1].r_fork;
		i++;
	}
}

void	struct_setup(t_data *data, int argc, char **argv)
{
	parsing_arguments(data, argc, argv);
	data->philo = (t_philo *)safe_malloc(sizeof(t_philo) * data->nb_of_philo);
	data->start_thread = false;
	data->end_time = false;
	philo_init(data);
}

t_data	*init_struct(void)
{
	static t_data	*data;
	int				i;

	i = 0;
	data = NULL;
	if (!data)
		data = safe_malloc(sizeof(t_data));
	return (data);
}

void	program_init(int argc, char **argv)
{
	int		i;
	t_data	*data;

	i = 0;
	data = init_struct();
	struct_setup(data, argc, argv);
	print_philo_info(data);
	dinner_start(data);
	clean_process(data);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 5 || argc == 6)
		program_init(argc, argv);
	else
		exit_prg_at_error("Invalid arguments");
	return (0);
}
/*
*	void philo_is_eating(t_data *data)
*	{
*		if (data->philo[i])
*			if (data->fork[i] == unlock && prg->fork[i + 1] ==
unlock) *				data->fork[i] == lock *
data->fork[i + 1] == lock *				printf (i is eating)
*				usleep(time_to_eat)
*				data->fork[i] == unlock
*				data->fork[i + 1] == unlock
*			philo[i + 1] must sleep time_to_sleep
*			if fork lock than think and wait
*			check if philo is not dead (time_before_last_meal)
*			if (nbr_of_meals) check if nbr of meals == 0
(nbr_of_meals--) *			check if philo can eat (fork lock) else
think and wait *			if eated then check for sleep


}
*
*/
