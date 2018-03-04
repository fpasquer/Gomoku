/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FreeThree.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 13:23:16 by fpasquer          #+#    #+#             */
/*   Updated: 2018/03/04 15:32:40 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Tools_incs/FreeThree.hpp"

FreeThree::t_checkFreet const
							FreeThree::m_func[] = {

	{&FreeThree::checkFTLeft},
	{&FreeThree::checkFTTopLeft},
	{&FreeThree::checkFTTop},
	{&FreeThree::checkFTTopRight},
	{&FreeThree::checkFTRight},
	{&FreeThree::checkFTBottomRight},
	{&FreeThree::checkFTBottom},
	{&FreeThree::checkFTBottomLeft},
	{NULL}
};

							FreeThree::FreeThree(void) : CountStone()
{
	
}

							FreeThree::FreeThree(short const cell[SIZE_GRID][SIZE_GRID]) : CountStone(cell)
{
	
}

bool						FreeThree::checkFTLeft(unsigned const int y_tmp, unsigned const int x_tmp, short const val, char &way) const
{
	short					c;
	unsigned int			y;
	unsigned int			x;
	unsigned int			count;

	y = y_tmp;
	x = x_tmp - 2;
	if ((way & RIGHT) != 0 || this->getValue(c, x, y) == false || GET_VAL(c) != GET_VAL(val))
		return (false);
	count = 0;
	if (this->countLeft(y_tmp, x_tmp, val, count) == true && count >= 2)
	{
		way ^= LEFT;
		return (true);
	}
	if ((way ^ RIGHT) == 0 && this->getValue(c, x + 1, y) == true && GET_VAL(c) == EMPTY_CELL &&
			this->countLeft(y, x, val, count) == true && count >= 1)
	{
		way ^= LEFT;
		return (true);
	}
	return (false);
}

bool						FreeThree::checkFTTopLeft(unsigned const int y_tmp, unsigned const int x_tmp, short const val, char &way) const
{
	short					c;
	unsigned int			y;
	unsigned int			x;
	unsigned int			count;

	y = y_tmp - 2;
	x = x_tmp - 2;
	if ((way & RIGHT_BOTTOM) != 0 || this->getValue(c, x, y) == false || GET_VAL(c) != GET_VAL(val))
		return (false);
	count = 0;
	if (this->countLeftTop(y_tmp, x_tmp, val, count) == true && count >= 2)
	{
		way ^= LEFT_TOP;
		return (true);
	}
	if (this->getValue(c, x + 1, y + 1) == true && GET_VAL(c) == EMPTY_CELL &&
			this->countLeftTop(y, x, val, count) == true && count >= 1)
	{
		way ^= LEFT_TOP;
		return (true);
	}
	return (false);
}

bool						FreeThree::checkFTTop(unsigned const int y_tmp, unsigned const int x_tmp, short const val, char &way) const
{
	short					c;
	unsigned int			y;
	unsigned int			x;
	unsigned int			count;

	y = y_tmp - 2;
	x = x_tmp;
	if ((way & BOTTOM) != 0 || this->getValue(c, x, y) == false || GET_VAL(c) != GET_VAL(val))
		return (false);
	count = 0;
	if (this->countTop(y_tmp, x_tmp, val, count) == true && count >= 2)
	{
		way ^= TOP;
		return (true);
	}
	if (this->getValue(c, x, y + 1) == true && GET_VAL(c) == EMPTY_CELL &&
			this->countTop(y, x, val, count) == true && count >= 1)
	{
		way ^= TOP;
		return (true);
	}
	return (false);
}

bool						FreeThree::checkFTTopRight(unsigned const int y_tmp, unsigned const int x_tmp, short const val, char &way) const
{
	short					c;
	unsigned int			y;
	unsigned int			x;
	unsigned int			count;

	y = y_tmp - 2;
	x = x_tmp + 2;
	if ((way & BOTTOM_LEFT) != 0 || this->getValue(c, x, y) == false || GET_VAL(c) != GET_VAL(val))
		return (false);
	count = 0;
	if (this->countTopRight(y_tmp, x_tmp, val, count) == true && count >= 2)
	{
		way ^= TOP_RIGHT;
		return (true);
	}
	if (this->getValue(c, x - 1, y + 1) == true && GET_VAL(c) == EMPTY_CELL &&
			this->countTopRight(y, x, val, count) ==true && count >= 1)
	{
		way ^= TOP_RIGHT;
		return (true);
	}
	return (false);
}

bool						FreeThree::checkFTRight(unsigned const int y_tmp, unsigned const int x_tmp, short const val, char &way) const
{
	short					c;
	unsigned int			y;
	unsigned int			x;
	unsigned int			count;

	y = y_tmp;
	x = x_tmp + 2;
	if ((way & LEFT) != 0 || this->getValue(c, x, y) == false || GET_VAL(c) != GET_VAL(val))
		return (false);
	count = 0;
	if (this->countRight(y_tmp, x_tmp, val, count) == true && count >= 2)
	{
		way ^= RIGHT;
		return (true);
	}
	if (this->getValue(c, x - 1, y) == true && GET_VAL(c) == EMPTY_CELL &&
			this->countRight(y, x, val, count) == true && count >= 1)
	{
		way ^= RIGHT;
		return (true);
	}
	return (false);
}

bool						FreeThree::checkFTBottomRight(unsigned const int y_tmp, unsigned const int x_tmp, short const val, char &way) const
{
	short					c;
	unsigned int			y;
	unsigned int			x;
	unsigned int			count;

	y = y_tmp + 2;
	x = x_tmp + 2;
	if ((way & LEFT_TOP) != 0 || this->getValue(c, x, y) == false || GET_VAL(c) != GET_VAL(val))
		return (false);
	count = 0;
	if (this->countRightBottom(y_tmp, x_tmp, val, count) == true && count >= 2)
	{
		way ^= RIGHT_BOTTOM;
		return (true);
	}
	if (this->getValue(c, x - 1, y - 1) == true && GET_VAL(c) == EMPTY_CELL &&
			this->countRightBottom(y, x, val, count) == true && count >= 1)
	{
		way ^= RIGHT_BOTTOM;
		return (true);
	}
	return (false);
}

bool						FreeThree::checkFTBottom(unsigned const int y_tmp, unsigned const int x_tmp, short const val, char &way) const
{
	short					c;
	unsigned int			y;
	unsigned int			x;
	unsigned int			count;

	y = y_tmp + 2;
	x = x_tmp;
	if ((way & TOP) != 0 || this->getValue(c, x, y) == false || GET_VAL(c) != GET_VAL(val))
		return (false);
	count = 0;
	if (this->countBottom(y_tmp, x_tmp, val, count) == true && count >= 2)
	{
		way ^= BOTTOM;
		return (true);
	}
	if (this->getValue(c, x, y - 1) == true && GET_VAL(c) == EMPTY_CELL &&
			this->countBottom(y, x, val, count) == true && count >= 1)
	{
		way ^= BOTTOM;
		return (true);
	}
	return (false);
}

bool						FreeThree::checkFTBottomLeft(unsigned const int y_tmp, unsigned const int x_tmp, short const val, char &way) const
{
	short					c;
	unsigned int			y;
	unsigned int			x;
	unsigned int			count;

	y = y_tmp + 2;
	x = x_tmp - 2;
	if ((way & TOP_RIGHT) != 0 || this->getValue(c, x, y) == false || GET_VAL(c) != GET_VAL(val))
		return (false);
	count = 0;
	if (this->countBottomLeft(y_tmp, x_tmp, val, count) == true && count >= 2)
	{
		way ^= BOTTOM_LEFT;
		return (true);
	}
	if (this->getValue(c, x + 1, y - 1) == true && GET_VAL(c) == EMPTY_CELL &&
			this->countBottomLeft(y, x, val, count) == true && count >= 1)
	{
		way ^= BOTTOM_LEFT;
		return (true);
	}
	return (false);
}

void						FreeThree::destroyFreeThree(unsigned const int y, unsigned const int x, short const val)
/*
DESCRIPTION :
	when player put his stone check if a free three of the other player have been destroyed
*/
{
	char					other_perm;
	char					other_val;
	short					c;
	short					other_player;

	other_val = GET_VAL(val) == PLAYER1 ? PLAYER2 : PLAYER1;
	other_perm = GET_PERM(val) == CAN_NOT_PLAY1 ? CAN_NOT_PLAY2 : CAN_NOT_PLAY1;
	other_player = SET_VAL(0, other_val);
	other_player = SET_PERM(other_player, other_perm);
	//check gauche
	if (this->getValue(c, x - 1, y) == true && (GET_PERM(c) & other_perm) != 0)
		if (this->getValue(c, x + 1, y) == true && GET_VAL(c) == other_val &&
				this->getValue(c, x + 2, y) == true && GET_VAL(c) == other_val &&
				this->checkFreeThree(y, x - 1, other_player) == false)
			m_cell[y][x - 1] = SET_PERM(m_cell[y][x - 1], other_perm);
	//check haut gauche
	if (this->getValue(c, x - 1, y - 1) == true && (GET_PERM(c) & other_perm) != 0)
		if (this->getValue(c, x + 1, y + 1) == true && GET_VAL(c) == other_val &&
				this->getValue(c, x + 2, y + 2) == true && GET_VAL(c) == other_val &&
				this->checkFreeThree(y - 1, x - 1, other_player) == false)
			m_cell[y - 1][x - 1] = SET_PERM(m_cell[y - 1][x - 1], other_perm);
	//check haut
	if (this->getValue(c, x, y - 1) == true && (GET_PERM(c) & other_perm) != 0)
		if (this->getValue(c, x, y + 1) == true && GET_VAL(c) == other_val &&
				this->getValue(c, x, y + 2) == true && GET_VAL(c) == other_val &&
				this->checkFreeThree(y - 1, x, other_player) == false)
			m_cell[y - 1][x] = SET_PERM(m_cell[y - 1][x], other_perm);
	//check haut droit
	if (this->getValue(c, x + 1, y - 1) == true && (GET_PERM(c) & other_perm) != 0)
		if (this->getValue(c, x - 1, y + 1) == true && GET_VAL(c) == other_val &&
				this->getValue(c, x - 2, y + 2) == true && GET_VAL(c) == other_val &&
				this->checkFreeThree(y - 1, x + 1, other_player) == false)
			m_cell[y - 1][x + 1] = SET_PERM(m_cell[y - 1][x + 1], other_perm);
	//check droit
	if (this->getValue(c, x + 1, y) == true && (GET_PERM(c) & other_perm) != 0)
		if (this->getValue(c, x - 1, y) == true && GET_VAL(c) == other_val &&
				this->getValue(c, x - 2, y) == true && GET_VAL(c) == other_val &&
				this->checkFreeThree(y, x + 1, other_player) == false)
			m_cell[y][x + 1] = SET_PERM(m_cell[y][x + 1], other_perm);
	//check bas droit
	if (this->getValue(c, x + 1, y + 1) == true && (GET_PERM(c) & other_perm) != 0)
		if (this->getValue(c, x - 1, y - 1) == true && GET_VAL(c) == other_val &&
				this->getValue(c, x - 2, y - 2) == true && GET_VAL(c) == other_val &&
				this->checkFreeThree(y + 1, x + 1, other_player) == false)
			m_cell[y + 1][x + 1] = SET_PERM(m_cell[y + 1][x + 1], other_perm);
	//check bas
	if (this->getValue(c, x, y + 1) == true && (GET_PERM(c) & other_perm) != 0)
		if (this->getValue(c, x, y - 1) == true && GET_VAL(c) == other_val &&
				this->getValue(c, x, y - 2) == true && GET_VAL(c) == other_val &&
				this->checkFreeThree(y + 1, x, other_player) == false)
			m_cell[y + 1][x] = SET_PERM(m_cell[y + 1][x], other_perm);
	//check bas gauche
	if (this->getValue(c, x - 1, y + 1) == true && (GET_PERM(c) & other_perm) != 0)
		if (this->getValue(c, x + 1, y - 1) == true && GET_VAL(c) == other_val &&
				this->getValue(c, x + 2, y - 2) == true && GET_VAL(c) == other_val &&
				this->checkFreeThree(y + 1, x - 1, other_player) == false)
			m_cell[y + 1][x - 1] = SET_PERM(m_cell[y + 1][x - 1], other_perm);
}

void						FreeThree::setUnavailable(unsigned int const y_tmp,
		unsigned int const x_tmp, short const val)
/*
DESCRIPTION :
	turn on the free three when player creat one
PARAM :
	y_tmp	-> Line where player puted his stone
	x_tmp	-> Column where player puted his stone
	val		-> Of the current player
*/
{
	char const				unpossible = GET_PERM(val);
	short					c;
	unsigned int			y;
	unsigned int			x;
	unsigned int			decalage;
	unsigned int			end;

	end = DEPTH_FREETHREE * 2 + 1;
	for (y = y_tmp - DEPTH_FREETHREE, x = x_tmp - DEPTH_FREETHREE, decalage = 0; decalage < end; decalage++)//check gauche haut bas droit
	{
		if (y + decalage == y_tmp && x + decalage == x_tmp)
			continue ;
		if (y + decalage < SIZE_GRID && x + decalage < SIZE_GRID && this->checkFreeThree(y + decalage, x + decalage, val) == true && this->getValue(c, x + decalage, y + decalage) == true && (GET_PERM(c) & GET_PERM(val)) == 0)
			m_cell[y + decalage][x + decalage] = SET_PERM(m_cell[y + decalage][x + decalage], unpossible);
	}
	for (y = y_tmp - DEPTH_FREETHREE, x = x_tmp, decalage = 0; decalage < end; decalage++)//check haut bas
	{
		if (y + decalage == y_tmp)
			continue ;
		if (y + decalage < SIZE_GRID && this->checkFreeThree(y + decalage, x, val) == true && this->getValue(c, x, y + decalage) == true && (GET_PERM(c) & GET_PERM(val)) == 0)
			m_cell[y + decalage][x] = SET_PERM(m_cell[y + decalage][x], unpossible);
	}
	for (y = y_tmp - DEPTH_FREETHREE, x = x_tmp + DEPTH_FREETHREE, decalage = 0; decalage < end; decalage++)//check Haut droit bas gauche
	{
		if (y + decalage == y_tmp && x - decalage == x_tmp)
			continue ;
		if (y + decalage < SIZE_GRID && x - decalage < SIZE_GRID && this->checkFreeThree(y + decalage, x - decalage, val) == true && this->getValue(c, x - decalage, y + decalage) == true && (GET_PERM(c) & GET_PERM(val)) == 0)
			m_cell[y + decalage][x - decalage] = SET_PERM(m_cell[y + decalage][x - decalage], unpossible);
	}
	for (y = y_tmp, x = x_tmp  - DEPTH_FREETHREE, decalage = 0; decalage < end; decalage++)//check gauche droit
	{
		if (x + decalage == x_tmp)
			continue ;
		if (x + decalage < SIZE_GRID && this->checkFreeThree(y, x + decalage, val) == true && this->getValue(c, x + decalage, y) == true && (GET_PERM(c) & GET_PERM(val)) == 0)
			m_cell[y][x + decalage] = SET_PERM(m_cell[y][x + decalage], unpossible);
	}
}

void						FreeThree::checkFreethreeAgent(unsigned int const y1, unsigned int const x1,
		unsigned int const y2, unsigned int const x2, char const other_perm, char const other_val)
{
	short					c;

	if (this->getValue(c, x1, y1) == true && (GET_PERM(c) & other_perm) != 0 &&
			this->checkFreeThree(y1, x1, other_val) == false)
		m_cell[y1][x1] = SET_PERM(m_cell[y1][x1], other_perm);
	if (GET_VAL(c) == EMPTY_CELL && this->getValue(c, x2, y2) == true && (GET_PERM(c) & other_perm) != 0 &&
			this->checkFreeThree(y2, x2, other_val) == false)
		m_cell[y2][x2] = SET_PERM(m_cell[y2][x2], other_perm);
}

void						FreeThree::setAvailable(unsigned int const y_tmp,
		unsigned int const x_tmp, short const val)
/*
DESCRIPTION :
	remove the freethree of the other player when player break it 
PARAM :
	y_tmp	-> Line where player puted his stone
	x_tmp	-> Column where player puted his stone
	val		-> Of the current player
*/
{
	unsigned int			y;
	unsigned int			x;
	short					c;
	char					other_perm;
	char					other_val;

	other_val = GET_VAL(val) == PLAYER1 ? PLAYER2 : PLAYER1;
	other_perm = GET_PERM(val) == CAN_NOT_PLAY1 ? CAN_NOT_PLAY2 : CAN_NOT_PLAY1;
	
	//check gauche
	for (x = 1; this->getValue(c, x_tmp - x, y_tmp) == true && GET_VAL(c) == other_val; x++)
		;
	if (x >= 3)
		this->checkFreethreeAgent(y_tmp, x_tmp - x, y_tmp, x_tmp - (x + 1), other_perm, other_val);

	//check haut gauche
	for (y = 1, x = 1; this->getValue(c, x_tmp - x, y_tmp - y) == true && GET_VAL(c) == other_val; y++, x++)
		;
	if (x >= 3 && y >= 3)
		this->checkFreethreeAgent(y_tmp - y, x_tmp - x, y_tmp - (y + 1), x_tmp - (x + 1), other_perm, other_val);

	//check haut
	for (y = 1; this->getValue(c, x_tmp, y_tmp - y) == true && GET_VAL(c) == other_val; y++)
		;
	if (y >= 3)
		this->checkFreethreeAgent(y_tmp - y, x_tmp, y_tmp - (y + 1), x_tmp, other_perm, other_val);

	//check haut droite
	for (y = 1, x = 1; this->getValue(c, x_tmp + x, y_tmp - y) == true && GET_VAL(c) == other_val; y++, x++)
		;
	if (y >= 3 && x >= 3)
		this->checkFreethreeAgent(y_tmp - y, x_tmp + x, y_tmp - (y + 1), x_tmp + (x + 1), other_perm, other_val);

	//check droite
	for (x = 1; this->getValue(c, x_tmp + x, y_tmp) == true && GET_VAL(c) == other_val; x++)
		;
	if (x >= 3)
		this->checkFreethreeAgent(y_tmp, x_tmp + x, y_tmp, x_tmp + (x + 1), other_perm, other_val);

	//check bas droite
	for (y = 1, x = 1; this->getValue(c, x_tmp + x, y_tmp + y) == true && GET_VAL(c) == other_val; y++, x++)
		;
	if (y >= 3 && x >= 3)
		this->checkFreethreeAgent(y_tmp + y, x_tmp + x, y_tmp + (y + 1), x_tmp + (x + 1), other_perm, other_val);

	//check bas
	for (y = 1; this->getValue(c, x_tmp, y_tmp + y) == true && GET_VAL(c) == other_val; y++)
		;
	if (y >= 3)
		this->checkFreethreeAgent(y_tmp + y, x_tmp, y_tmp + (y + 1), x_tmp, other_perm, other_val);

	//check bas gauche
	for (y = 1, x = 1; this->getValue(c, x_tmp - x, y_tmp + y) == true && GET_VAL(c) == other_val; y++, x++)
		;
	if (y >= 3 && x >= 3)
		this->checkFreethreeAgent(y_tmp + y, x_tmp - x, y_tmp + (y + 1), x_tmp - (x + 1), other_perm, other_val);
}

bool						FreeThree::checkFreeThree(unsigned int const y, unsigned int const x, short const val) const
{
	char					way;
	short					c;
	unsigned int			i;
	unsigned int			count;

	if (this->getValue(c, x, y) == false || GET_VAL(c) != EMPTY_CELL)
		return (false);
	for (way = NONE, i = 0, count = 0; m_func[i].f != NULL; i++)
		if (((*this).*m_func[i].f)(y, x, val, way) == true)
			count++;
	return (count >= 2 ? true : false);
}

bool						FreeThree::updateFreeThree(unsigned int const y, unsigned int const x, short const val) const
{
	short					c;
	short					new_val;

	if (this->getValue(c, x, y) == false || GET_VAL(c) != EMPTY_CELL || GET_PERM(c) == 0)
		return (false);
	new_val = SET_VAL(0, GET_VAL(val) == PLAYER1 ? PLAYER2 : PLAYER1);
	new_val = SET_PERM(new_val, (GET_PERM(val) == CAN_NOT_PLAY1) ? CAN_NOT_PLAY2 : CAN_NOT_PLAY1);
	if (((GET_PERM(c)) & (GET_PERM(new_val))) == 0)
		return (false);
	return (!(this->checkFreeThree(y, x, new_val)));
}