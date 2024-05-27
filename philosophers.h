/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvallhon <mvallhon@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 12:43:30 by mvallhon          #+#    #+#             */
/*   Updated: 2024/05/06 19:37:37 by mvallhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <errno.h>
# include <pthread.h>
# include <sys/time.h>
# include "libs/libft/libft.h"

typedef pthread_mutex_t	t_mtx;

typedef struct s_args
{
	int	n_philo;
	int	time_die;
	int	time_eat;
	int	time_sleep;
	int	meals;
}		t_args;

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	size_t			eating;
	int				meals_eaten;
	size_t			last_meal;
	size_t			time_die;
	size_t			time_eat;
	size_t			time_sleep;
	size_t			start_time;
	int				n_philos;
	int				meals;
	int				*dead;
	t_mtx			r_fork;
	t_mtx			*l_fork;
	t_mtx			*write_lock;
	t_mtx			*dead_lock;
	t_mtx			*meal_lock;
}					t_philo;

typedef struct s_program
{
	int			dead_flag;
	t_mtx		dead_lock;
	t_mtx		meal_lock;
	t_mtx		write_lock;
	t_philo		*philos;
}				t_program;

//parse
int		parse_args(int argc, char *argv[], t_program *vars);
void	philo_values(t_philo *aux, int i, t_program *vars, t_args *args);

//utils
size_t	get_current_time(void);
int		ft_usleep(size_t milliseconds);
int		check_meals(t_philo *philos);
void	print_action(char *str, t_philo *philo);
char	*ft_litoa(long int n);

//routine
void	*routine(void *arg);

//handle errors
void	handle_philos(t_philo *philos);
void	handle_mtx(t_program *vars);
void	handle_all(t_program *vars);

#endif
