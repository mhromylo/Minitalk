/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhromylo <mhromylo@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:33:04 by mhromylo          #+#    #+#             */
/*   Updated: 2024/01/26 14:04:04 by mhromylo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	bin_to_char(int signum, char *c)
{
	if (signum == SIGUSR1)
		*c = (*c << 1) | 1;
	else if (signum == SIGUSR2)
		*c <<= 1;
}

void	sig_handler(int signum, siginfo_t *info, void *context)
{
	static int	pid;
	static int	i;
	static char	c;

	(void)context;
	if (pid == 0)
		pid = info->si_pid;
	bin_to_char(signum, &c);
	if (++i == 8)
	{
		i = 0;
		if (!c)
		{
			kill(pid, SIGUSR1);
			pid = 0;
			return ;
		}
		ft_printf("%c", c);
		c = 0;
	}
	kill(pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	sact;

	ft_printf("PID %d'\n", getpid());
	sigemptyset(&sact.sa_mask);
	sact.sa_flags = SA_RESTART | SA_SIGINFO;
	sact.sa_sigaction = sig_handler;
	if (sigaction(SIGUSR1, &sact, NULL) == -1)
		ft_printf("Error sigaction\n");
	if (sigaction(SIGUSR2, &sact, NULL) == -1)
		ft_printf("Error sigaction\n");
	while (1)
		pause();
	return (0);
}
