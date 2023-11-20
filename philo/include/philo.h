/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 08:08:39 by ldufour           #+#    #+#             */
/*   Updated: 2023/11/20 10:43:43 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

// STRUCT
// //
// typedef enum time
// {
// 	DIE,
// 	EAT,
// 	SLEEP,
// };
typedef struct s_philosophers
{
	pthread_mutex_t	*fork;

}					t_philosophers;

typedef struct s_prg
{
	int				nb_of_philo;
	int				nb_of_meals;
	long long		time;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	pthread_mutex_t	*fork; 
	pthread_t *philo;
	// t_philosophers	*philosophers;
}					t_prg;
#endif
