/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvallhon <mvallhon@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 18:37:12 by mvallhon          #+#    #+#             */
/*   Updated: 2024/05/06 17:18:16 by mvallhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	handle_philos(t_philo *philos)
{
	int		i;
	t_philo	*aux;

	i = -1;
	while (++i < philos->n_philos)
	{
		aux = philos + i;
		pthread_detach(aux->thread);
	}
	free(philos);
}

void	handle_mtx(t_program *vars)
{
	pthread_mutex_destroy(&vars->dead_lock);
	pthread_mutex_destroy(&vars->meal_lock);
	pthread_mutex_destroy(&vars->write_lock);
}

void	handle_all(t_program *vars)
{
	handle_philos(vars->philos);
	handle_mtx(vars);
}
