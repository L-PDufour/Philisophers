/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 08:08:39 by ldufour           #+#    #+#             */
/*   Updated: 2023/11/23 08:57:24 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stddef.h>
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
	pthread_mutex_t	r_fork;
	pthread_mutex_t	*l_fork;
}					t_philosophers;

typedef struct s_prg
{
	int				nb_of_philo;
	int				nb_of_meals;
	long			time;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	pthread_t		*threads;
	t_philosophers	*philosophers;
}					t_prg;
// Functions

void				parsing_arguments(t_prg *philo, int argc, char **argv);
void				thread_init(t_prg *prg, int argc, char **argv);
// Utils

void				exit_prg_at_error(char *str);
void				*safe_malloc(size_t bytes);

#endif
