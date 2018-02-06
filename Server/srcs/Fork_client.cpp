/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fork_client.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 20:09:41 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/06 20:34:56 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Fork_client.hpp"

							Fork_client::Fork_client(int const &sock_client, int const &sock_server) : m_sock_client(sock_client) , m_sock_server(sock_server)
{

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

void						Fork_client::run_loop(void) const
{
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
}

							Fork_client::~Fork_client(void)
{
	std::cout << "close_client[" << m_sock_client << "]" << std::endl;
}