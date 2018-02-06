/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 18:56:02 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/06 20:36:09 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
# define SERVER_HPP

# include "Error.hpp"
# include <iostream>
# include <sys/socket.h>
# include <netdb.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <unistd.h>
# include <vector>
# define BUFF_SIZE 100

class Server
{
	public:
							Server(int const &port);
		int					accept_client(void);
		int					get_sock_server(void) const;
							~Server(void);
		static int			m_backlog;

	private:
		std::vector <int>	m_list_sock_client;
		int					m_sock_server;
		int					m_port;
};

#endif