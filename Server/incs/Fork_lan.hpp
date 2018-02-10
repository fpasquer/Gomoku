/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fork_lan.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 09:09:06 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/10 20:36:04 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORK_LAN_HPP
# define FORK_LAN_HPP

# include "Fork_abstract.hpp"
# include "Client.hpp"

class Fork_lan : public Fork_abstract
{
	public:
							Fork_lan(Client const &player, Client const &player2);

	protected:
		virtual void		run_loop(void) const;
		Client				m_player2;
};

#endif