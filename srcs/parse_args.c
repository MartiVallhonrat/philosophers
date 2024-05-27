/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvallhon <mvallhon@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:14:12 by mvallhon          #+#    #+#             */
/*   Updated: 2024/05/09 14:40:57 by mvallhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

static int	check_args(int argc, char *argv[])
{
	int	i;
	int	j;

	if (argc < 5)
		return (ft_putstr_fd("Too few arguments!\n", 2), 1);
	i = 0;
	while (argv[++i])
	{
		if (!argv[i][0] || (argv[i][0] == '0' && !argv[i][1]))
			return (ft_putstr_fd("Only natural digits are valid!\n", 2), 1);
		j = -1;
		while (argv[i][++j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (ft_putstr_fd("Only natural digits are valid!\n", 2), 1);
		}
	}
	return (0);
}

static int	set_philos(t_args *args, t_program *vars)
{
	t_philo	*aux;
	int		i;

	i = -1;
	while (++i < args->n_philo)
	{
		aux = vars->philos + i;
		philo_values(aux, i, vars, args);
	}
	pthread_mutex_lock(&vars->write_lock);
	ft_putstr_fd("📍 Simulation Started! 📍\n\n", 1);
	i = -1;
	pthread_mutex_unlock(&vars->write_lock);
	while (++i < args->n_philo)
	{
		aux = vars->philos + i;
		aux->start_time = get_current_time();
		aux->last_meal = aux->start_time;
		if (pthread_create(&aux->thread, NULL, &routine, aux))
			return (handle_all(vars), 1);
	}
	return (0);
}

static int	set_args(char *argv[], t_program *vars)
{
	t_args	args;
	int		i;

	i = 0;
	args.n_philo = ft_atoi(argv[++i]);
	args.time_die = ft_atoi(argv[++i]);
	args.time_eat = ft_atoi(argv[++i]);
	args.time_sleep = ft_atoi(argv[++i]);
	args.meals = ft_atoi(argv[++i]);
	vars->dead_flag = 0;
	pthread_mutex_init(&vars->dead_lock, NULL);
	pthread_mutex_init(&vars->meal_lock, NULL);
	pthread_mutex_init(&vars->write_lock, NULL);
	vars->philos = ft_calloc((args.n_philo + 1), sizeof(t_philo));
	if (!(vars->philos) || set_philos(&args, vars))
		return (perror("Philosophers"), 1);
	return (0);
}

int	parse_args(int argc, char *argv[], t_program *vars)
{
	if (check_args(argc, argv))
		return (1);
	if (set_args(argv, vars))
		return (1);
	return (0);
}
