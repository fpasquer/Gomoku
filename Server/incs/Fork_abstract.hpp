/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fork_abstract.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 09:10:21 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/10 20:29:04 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORK_ABSTRACT_HPP
# define FORK_ABSTRACT_HPP

# include "Client.hpp"
# include <unistd.h>
# include <iostream>

class Fork_abstract
{
	public:
							Fork_abstract(Client const &player);

	protected:
		virtual void		run_loop(void) const = 0;
		Client				m_player;
		pid_t				m_pid;
};

#endif