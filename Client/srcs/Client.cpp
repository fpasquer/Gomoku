/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 21:10:26 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/11 14:13:20 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Client.hpp"

std::string					Client::localhost_str = "localhost";
std::string					Client::localhost_ipv4 = "127.0.0.1";

							Client::Client(void) : m_connected(false), m_addr(""), m_port(0)
{
	
}

int							Client::getSockClient(void) const
{
	return (m_sock_client);
}

							Client::Client(std::string const &ip, int const &port) : m_connected(false), m_addr(ip), m_port(port)
{
	this->connect_to_server();
}

bool						Client::set_addr(std::string const &ip)
{
	char					dest[INET_ADDRSTRLEN];

	if (inet_pton(AF_INET, ip.c_str(), &dest) != 1)
		return (false);
	if ((m_addr = ip) == Client::localhost_str)
		m_addr = Client::localhost_ipv4;
	return (true);	
}

bool						Client::set_port(int const &port)
{
	if (port < MIN_PORT || port > MAX_PORT)
		return (false);
	m_port = port;
	return (true);
}

void						Client::connect_to_server(void)
{
	char					dest[INET_ADDRSTRLEN];
	struct protoent			*proto;
	struct sockaddr_in		addr;

	addr.sin_family = AF_INET;
	addr.sin_port = htons(m_port);
	addr.sin_addr.s_addr = inet_addr(m_addr.c_str());
	try
	{
		if (inet_pton(AF_INET, m_addr.c_str(), &dest) != 1)
			throw Error("Unvalable addr");
		if (m_port < MIN_PORT || m_port > MAX_PORT)
			throw Error("Unvalable port");
		if ((proto = getprotobyname("tcp")) == NULL)
			throw Error("Proto failled");
		if ((m_sock_client = socket(PF_INET, SOCK_STREAM, proto->p_proto)) <= 0)
			throw Error("Socket failled"); 
		if (connect(m_sock_client, (const struct sockaddr *)&addr, sizeof(addr)) == -1)
			throw Error("Connect failled");
	}
	catch (std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
		exit(-1);
	}
	m_connected = true;
}

bool						Client::connected(void) const
{
	return (m_connected);
}

ssize_t						Client::send_to_server(void const *data, size_t const &len) const
{
	return (write(m_sock_client, data, len));
}

ssize_t						Client::read_from_server(void *data, size_t const &len) const
{
	memset(data, 0, len);
	return (read(m_sock_client, data, len));
}

							Client::~Client(void)
{
	if (this->connected() == false)
		return ;
	this->send_to_server(QUIT, SIZE_CMD);
	close(m_sock_client);
}