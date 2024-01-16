/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 08:08:39 by ldufour           #+#    #+#             */
/*   Updated: 2024/01/16 15:08:29 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <limits.h>
#include <pthread.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>

typedef enum e_state {
  DIE,
  EAT,
  SLEEP,
  THINK,
  FORKING,
} t_state;

typedef struct s_philosophers {
  pthread_mutex_t r_fork;
  pthread_mutex_t *l_fork;
  pthread_t *threads;
  t_state state;
} t_philosophers;

typedef struct s_prg {
  int nb_of_philo;
  int nb_of_meals;
  long time;
  long time_to_die;
  long time_to_eat;
  long time_to_sleep;
  pthread_mutex_t print;
  t_philosophers *philosophers;
} t_prg;

// Functions
void parsing_arguments(t_prg *philo, int argc, char **argv);

t_prg *thread_init(int argc, char **argv);
// utils
void exit_prg_at_error(char *str);
void *safe_malloc(size_t bytes);

#endif
