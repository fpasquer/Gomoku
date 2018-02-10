/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fork_ia.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 09:26:10 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/10 11:53:07 by fpasquer         ###   ########.fr       */
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
		this->run_loop(player);
}

void						Fork_ia::play_ia(Client const &player) const
{
	unsigned int			x;
	unsigned int			y;
	unsigned int			depth;
	char					grid[SIZE_GRID][SIZE_GRID];
	clock_t					start, end;
	double					time_spend;

	player.read_from_client(&depth, sizeof(depth));
	player.read_from_client(&grid, sizeof(grid));
	start = clock();
	Ia_player::play(grid, depth, x, y);
	end = clock();
	time_spend = ((double) (end - start)) / CLOCKS_PER_SEC;
#ifdef DEBUG
	std::cout << "deep client[" << m_sock_client << "] = " << deep << ", x = " << x << " y = " << y <<std::endl;
	unsigned int			i, j;
	for (i = 0; i < SIZE_GRID; i++)
	{
		for (j = 0; j < SIZE_GRID; j++)
			std::cout << grid[i][j];
		std::cout << std::endl;
	}
#endif
	player.send_to_client((void*)TIME_SPEND, SIZE_CMD);
	player.send_to_client(&time_spend, sizeof(time_spend));
	player.send_to_client(&y, sizeof(y));
	player.send_to_client(&x, sizeof(x));
}

void						Fork_ia::run_loop(Client const &player) const
{
	pid_t					pid;
	char					buff[SIZE_CMD + 1];
	ssize_t					len;

	pid = getpid();
	std::cout << "New player["<< pid <<"] vs ia" <<std::endl;
	player.send_to_client((void*)CONNECTED, SIZE_CMD);
	while ((len = player.read_from_client(buff, SIZE_CMD)) > 0)
	{
		buff[len] = '\0';
		if (strcmp(buff, QUIT) == 0)
			break ;
		if (strcmp(buff, IA) == 0)
			this->play_ia(player);
		else
			std::cout << buff << std::endl;
	}
	std::cout << "Close player["<< pid <<"] vs ia"<<std::endl;
	kill(getpid(), SIGINT);
}