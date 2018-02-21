/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fork_ia.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 09:26:10 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/21 13:30:16 by amaindro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Fork_ia.hpp"

							Fork_ia::Fork_ia(Client const &player) : Fork_abstract(player)
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

void						Fork_ia::play_ia(void) const
{
	unsigned int			x;
	unsigned int			y;
	unsigned int			depth;
	short					grid[SIZE_GRID][SIZE_GRID];
	clock_t					start, end;
	double					time_spend;

	m_player.read_from_client(&depth, sizeof(depth));
	m_player.read_from_client(&grid, sizeof(grid));
	start = clock();
	Ia_player::play(grid, depth, x, y);
	std::cout << "x :" << x << " y :" << y <<std::endl;
	end = clock();
	time_spend = ((double) (end - start)) / CLOCKS_PER_SEC;
#ifdef DEBUG
	std::cout << "deep client[" << getpid() << "] = " << deep << ", x = " << x << " y = " << y <<std::endl;
	unsigned int			i, j;
	for (i = 0; i < SIZE_GRID; i++)
	{
		for (j = 0; j < SIZE_GRID; j++)
			std::cout << grid[i][j];
		std::cout << std::endl;
	}
#endif
	m_player.send_to_client((void*)TIME_SPEND, SIZE_CMD);
	m_player.send_to_client(&time_spend, sizeof(time_spend));
	m_player.send_to_client(&y, sizeof(y));
	m_player.send_to_client(&x, sizeof(x));
}

void						Fork_ia::run_loop(void) const
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
