/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvallhon <mvallhon@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:17:09 by mvallhon          #+#    #+#             */
/*   Updated: 2024/05/06 19:43:53 by mvallhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

static void	do_eat(t_philo *philo)
{
	if (philo->l_fork == NULL)
	{
		pthread_mutex_lock(philo->dead_lock);
		ft_usleep(philo->time_die);
		pthread_mutex_unlock(philo->dead_lock);
		ft_usleep(1);
		return ;
	}
	pthread_mutex_lock(&philo->r_fork);
	pthread_mutex_lock(philo->l_fork);
	print_action("🍴 Philo eating! 🍴\n", philo);
	pthread_mutex_lock(philo->meal_lock);
	philo->last_meal = get_current_time();
	(philo->meals_eaten)++;
	pthread_mutex_unlock(philo->meal_lock);
	ft_usleep(philo->time_eat);
	pthread_mutex_unlock(&philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

static void	do_sleep(t_philo *philo)
{
	print_action("😴 Philo sleeping! 😴\n", philo);
	ft_usleep(philo->time_sleep);
}

static void	do_think(t_philo *philo)
{
	print_action("🤔 Philo thinking! 🤔\n", philo);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2)
		ft_usleep(1);
	while (1)
	{
		do_eat(philo);
		do_sleep(philo);
		do_think(philo);
	}
	return (0);
}
