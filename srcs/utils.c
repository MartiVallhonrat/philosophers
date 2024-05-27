/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvallhon <mvallhon@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 13:17:41 by mvallhon          #+#    #+#             */
/*   Updated: 2024/05/09 14:26:39 by mvallhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < milliseconds)
		usleep(500);
	return (0);
}

int	check_meals(t_philo *philos)
{
	int		i;
	t_philo	*philo;

	i = -1;
	while (++i < philos->n_philos)
	{
		philo = philos + i;
		pthread_mutex_lock(philo->meal_lock);
		if (philo->meals_eaten < philo->meals)
		{
			pthread_mutex_unlock(philo->meal_lock);
			return (0);
		}
		pthread_mutex_unlock(philo->meal_lock);
	}
	pthread_mutex_lock(philo->dead_lock);
	*(philos->dead) = 1;
	pthread_mutex_unlock(philo->dead_lock);
	return (1);
}

void	print_action(char *str, t_philo *philo)
{
	char	*time;
	char	*id;

	pthread_mutex_lock(philo->dead_lock);
	pthread_mutex_lock(philo->write_lock);
	if (*(philo->dead))
	{
		pthread_mutex_unlock(philo->write_lock);
		pthread_mutex_unlock(philo->dead_lock);
		return ;
	}
	pthread_mutex_unlock(philo->dead_lock);
	time = ft_litoa(get_current_time() - philo->start_time);
	id = ft_itoa(philo->id);
	ft_putstr_fd(time, 1);
	free(time);
	ft_putstr_fd(" - ", 1);
	ft_putstr_fd(id, 1);
	free(id);
	ft_putstr_fd("  ", 1);
	ft_putstr_fd(str, 1);
	ft_putstr_fd("\n", 1);
	pthread_mutex_unlock(philo->write_lock);
}
