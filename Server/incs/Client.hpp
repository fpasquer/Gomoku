/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 07:57:33 by fpasquer          #+#    #+#             */
/*   Updated: 2018/03/01 14:59:27 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_HPP
# define CLIENT_HPP

# include "../../Tools_incs/Gomoku.hpp"
# include "Server.hpp"

class Client
{
	public:
							Client(void);
		void				setNewClient(Server const &server);
		int					getSockClient(void) const;
		int					getSockServer(void) const;
		std::string			getTypeClient(void) const;
		void				sendError(void) const;
							~Client(void);
		ssize_t				read_from_client(void *data, size_t const &size) const;
		ssize_t				send_to_client(void *data, size_t const &size) const;
		ssize_t				send_to_server(void *data, size_t const &size) const;

	private:
		int					m_sock_client;
		int					m_sock_server;
		std::string			m_type_client;
};

#endif