/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 18:58:04 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/10 10:40:21 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Server.hpp"

int							Server::m_backlog = 50;

							Server::Server(int const &port) : m_port(port)
{
	struct protoent			*proto;
	struct sockaddr_in		addr;

	addr.sin_family = AF_INET;
	addr.sin_port = htons(m_port);
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	try
	{
		if ((proto = getprotobyname("tcp")) == NULL)
			throw Error("Proto failled");
		if ((m_sock_server = socket(PF_INET, SOCK_STREAM, proto->p_proto)) <= 0)
			throw Error("Socket failled");
		if (bind(m_sock_server, (const struct sockaddr *)&addr, sizeof(addr)) == -1)
			throw Error("Bind failled");
		if (listen(m_sock_server, Server::m_backlog))
			throw Error("Listen failled");
		
	}
	catch (std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
		exit(-1);
	}
}

int							Server::accept_client(void) const
{
	int						ret;
	struct sockaddr_in		addr;
	unsigned int			len;

	try
	{
		if ((ret = accept(m_sock_server, (struct sockaddr *)&addr, (socklen_t *)&len)) == -1)
			throw Error("Accept failed");
	}
	catch (std::exception const &e)
	{
		std::cerr << e.what() << " Pid = " << getpid() << " Sock_serv = " << m_sock_server <<std::endl;
		exit(-1);
	}
	return (ret);
}

int 						Server::get_sock_server(void) const
{
	return (m_sock_server);
}

							Server::~Server(void)
{
	close(m_sock_server);
}