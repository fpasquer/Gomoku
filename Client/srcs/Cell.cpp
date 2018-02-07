/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cell.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 21:20:06 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/07 11:04:38 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Cell.hpp"

							Cell::Cell(void) : m_val(EMPTY_CELL)
{
	
}

bool						Cell::setVal(Player const &player)
{
	if (m_val != EMPTY_CELL)
		return (false);
	m_val = player.getValue();
	return (true);
}

bool						Cell::setVal(char const &c)
{
	if (!(c == EMPTY_CELL[0] || c == Player::player1[0] || c == Player::player2[0]))
		return (false);
	m_val = c;
	return (true);
}

std::string					Cell::getVal(void) const
{
	return (m_val);
}