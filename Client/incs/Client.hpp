/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 20:56:39 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/07 09:28:38 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_HPP
# define CLIENT_HPP

# include <string>
# include <sys/socket.h>
# include <netdb.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include "Error.hpp"
# include <iostream>
# include <unistd.h>
# include "Gomoku_client.hpp"
# include "../../Gomoku.hpp"

class Client
{
	public:
		static std::string	localhost_str;
		static std::string	localhost_ipv4;
							Client(std::string const &addr, int const &port);
		ssize_t				send_to_server(void const *data, size_t const &len) const;
		ssize_t				read_from_server(void *data, size_t const &len) const;
							~Client(void);
	private:
		std::string			m_addr;
		int					m_port;
		int					m_sock_client;
};

#endif