/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhromylo <mhromylo@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:47:13 by mhromylo          #+#    #+#             */
/*   Updated: 2024/01/26 14:02:32 by mhromylo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_signal(int signal, siginfo_t *info, void *context)
{
	static unsigned char	cur_char;
	static int				bit_index;

	(void)context;
	cur_char |= (signal == SIGUSR1);
	bit_index++;
	if (bit_index == 8)
	{
		if (cur_char == '\0')
			ft_printf("\n");
		else
			ft_printf("%c", cur_char);
		bit_index = 0;
		cur_char = 0;
	}
	else
		cur_char <<= 1;
	if (signal == SIGUSR1)
		kill(info->si_pid, SIGUSR1);
	else if (signal == SIGUSR2)
		kill(info->si_pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	sact;

	sact.sa_sigaction = &handle_signal;
	sact.sa_flags = SA_SIGINFO;
	sigemptyset(&sact.sa_mask);
	printf("%d\n", getpid());
	sigaction(SIGUSR1, &sact, NULL);
	sigaction(SIGUSR2, &sact, NULL);
	while (1)
		pause();
	return (0);
}
