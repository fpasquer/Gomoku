/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fork_client.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 20:09:41 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/09 14:40:24 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Fork_client.hpp"

# define DEBUG

							Fork_client::Fork_client(int const &sock_client, int const &sock_server) : m_sock_client(sock_client) , m_sock_server(sock_server)
{
	srand(time(NULL));
}

bool						Fork_client::set_sock_client(int const &sock_client)
{
	if (sock_client <= 0)
		return (false);
	m_sock_client = sock_client;
	return (true);
}

bool						Fork_client::set_sock_server(int const &sock_server)
{
	if (sock_server <= 0)
		return (false);
	m_sock_server = sock_server;
	return (true);
}

ssize_t						Fork_client::read_from_client(void *data, size_t const &size) const
{
	ssize_t					ret;

	memset(data, 0, size);
	ret = read(m_sock_client, data, size);
	return (ret);
}

ssize_t						Fork_client::send_to_client(void *data, size_t const &size) const
{
	return (write(m_sock_client, data, size));
}

void						Fork_client::ia_playe(char grid[SIZE_GRID][SIZE_GRID], unsigned int &x, unsigned int &y) const
{
	do
	{
		x = rand() % SIZE_GRID;
		y = rand() % SIZE_GRID;
	}	while (grid[y][x] != EMPTY_CELL);
	Ia_player::play(grid, 6);
}

void						Fork_client::ia(void) const
{
	unsigned int			deep, x, y;
	char					grid[SIZE_GRID][SIZE_GRID];
	clock_t					start, end;
	double					time_spend;

	start = clock();
	this->read_from_client(&deep, sizeof(deep));
	this->read_from_client(&grid, sizeof(grid));
	start = clock();
	this->ia_playe(grid, x, y);
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
	this->send_to_client((void*)TIME_SPEND, SIZE_CMD);
	this->send_to_client(&time_spend, sizeof(time_spend));
	this->send_to_client(&y, sizeof(y));
	this->send_to_client(&x, sizeof(x));
}

void						Fork_client::run_loop(void) const
{
	char					buff[SIZE_CMD + 1];
	ssize_t					len;

	try
	{
		if (m_sock_server <= 0 || m_sock_server <= 0)
			throw Error("Unvalable sockets");
	}
	catch (std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
		exit(-1);
	}
	std::cout << "new_client[" << m_sock_client << "]" << std::endl;
	while (1)
	{
		if ((len = this->read_from_client(buff, SIZE_CMD)) > 0)
		{
			buff[len] = '\0';
			if (strcmp(buff, QUIT) == 0)
				this->~Fork_client();
			else if (strcmp(buff, IA) == 0)
				this->ia();
			else
				std::cout << buff << std::endl;
		}
	}
}

							Fork_client::~Fork_client(void)
{
	std::cout << "close_client[" << m_sock_client << "]" << std::endl;
	close(m_sock_client);
	kill(getpid(), SIGINT);
}
