/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fork_ia.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 09:26:10 by fpasquer          #+#    #+#             */
/*   Updated: 2018/03/02 09:29:18 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Fork_ia.hpp"

							Fork_ia::Fork_ia(Client const &player) : Fork_abstract(player), m_grid()
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

void						Fork_ia::play_ia(void)
{
	unsigned int			x;
	unsigned int			y;
	clock_t					start, end;
	double					time_spend;

	m_grid.updateInfoGrid(m_player);
	start = clock();
	Ia_player::play(m_grid.m_cell, x, y, m_grid.getDepth(), m_grid.getNbCapturePlayer(), m_grid.getNbCaptureIa());
	end = clock();
	time_spend = ((double) (end - start)) / CLOCKS_PER_SEC;
	m_player.send_to_client((void*)TIME_SPEND, SIZE_CMD);
	m_player.send_to_client(&time_spend, sizeof(time_spend));
	m_player.send_to_client(&y, sizeof(y));
	m_player.send_to_client(&x, sizeof(x));
	std::cout << __FILE__ << " " << __LINE__  << " y = " << y << " x = " << x << std::endl;
}

void						Fork_ia::run_loop(void)
{
	pid_t					pid = getpid();
	char					buff[SIZE_CMD + 1];
	ssize_t					len;

	std::cout << "New player[" << pid  << "] vs ia" <<std::endl;
	m_player.send_to_client((void*)CONNECTED, SIZE_CMD);
	while ((len = m_player.read_from_client(buff, SIZE_CMD)) > 0)
	{
		buff[len] = '\0';
		if (strcmp(buff, QUIT) == 0)
			break ;
		if (strcmp(buff, IA) == 0)
			this->play_ia();
		else
			std::cout << buff << std::endl;
	}
	std::cout << "Close player[" << pid  << "] vs ia"<<std::endl;
	kill(getpid(), SIGINT);
}
