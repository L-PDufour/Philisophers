/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:58:29 by ldufour           #+#    #+#             */
/*   Updated: 2024/01/17 14:06:49 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long long	timeInMilliseconds(void)
{
	static struct timeval	start;
	struct timeval			end;

	start.tv_sec = 0;
	start.tv_usec = 0;
	if (start.tv_sec == 0 && start.tv_usec == 0)
		gettimeofday(&start, NULL);
	gettimeofday(&end, NULL);
	return (((long long)end.tv_sec) * 1000 + (end.tv_usec / 1000)) -
		(((long long)start.tv_sec) * 1000 + (start.tv_usec / 1000));
}

long long	timeInMicroseconds(void)
{
	static struct timeval	start;
	struct timeval			end;

	start.tv_sec = 0;
	start.tv_usec = 0;
	if (start.tv_sec == 0 && start.tv_usec == 0)
		gettimeofday(&start, NULL);
	gettimeofday(&end, NULL);
	return ((long long)(end.tv_sec - start.tv_sec) * 1000000LL +
			(end.tv_usec - start.tv_usec));
}

void	precise_usleep(long usec, t_data *data)
{
	long	start;
	long	elasped;
	long	rem;

	start = timeInMicroseconds();
	while (timeInMicroseconds() - start < usec)
	{
		elasped = timeInMicroseconds() - start;
		rem = usec - elasped;
		if (rem > 1000)
			usleep(rem / 2);
		else
			while (timeInMicroseconds() - start < usec)
				;
	}
}
