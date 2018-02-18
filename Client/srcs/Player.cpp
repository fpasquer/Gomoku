/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 20:35:27 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/18 09:18:12 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Player.hpp"

unsigned int				Player::m_count = 0;

							Player::Player(unsigned int const &x, unsigned int const &y) : m_x(x), m_y(y), m_capture("")
{
	m_x = (m_x >= SIZE_GRID) ? 0 : m_x;
	m_y = (m_y >= SIZE_GRID) ? 0 : m_y;
	m_val = (m_count++ == 0) ? PLAYER1 : PLAYER2;
}

bool						Player::setX(unsigned int const &x)
{
	if (x >= SIZE_GRID)
		return (false);
	m_x = x;
	return (true);
}

unsigned int				Player::getX(void) const
{
	return (m_x);
}

bool						Player::setY(unsigned int const &y)
{
	if (y >= SIZE_GRID)
		return (false);
	m_y = y;
	return (true);
}

unsigned int				Player::getY(void) const
{
	return (m_y);
}

char						Player::getValue(void) const
{
	return (m_val);
}

void						Player::addCapture(void)
{
	m_capture += "**";
}

std::string					Player::getCapture(void) const
{
	return (m_capture);
}