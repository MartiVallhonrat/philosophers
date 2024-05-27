/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvallhon <mvallhon@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 12:24:50 by mvallhon          #+#    #+#             */
/*   Updated: 2024/05/06 19:35:09 by mvallhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

static void	print_die(char *str, t_philo *philo)
{
	char	*time;
	char	*id;

	pthread_mutex_lock(philo->write_lock);
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
}

static int	check_dead(t_program *vars)
{
	int		i;
	t_philo	*philo;

	i = -1;
	while (++i < vars->philos->n_philos)
	{
		philo = vars->philos + i;
		pthread_mutex_lock(philo->dead_lock);
		pthread_mutex_lock(philo->meal_lock);
		if (get_current_time() - philo->last_meal > philo->time_die)
		{
			pthread_mutex_unlock(philo->meal_lock);
			pthread_mutex_unlock(philo->dead_lock);
			pthread_mutex_lock(philo->dead_lock);
			*(philo->dead) = 1;
			pthread_mutex_unlock(philo->dead_lock);
			print_die("💀 Philo died! 💀\n", philo);
			pthread_mutex_unlock(philo->write_lock);
			return (1);
		}
		pthread_mutex_unlock(philo->meal_lock);
		pthread_mutex_unlock(philo->dead_lock);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_program	vars;

	if (parse_args(argc, argv, &vars))
		return (1);
	while (1)
	{
		if ((vars.philos->meals != -1 && check_meals(vars.philos))
			|| check_dead(&vars))
			break ;
	}
	ft_usleep(2000);
	handle_all(&vars);
	ft_putstr_fd("📍 Simulation Ended! 📍\n", 1);
	return (0);
}
