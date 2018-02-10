/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fork_abstract.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 09:26:53 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/10 09:49:29 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Fork_abstract.hpp"

							Fork_abstract::Fork_abstract(Client const &player) : m_player(player), m_pid(-1)
{
	
}