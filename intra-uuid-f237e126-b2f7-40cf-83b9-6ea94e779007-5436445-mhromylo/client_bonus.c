/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhromylo <mhromylo@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:31:56 by mhromylo          #+#    #+#             */
/*   Updated: 2024/01/26 15:35:32 by mhromylo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_sender(int pid, unsigned char c)
{
	int				i;
	unsigned char	temp;

	i = 8;
	temp = c;
	while (i > 0)
	{
		i--;
		temp = c >> i;
		if (temp % 2 == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(420);
	}
}

void	answer_signal(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("Received bit 1\n");
	else if (signal == SIGUSR2)
		ft_printf("Received bit 0\n");
}

int	main(int argc, char const *argv[])
{
	pid_t		serv_pid;
	const char	*m;
	int			i;

	signal(SIGUSR1, answer_signal);
	signal(SIGUSR2, answer_signal);
	if (argc != 3)
	{
		ft_printf("Usage: %s <pid> <message>\n", argv[0]);
		exit(0);
	}
	serv_pid = ft_atoi(argv[1]);
	m = argv[2];
	i = 0;
	while (m[i])
	{
		signal_sender(serv_pid, m[i]);
		i++;
	}
	signal_sender(serv_pid, '\0');
	return (0);
}
