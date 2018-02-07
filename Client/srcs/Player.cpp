/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 20:35:27 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/07 12:58:01 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Player.hpp"

unsigned int				Player::m_count = 0;

							Player::Player(unsigned int const &x, unsigned int const &y, unsigned int const &deep) : m_x(x), m_y(y), m_deep(deep)
{
	m_deep = (m_deep > MAX_DEEP) ? INIT_DEEP : m_deep;
	m_x = (m_x >= SIZE_GRID) ? 0 : m_x;
	m_y = (m_y >= SIZE_GRID) ? 0 : m_y;
	m_i = m_count;
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

unsigned int				Player::getDeep(void) const
{
	return (m_deep);
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

bool						Player::checkKeySelect(std::string const &key)
{
	if (key == KEY_ARROW_LEFT_)
		this->setX(m_x - 1);
	else if (key == KEY_ARROW_RIGHT_)
		this->setX(m_x + 1);
	else if (key == KEY_ARROW_DOWN_)
		this->setY(m_y + 1);
	else if (key == KEY_ARROW_UP_)
		this->setY(m_y - 1);
	return ((key == KEY_SPACE_) ? true : false); 
}

char						Player::getValue(void) const
{
	return (m_val);
}