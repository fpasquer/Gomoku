/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 08:02:55 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/10 10:42:26 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Client.hpp"
#include <unistd.h>

							Client::Client(void) : m_sock_client(INIT_SOCK), m_sock_server(INIT_SOCK), m_type_client("")
{
	
}

void						Client::setNewClient(Server const &server)
{
	char					buff[SIZE_CMD + 1];
	ssize_t					len;

	m_sock_client = server.accept_client();
	m_sock_server = server.get_sock_server();
	len = this->read_from_client(buff, sizeof(buff));
	buff[len] = '\0';
	m_type_client = buff;
}

std::string					Client::getTypeClient(void) const
{
	return (m_type_client);
}

void						Client::sendError(void) const
{
	this->send_to_client((void*)ERROR, SIZE_CMD);
}

int							Client::getSockClient(void) const
{
	return (m_sock_client);
}

int							Client::getSockServer(void) const
{
	return (m_sock_server);
}

ssize_t						Client::read_from_client(void *data, size_t const &size) const
{
	ssize_t					ret;

	memset(data, 0, size);
	ret = read(m_sock_client, data, size);
	return (ret);
}

ssize_t						Client::send_to_client(void *data, size_t const &size) const
{
	return (write(m_sock_client, data, size));
}

							Client::~Client(void)
{
	close(m_sock_client);
}