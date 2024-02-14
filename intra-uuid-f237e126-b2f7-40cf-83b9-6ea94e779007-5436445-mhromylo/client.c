/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhromylo <mhromylo@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:30:48 by mhromylo          #+#    #+#             */
/*   Updated: 2024/01/26 15:30:20 by mhromylo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	g_receiver;

void	sig_handler(int signum, siginfo_t *info, void *context)
{
	static int	i;

	(void)context;
	(void)info;
	(void)signum;
	g_receiver = 1;
	if (signum == SIGUSR2)
		i++;
	else if (signum == SIGUSR1)
		ft_printf("%d", i / 8);
}

int	char_to_bin(char c, int pid)
{
	int	itr;
	int	bit_index;

	bit_index = 7;
	while (bit_index >= 0)
	{
		itr = 0;
		if ((c >> bit_index) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (g_receiver == 0)
		{
			if (itr == 50)
			{
				ft_printf("No response from server");
				exit(1);
			}
			itr++;
			usleep(100);
		}
		g_receiver = 0;
		bit_index--;
	}
	return (0);
}

int	main(int argc, char const *argv[])
{
	struct sigaction	sact;
	int					byte_index;
	int					pid;

	if (argc != 3)
	{
		ft_printf("Pass please 2 argc");
		return (1);
	}
	byte_index = 0;
	pid = ft_atoi(argv[1]);
	sigemptyset(&sact.sa_mask);
	sact.sa_flags = SA_RESTART | SA_SIGINFO;
	sact.sa_sigaction = sig_handler;
	if (sigaction(SIGUSR1, &sact, NULL) == -1)
		ft_printf("Error sigaction\n");
	if (sigaction(SIGUSR2, &sact, NULL) == -1)
		ft_printf("Error sigaction\n");
	while (argv[2][byte_index])
		char_to_bin(argv[2][byte_index++], pid);
	char_to_bin('\0', pid);
	return (0);
}
