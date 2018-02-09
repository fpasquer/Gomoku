/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fork_client.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 20:07:13 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/09 14:39:37 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORK_CLIENT_HPP
# define FORK_CLIENT_HPP

# include "Error.hpp"
# include <iostream>
# include <unistd.h>
# include "../../Gomoku.hpp"
# include <time.h>
# include <signal.h>
# include "ia_player.hpp"
 
# define INIT_SOCK -1
# define SIZE_BUFF_READ 1000

class Fork_client
{
	public:
							Fork_client(int const &sock_client = INIT_SOCK, int const &sock_server = INIT_SOCK);
		bool				set_sock_client(int const &sock_client);
		bool				set_sock_server(int const &sock_server);
		void				ia(void) const;
		void				ia_playe(char grid[SIZE_GRID][SIZE_GRID], unsigned int &x, unsigned int &y) const;
		ssize_t				read_from_client(void *data, size_t const &size) const;
		ssize_t				send_to_client(void *data, size_t const &size) const;
		void				run_loop(void) const;
							~Fork_client(void);

	private:
		int					m_sock_client;
		int					m_sock_server;
};

#endif
