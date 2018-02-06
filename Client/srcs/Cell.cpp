/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cell.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 21:20:06 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/06 21:04:01 by fpasquer         ###   ########.fr       */
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

std::string					Cell::getVal(void) const
{
	return (m_val);
}