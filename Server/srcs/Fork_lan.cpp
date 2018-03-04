/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fork_lan.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 20:33:57 by fpasquer          #+#    #+#             */
/*   Updated: 2018/03/02 09:06:45 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Fork_lan.hpp"
#include <unistd.h>

							Fork_lan::Fork_lan(Client const &player, Client const &player2) : Fork_abstract(player), m_player2(player2)
{
	try
	{
		if ((m_pid = fork()) == -1)
			throw Error("Fork failled");
	}
	catch (std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
		exit(-1);
	}
	if (m_pid == 0)
		this->run_loop();
}

bool						Fork_lan::in_loop(Client const &src, Client const &dest) const
{
	unsigned int			x;
	unsigned int			y;
	char					buff[SIZE_CMD + 1];
	ssize_t					len;

	if ((len = src.read_from_client(buff, SIZE_CMD)) <= 0)
		return (false);
	buff[len] = '\0';
	len = src.read_from_client(&y, sizeof(y));
	len += src.read_from_client(&x, sizeof(x));
	if (len == 0)
	{
		dest.send_to_client((void*)QUIT, SIZE_CMD);
		return (false);
	}
	dest.send_to_client((void*)CONNECTED, SIZE_CMD);
	dest.send_to_client(&y, sizeof(y));
	dest.send_to_client(&x, sizeof(x));
	src.send_to_client((void*)CONNECTED2, SIZE_CMD);
	std::cout << "\tsrc[" << src.getSockClient() << "] x = " << x << " y = " << y << " to dest[" << dest.getSockClient()  << "]" << std::endl;
	return (true);
}

void						Fork_lan::run_loop(void)
{
	bool					ret1;
	bool					ret2;
	pid_t					pid = getpid();

	m_player.send_to_client((void*)CONNECTED, SIZE_CMD);
	m_player2.send_to_client((void*)CONNECTED2, SIZE_CMD);
	std::cout << "New Lan " << pid << ", Player [" << m_player.getSockClient() << "] vs Player[" << m_player2.getSockClient() << "]" <<std::endl;
	do
	{
		if ((ret1 = this->in_loop(m_player, m_player2)) == true)
			ret2 = this->in_loop(m_player2, m_player);
	} while (ret1 == true && ret2 == true);
	std::cout << "Close game[" << pid  << "]"<<std::endl;
	m_player.send_to_client((void*)QUIT, SIZE_CMD);
	m_player.send_to_client((void*)QUIT, SIZE_CMD);
	kill(getpid(), SIGINT);
}