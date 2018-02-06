/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 20:56:39 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/06 21:32:08 by fpasquer         ###   ########.fr       */
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

class Client
{
	public:
		static std::string	localhost_str;
		static std::string	localhost_ipv4;
							Client(std::string const &addr, int const &port);
							~Client(void);
	private:
		std::string			m_addr;
		int					m_port;
		int					m_sock_client;
};

#endif