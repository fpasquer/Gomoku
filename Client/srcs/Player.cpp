/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 20:35:27 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/07 14:59:37 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Player.hpp"

Player::t_cmd const			Player::m_cmd[] = {
	{KEY_ARROW_LEFT_, &Player::moveLeft},
	{KEY_ARROW_RIGHT_, &Player::moveRight},
	{KEY_ARROW_DOWN_, &Player::moveDown},
	{KEY_ARROW_UP_, &Player::moveUp},
	{KEY_SPACE_, &Player::isSpace},
	{KEY_MORE_, &Player::deepMore},
	{KEY_MINUS_, &Player::deepMinus},
	{0, NULL}
};

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

bool						Player::moveLeft(void)
{
	this->setX(m_x - 1);
	return (false);
}

bool						Player::moveRight(void)
{
	this->setX(m_x + 1);
	return (false);
}


bool						Player::moveDown(void)
{
	this->setY(m_y + 1);
	return (false);
}

bool						Player::moveUp(void)
{
	this->setY(m_y - 1);
	return (false);
}

bool						Player::isSpace(void)
{
	return (true);
}

bool						Player::deepMinus(void)
{
	if (m_deep > MIN_DEEP)
		m_deep--;
	return (false);
}

bool						Player::deepMore(void)
{
	if (m_deep < MAX_DEEP)
		m_deep++;
	return (false);
}

bool						Player::checkKeySelect(std::string const &key)
{
	unsigned int			i;

	for (i = 0; m_cmd[i].key != 0; i++)
		if (key == m_cmd[i].key)
			return ((*(this).*m_cmd[i].f)());
	return (false);
}

char						Player::getValue(void) const
{
	return (m_val);
}