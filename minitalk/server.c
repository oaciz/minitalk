/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaciz <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:17:16 by oaciz             #+#    #+#             */
/*   Updated: 2022/05/31 15:17:19 by oaciz            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_usr(int sig)
{
	static char	str = 0;
	static int	get_byte = 0;

	if (sig == SIGUSR1)
		str = str | 1;
	if (++get_byte == 8)
	{
		get_byte = 0;
		ft_printf("%c", str);
		str = 0;
	}
	else
		str <<= 1;
}

int	main(void)
{
	ft_printf("pid = %d\n", getpid());
	signal(SIGUSR1, sig_usr);
	signal(SIGUSR2, sig_usr);
	while (1)
	{
		pause();
	}
	return (0);
}
