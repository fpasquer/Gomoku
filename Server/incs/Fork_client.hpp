/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fork_client.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 20:07:13 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/06 20:33:19 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORK_CLIENT_HPP
# define FORK_CLIENT_HPP

# include "Error.hpp"
# include <iostream>

# define INIT_SOCK -1

class Fork_client
{
	public:
							Fork_client(int const &sock_client = INIT_SOCK, int const &sock_server = INIT_SOCK);
		bool				set_sock_client(int const &sock_client);
		bool				set_sock_server(int const &sock_server);
		void				run_loop(void) const;
							~Fork_client(void);

	private:
		int					m_sock_client;
		int					m_sock_server;
};

#endif