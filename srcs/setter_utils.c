/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setter_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvallhon <mvallhon@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 18:37:50 by mvallhon          #+#    #+#             */
/*   Updated: 2024/05/06 18:23:45 by mvallhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

static void	set_forks(t_philo *aux)
{
	if (aux->id == 0)
	{
		pthread_mutex_init(&aux->r_fork, NULL);
		aux->l_fork = NULL;
	}
	else if (aux->id == (aux->n_philos - 1))
	{
		pthread_mutex_init(&aux->r_fork, NULL);
		aux->l_fork = &(aux - 1)->r_fork;
		(aux - (aux->n_philos - 1))->l_fork = &aux->r_fork;
	}
	else
	{
		pthread_mutex_init(&aux->r_fork, NULL);
		aux->l_fork = &(aux - 1)->r_fork;
	}
}

void	philo_values(t_philo *aux, int i, t_program *vars, t_args *args)
{
	aux->id = i;
	aux->eating = 0;
	aux->last_meal = 0;
	aux->time_die = args->time_die;
	aux->time_eat = args->time_eat;
	aux->time_sleep = args->time_sleep;
	aux->n_philos = args->n_philo;
	if (args->meals)
		aux->meals = args->meals;
	else
		aux->meals = -1;
	aux->dead = &vars->dead_flag;
	set_forks(aux);
	aux->write_lock = &vars->write_lock;
	aux->dead_lock = &vars->dead_lock;
	aux->meal_lock = &vars->meal_lock;
}
