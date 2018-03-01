/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Captures.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 20:13:50 by fpasquer          #+#    #+#             */
/*   Updated: 2018/03/01 15:08:58 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Tools_incs/Captures.hpp"

Captures::t_list_way const		Captures::m_list_way[] = {
	{LEFT, &Captures::checkLeft},
	{LEFT_TOP, &Captures::checkLeftTop},
	{TOP, &Captures::checkTop},
	{TOP_RIGHT, &Captures::checkTopRight},
	{RIGHT, &Captures::checkRight},
	{RIGHT_BOTTOM, &Captures::checkRightBottom},
	{BOTTOM, &Captures::checkBottom},
	{BOTTOM_LEFT, &Captures::checkBottomLeft},
	{NONE, NULL}
};

							Captures::Captures(void) : FreeThree()
{
	
}

							Captures::Captures(short const cell[SIZE_GRID][SIZE_GRID]) : FreeThree(cell)
{
	
}

t_way						Captures::checkLeft(unsigned int const y, unsigned int const x, short const val)
{
	unsigned int			i;

	for (i = 0; i < NB_STONE_CAPTURE && x - i - 1 < SIZE_GRID; i++)
		if (GET_VAL(m_cell[y][x - i - 1]) == GET_VAL(val) || GET_VAL(m_cell[y][x - i - 1]) == EMPTY_CELL)
			break ;
	if (i != NB_STONE_CAPTURE || x - i - 1 >= SIZE_GRID || GET_VAL(m_cell[y][x - i - 1]) != GET_VAL(val) )
		return (NONE);
	for (i = 0; i < NB_STONE_CAPTURE; i++)
	{
		m_cell[y][x - i - 1] = CLEAR_PERM_PLAYER(m_cell[y][x - i - 1], EMPTY_CELL, GET_PERM(val));
		this->captureFreethree(y, x - i - 1, val);
	}
	return (LEFT);
}

t_way						Captures::checkLeftTop(unsigned int const y, unsigned int const x, short const val)
{
	unsigned int			i;

	for (i = 0; i < NB_STONE_CAPTURE && x - i - 1 < SIZE_GRID && y - i - 1 < SIZE_GRID; i++)
		if (GET_VAL(m_cell[y - i - 1][x - i - 1]) == GET_VAL(val) || GET_VAL(m_cell[y - i - 1][x - i - 1]) == EMPTY_CELL)
			break ;
	if (i != NB_STONE_CAPTURE || x - i - 1 >=  SIZE_GRID|| y - i - 1 >= SIZE_GRID || GET_VAL(m_cell[y - i - 1][x - i - 1]) != GET_VAL(val))
		return (NONE);
	for (i = 0; i < NB_STONE_CAPTURE; i++)
	{
		m_cell[y - i - 1][x - i - 1] = CLEAR_PERM_PLAYER(m_cell[y - i - 1][x - i - 1], EMPTY_CELL, GET_PERM(val));
		this->captureFreethree(y - i - 1, x - i - 1, val);
	}
	return (LEFT_TOP);
}

t_way						Captures::checkTop(unsigned int const y, unsigned int const x, short const val)
{
	unsigned int			i;

	for (i = 0; i < NB_STONE_CAPTURE && y - i - 1 < SIZE_GRID; i++)
		if (GET_VAL(m_cell[y - i - 1][x]) == GET_VAL(val) || GET_VAL(m_cell[y - i - 1][x]) == EMPTY_CELL)
			break ;
	if (i != NB_STONE_CAPTURE || y - i - 1 >= SIZE_GRID || GET_VAL(m_cell[y - i - 1][x]) != GET_VAL(val))
		return (NONE);
	for (i = 0; i < NB_STONE_CAPTURE; i++)
	{
		m_cell[y - i - 1][x] = CLEAR_PERM_PLAYER(m_cell[y - i - 1][x], EMPTY_CELL, GET_PERM(val));
		this->captureFreethree(y - i - 1, x, val);
	}
	return (TOP);
}

t_way						Captures::checkTopRight(unsigned int const y, unsigned int const x, short const val)
{
	unsigned int			i;

	for (i = 0; i < NB_STONE_CAPTURE && y - i - 1 < SIZE_GRID && x + i + 1 < SIZE_GRID; i++)
		if (GET_VAL(m_cell[y - i - 1][x + i + 1]) == GET_VAL(val) || GET_VAL(m_cell[y - i - 1][x + i + 1]) == EMPTY_CELL)
			break ;
	if (i != NB_STONE_CAPTURE || y - i - 1 >= SIZE_GRID || x + i + 1 >= SIZE_GRID || GET_VAL(m_cell[y - i - 1][x + i + 1]) != GET_VAL(val))
		return (NONE);
	for (i = 0; i < NB_STONE_CAPTURE; i++)
	{
		m_cell[y - i - 1][x + i + 1] = CLEAR_PERM_PLAYER(m_cell[y - i - 1][x + i + 1], EMPTY_CELL, GET_PERM(val));
		this->captureFreethree(y - i - 1, x + i + 1, val);
	}
	return (TOP_RIGHT);
}

t_way						Captures::checkRight(unsigned int const y, unsigned int const x, short const val)
{
	unsigned int			i;

	for (i = 0; i < NB_STONE_CAPTURE && x + i + 1 < SIZE_GRID; i++)
		if (GET_VAL(m_cell[y][x + i + 1]) == GET_VAL(val) || GET_VAL(m_cell[y][x + i + 1]) == EMPTY_CELL)
			break ;
	if (i != NB_STONE_CAPTURE || x + i + 1 >= SIZE_GRID || GET_VAL(m_cell[y][x + i + 1]) != GET_VAL(val))
		return (NONE);
	for (i = 0; i < NB_STONE_CAPTURE; i++)
	{
		m_cell[y][x + i + 1] = CLEAR_PERM_PLAYER(m_cell[y][x + i + 1], EMPTY_CELL, GET_PERM(val));
		this->captureFreethree(y, x + i + 1, val);
	}
	return (RIGHT);
}

t_way						Captures::checkRightBottom(unsigned int const y, unsigned int const x, short const val)
{
	unsigned int			i;

	for (i = 0; i < NB_STONE_CAPTURE && y + i + 1 < SIZE_GRID && x + i + 1 < SIZE_GRID; i++)
		if (GET_VAL(m_cell[y + i + 1][x + i + 1]) == GET_VAL(val) || GET_VAL(m_cell[y + i + 1][x + i + 1]) == EMPTY_CELL)
			break ;
	if (i != NB_STONE_CAPTURE || x + i + 1 >= SIZE_GRID || y + i + 1 >= SIZE_GRID || GET_VAL(m_cell[y + i + 1][x + i + 1]) != GET_VAL(val))
		return (NONE);
	for (i = 0; i < NB_STONE_CAPTURE; i++)
	{
		m_cell[y + i + 1][x + i + 1] = CLEAR_PERM_PLAYER(m_cell[y + i + 1][x + i + 1], EMPTY_CELL, GET_PERM(val));
		this->captureFreethree(y + i + 1, x + i + 1, val);
	}
	return (RIGHT_BOTTOM);
}

t_way						Captures::checkBottom(unsigned int const y, unsigned int const x, short const val)
{
	unsigned int			i;

	for (i = 0; i < NB_STONE_CAPTURE && y + i + 1 < SIZE_GRID; i++)
		if (GET_VAL(m_cell[y + i + 1][x]) == GET_VAL(val) || GET_VAL(m_cell[y + i + 1][x]) == EMPTY_CELL)
			break ;
	if (i != NB_STONE_CAPTURE || y + i + 1 >= SIZE_GRID || GET_VAL(m_cell[y + i + 1][x]) != GET_VAL(val))
		return (NONE);
	for (i = 0; i < NB_STONE_CAPTURE; i++)
	{
		m_cell[y + i + 1][x] = CLEAR_PERM_PLAYER(m_cell[y + i + 1][x], EMPTY_CELL, GET_PERM(val));
		this->captureFreethree(y + i + 1, x, val);
	}
	return (BOTTOM);
}

t_way						Captures::checkBottomLeft(unsigned int const y, unsigned int const x, short const val)
{
	unsigned int			i;

	for (i = 0; i < NB_STONE_CAPTURE && y + i + 1 < SIZE_GRID && x - i - 1 < SIZE_GRID; i++)
		if (GET_VAL(m_cell[y + i + 1][x - i - 1]) == GET_VAL(val) || GET_VAL(m_cell[y + i + 1][x - i - 1]) == EMPTY_CELL)
			break ;
	if (i != NB_STONE_CAPTURE || y + i + 1 >= SIZE_GRID || x - i - 1 >= SIZE_GRID || GET_VAL(m_cell[y + i + 1][x - i - 1]) != GET_VAL(val))
		return (NONE);
	for (i = 0; i < NB_STONE_CAPTURE; i++)
	{
		m_cell[y + i + 1][x - i - 1] = CLEAR_PERM_PLAYER(m_cell[y + i + 1][x - i - 1], EMPTY_CELL, GET_PERM(val));
		this->captureFreethree(y + i + 1, x - i - 1, val);
	}
	return (BOTTOM_LEFT);
}

void						Captures::captureFreethree(unsigned int const y_tmp, unsigned int const x_tmp, short const val)
{
	unsigned int			i;
	char					other_perm;
	char					other_val;
	short					c;
	short					other_player;
	
	other_val = GET_VAL(val) == PLAYER1 ? PLAYER2 : PLAYER1;
	other_perm = (GET_PERM(val) == CAN_NOT_PLAY1) ? CAN_NOT_PLAY2 : CAN_NOT_PLAY1;
	other_player = SET_VAL(0, other_val);
	other_player = SET_PERM(other_player, other_perm);
	//check gauche
	for (i = 1; i <= 3 ; i++)
		if (this->getValue(c, x_tmp - i, y_tmp) == true && (GET_PERM(c) & other_perm) != 0 &&
			this->checkFreeThree(y_tmp, x_tmp - i, other_player) == false)
		m_cell[y_tmp][x_tmp - i] = SET_PERM(m_cell[y_tmp][x_tmp - i], other_perm);
	//check haut gauche
	for (i = 1; i <= 3 ; i++)
		if (this->getValue(c, x_tmp - i, y_tmp - i) == true && (GET_PERM(c) & other_perm) != 0 &&
	 			this->checkFreeThree(y_tmp - i, x_tmp - i, other_player) == false)
	 		m_cell[y_tmp - i][x_tmp - i] = SET_PERM(m_cell[y_tmp - i][x_tmp - i], other_perm);
	//check haut
	for (i = 1; i <= 3 ; i++)
		if (this->getValue(c, x_tmp, y_tmp - i) == true && (GET_PERM(c) & other_perm) != 0 &&
			this->checkFreeThree(y_tmp - i, x_tmp, other_player) == false)
		m_cell[y_tmp - i][x_tmp] = SET_PERM(m_cell[y_tmp - i][x_tmp], other_perm);
	//check haut droit
	for (i = 1; i <= 3 ; i++)
		if (this->getValue(c, x_tmp + i, y_tmp - i) == true && (GET_PERM(c) & other_perm) != 0 &&
				this->checkFreeThree(y_tmp - i, x_tmp + i, other_player) == false)
			m_cell[y_tmp - i][x_tmp + i] = SET_PERM(m_cell[y_tmp - i][x_tmp + i], other_perm);
	//check droit
	for (i = 1; i <= 3 ; i++)
		if (this->getValue(c, x_tmp + i, y_tmp) == true && (GET_PERM(c) & other_perm) != 0 &&
				this->checkFreeThree(y_tmp, x_tmp + i, other_player) == false)
			m_cell[y_tmp][x_tmp + i] = SET_PERM(m_cell[y_tmp][x_tmp + i], other_perm);
	//check bas droit
	for (i = 1; i <= 3 ; i++)
		if (this->getValue(c, x_tmp + i, y_tmp + i) == true && (GET_PERM(c) & other_perm) != 0 &&
				this->checkFreeThree(y_tmp + i, x_tmp + i, other_player) == false)
			m_cell[y_tmp + i][x_tmp + i] = SET_PERM(m_cell[y_tmp + i][x_tmp + i], other_perm);
	//check bas
	for (i = 1; i <= 3 ; i++)
		if (this->getValue(c, x_tmp, y_tmp + i) == true && (GET_PERM(c) & other_perm) != 0 &&
				this->checkFreeThree(y_tmp + i, x_tmp, other_player) == false)
			m_cell[y_tmp + i][x_tmp] = SET_PERM(m_cell[y_tmp + i][x_tmp], other_perm);
	//check bas gauche
	for (i = 1; i <= 3 ; i++)
		if (this->getValue(c, x_tmp - i, y_tmp + i) == true && (GET_PERM(c) & other_perm) != 0 &&
				this->checkFreeThree(y_tmp + i, x_tmp - i, other_player) == false)
			m_cell[y_tmp + i][x_tmp - i] = SET_PERM(m_cell[y_tmp + i][x_tmp - i], other_perm);
}

unsigned int				Captures::checkCaptures(unsigned int const y_tmp, unsigned int const x_tmp, short const val)
{
	unsigned int			i;
	unsigned int			count;

	for (count = 0, i = 0; m_list_way[i].f != NULL; i++)
		if (((*this).*m_list_way[i].f)(y_tmp, x_tmp, val) == m_list_way[i].way)
			count++;
	return (count);
}