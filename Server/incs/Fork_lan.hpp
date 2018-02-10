/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fork_lan.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 09:09:06 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/10 09:17:04 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORK_LAN_HPP
# define FORK_LAN_HPP

# include "Fork_abstract.hpp"
# include "Client.hpp"

class Fork_lan : public Fork_abstract
{
	public:
							Fork_lan(Client *player1, Client const &player2);
};

#endif