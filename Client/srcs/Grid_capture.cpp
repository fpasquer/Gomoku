/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Grid_capture.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 20:13:50 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/28 15:17:47 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Grid.hpp"
#include "../incs/FreeThree.hpp"

Grid::t_list_way const		Grid::m_list_way[] = {
	{LEFT, &Grid::checkLeft},
	{LEFT_TOP, &Grid::checkLeftTop},
	{TOP, &Grid::checkTop},
	{TOP_RIGHT, &Grid::checkTopRight},
	{RIGHT, &Grid::checkRight},
	{RIGHT_BOTTOM, &Grid::checkRightBottom},
	{BOTTOM, &Grid::checkBottom},
	{BOTTOM_LEFT, &Grid::checkBottomLeft},
	{NONE, NULL}
};

t_way						Grid::checkLeft(Player const &player)
{
	char					val;
	unsigned int			y;
	unsigned int			x;
	unsigned int			i;

	y = player.getY();
	x = player.getX();
	val = GET_VAL(player.getValue());
	for (i = 0; i < NB_STONE_CAPTURE && x - i - 1 < SIZE_GRID; i++)
		if (GET_VAL(m_cell[y][x - i - 1]) == val || GET_VAL(m_cell[y][x - i - 1]) == EMPTY_CELL)
			break ;
	if (i != NB_STONE_CAPTURE || x - i - 1 >= SIZE_GRID || GET_VAL(m_cell[y][x - i - 1]) != val)
		return (NONE);
	for (i = 0; i < NB_STONE_CAPTURE; i++)
	{
		m_cell[y][x - i - 1] = CLEAR_PERM_PLAYER(m_cell[y][x - i - 1], EMPTY_CELL, player.getUnpossible());
		this->captureFreethree(y, x - i - 1, player.getValue());
	}
	return (LEFT);
}

t_way						Grid::checkLeftTop(Player const &player)
{
	char					val;
	unsigned int			y;
	unsigned int			x;
	unsigned int			i;

	y = player.getY();
	x = player.getX();
	val = GET_VAL(player.getValue());
	for (i = 0; i < NB_STONE_CAPTURE && x - i - 1 < SIZE_GRID && y - i - 1 < SIZE_GRID; i++)
		if (GET_VAL(m_cell[y - i - 1][x - i - 1]) == val || GET_VAL(m_cell[y - i - 1][x - i - 1]) == EMPTY_CELL)
			break ;
	if (i != NB_STONE_CAPTURE || x - i - 1 >=  SIZE_GRID|| y - i - 1 >= SIZE_GRID || GET_VAL(m_cell[y - i - 1][x - i - 1]) != val)
		return (NONE);
	for (i = 0; i < NB_STONE_CAPTURE; i++)
	{
		m_cell[y - i - 1][x - i - 1] = CLEAR_PERM_PLAYER(m_cell[y - i - 1][x - i - 1], EMPTY_CELL, player.getUnpossible());
		this->captureFreethree(y - i - 1, x - i - 1, player.getValue());
	}
	return (LEFT_TOP);
}

t_way						Grid::checkTop(Player const &player)
{
	char					val;
	unsigned int			y;
	unsigned int			x;
	unsigned int			i;

	y = player.getY();
	x = player.getX();
	val = GET_VAL(player.getValue());
	for (i = 0; i < NB_STONE_CAPTURE && y - i - 1 < SIZE_GRID; i++)
		if (GET_VAL(m_cell[y - i - 1][x]) == val || GET_VAL(m_cell[y - i - 1][x]) == EMPTY_CELL)
			break ;
	if (i != NB_STONE_CAPTURE || y - i - 1 >= SIZE_GRID || GET_VAL(m_cell[y - i - 1][x]) != val)
		return (NONE);
	for (i = 0; i < NB_STONE_CAPTURE; i++)
	{
		m_cell[y - i - 1][x] = CLEAR_PERM_PLAYER(m_cell[y - i - 1][x], EMPTY_CELL, player.getUnpossible());
		this->captureFreethree(y - i - 1, x, player.getValue());
	}
	return (TOP);
}

t_way						Grid::checkTopRight(Player const &player)
{
	char					val;
	unsigned int			y;
	unsigned int			x;
	unsigned int			i;

	y = player.getY();
	x = player.getX();
	val = GET_VAL(player.getValue());
	for (i = 0; i < NB_STONE_CAPTURE && y - i - 1 < SIZE_GRID && x + i + 1 < SIZE_GRID; i++)
		if (GET_VAL(m_cell[y - i - 1][x + i + 1]) == val || GET_VAL(m_cell[y - i - 1][x + i + 1]) == EMPTY_CELL)
			break ;
	if (i != NB_STONE_CAPTURE || y - i - 1 >= SIZE_GRID || x + i + 1 >= SIZE_GRID || GET_VAL(m_cell[y - i - 1][x + i + 1]) != val)
		return (NONE);
	for (i = 0; i < NB_STONE_CAPTURE; i++)
	{
		m_cell[y - i - 1][x + i + 1] = CLEAR_PERM_PLAYER(m_cell[y - i - 1][x + i + 1], EMPTY_CELL, player.getUnpossible());
		this->captureFreethree(y - i - 1, x + i + 1, player.getValue());
	}
	return (TOP_RIGHT);
}

t_way						Grid::checkRight(Player const &player)
{
	char					val;
	unsigned int			y;
	unsigned int			x;
	unsigned int			i;

	y = player.getY();
	x = player.getX();
	val = GET_VAL(player.getValue());
	for (i = 0; i < NB_STONE_CAPTURE && x + i + 1 < SIZE_GRID; i++)
		if (GET_VAL(m_cell[y][x + i + 1]) == val || GET_VAL(m_cell[y][x + i + 1]) == EMPTY_CELL)
			break ;
	if (i != NB_STONE_CAPTURE || x + i + 1 >= SIZE_GRID || GET_VAL(m_cell[y][x + i + 1]) != val)
		return (NONE);
	for (i = 0; i < NB_STONE_CAPTURE; i++)
	{
		m_cell[y][x + i + 1] = CLEAR_PERM_PLAYER(m_cell[y][x + i + 1], EMPTY_CELL, player.getUnpossible());
		this->captureFreethree(y, x + i + 1, player.getValue());
	}
	return (RIGHT);
}

t_way						Grid::checkRightBottom(Player const &player)
{
	char					val;
	unsigned int			y;
	unsigned int			x;
	unsigned int			i;

	y = player.getY();
	x = player.getX();
	val = GET_VAL(player.getValue());
	for (i = 0; i < NB_STONE_CAPTURE && y + i + 1 < SIZE_GRID && x + i + 1 < SIZE_GRID; i++)
		if (GET_VAL(m_cell[y + i + 1][x + i + 1]) == val || GET_VAL(m_cell[y + i + 1][x + i + 1]) == EMPTY_CELL)
			break ;
	if (i != NB_STONE_CAPTURE || x + i + 1 >= SIZE_GRID || y + i + 1 >= SIZE_GRID || GET_VAL(m_cell[y + i + 1][x + i + 1]) != val)
		return (NONE);
	for (i = 0; i < NB_STONE_CAPTURE; i++)
	{
		m_cell[y + i + 1][x + i + 1] = CLEAR_PERM_PLAYER(m_cell[y + i + 1][x + i + 1], EMPTY_CELL, player.getUnpossible());
		this->captureFreethree(y + i + 1, x + i + 1, player.getValue());
	}
	return (RIGHT_BOTTOM);
}

t_way						Grid::checkBottom(Player const &player)
{
	char					val;
	unsigned int			y;
	unsigned int			x;
	unsigned int			i;

	y = player.getY();
	x = player.getX();
	val = GET_VAL(player.getValue());
	for (i = 0; i < NB_STONE_CAPTURE && y + i + 1 < SIZE_GRID; i++)
		if (GET_VAL(m_cell[y + i + 1][x]) == val || GET_VAL(m_cell[y + i + 1][x]) == EMPTY_CELL)
			break ;
	if (i != NB_STONE_CAPTURE || y + i + 1 >= SIZE_GRID || GET_VAL(m_cell[y + i + 1][x]) != val)
		return (NONE);
	for (i = 0; i < NB_STONE_CAPTURE; i++)
	{
		m_cell[y + i + 1][x] = CLEAR_PERM_PLAYER(m_cell[y + i + 1][x], EMPTY_CELL, player.getUnpossible());
		this->captureFreethree(y + i + 1, x, player.getValue());
	}
	return (BOTTOM);
}

t_way						Grid::checkBottomLeft(Player const &player)
{
	char					val;
	unsigned int			y;
	unsigned int			x;
	unsigned int			i;

	y = player.getY();
	x = player.getX();
	val = GET_VAL(player.getValue());
	for (i = 0; i < NB_STONE_CAPTURE && y + i + 1 < SIZE_GRID && x - i - 1 < SIZE_GRID; i++)
		if (GET_VAL(m_cell[y + i + 1][x - i - 1]) == val || GET_VAL(m_cell[y + i + 1][x - i - 1]) == EMPTY_CELL)
			break ;
	if (i != NB_STONE_CAPTURE || y + i + 1 >= SIZE_GRID || x - i - 1 >= SIZE_GRID || GET_VAL(m_cell[y + i + 1][x - i - 1]) != val)
		return (NONE);
	for (i = 0; i < NB_STONE_CAPTURE; i++)
	{
		m_cell[y + i + 1][x - i - 1] = CLEAR_PERM_PLAYER(m_cell[y + i + 1][x - i - 1], EMPTY_CELL, player.getUnpossible());
		this->captureFreethree(y + i + 1, x - i - 1, player.getValue());
	}
	return (BOTTOM_LEFT);
}

void						Grid::captureFreethree(unsigned int const y_tmp, unsigned int const x_tmp, short const val)
{
	unsigned int			i;
	char					other_perm;
	char					other_val;
	short					c;
	short					other_player;
	FreeThree				freeThree(*this);
	
	other_val = GET_VAL(val) == PLAYER1 ? PLAYER2 : PLAYER1;
	other_perm = (GET_PERM(val) == CAN_NOT_PLAY1) ? CAN_NOT_PLAY2 : CAN_NOT_PLAY1;
	other_player = SET_VAL(0, other_val);
	other_player = SET_PERM(other_player, other_perm);
	//check gauche
	for (i = 1; i <= 3 ; i++)
		if (this->getValue(c, x_tmp - i, y_tmp) == true && (GET_PERM(c) & other_perm) != 0 &&
			freeThree.checkFreeThree(y_tmp, x_tmp - i, other_player) == false)
		m_cell[y_tmp][x_tmp - i] = SET_PERM(m_cell[y_tmp][x_tmp - i], other_perm);
	//check haut gauche
	for (i = 1; i <= 3 ; i++)
		if (this->getValue(c, x_tmp - i, y_tmp - i) == true && (GET_PERM(c) & other_perm) != 0 &&
	 			freeThree.checkFreeThree(y_tmp - i, x_tmp - i, other_player) == false)
	 		m_cell[y_tmp - i][x_tmp - i] = SET_PERM(m_cell[y_tmp - i][x_tmp - i], other_perm);
	//check haut
	for (i = 1; i <= 3 ; i++)
		if (this->getValue(c, x_tmp, y_tmp - i) == true && (GET_PERM(c) & other_perm) != 0 &&
			freeThree.checkFreeThree(y_tmp - i, x_tmp, other_player) == false)
		m_cell[y_tmp - i][x_tmp] = SET_PERM(m_cell[y_tmp - i][x_tmp], other_perm);
	//check haut droit
	for (i = 1; i <= 3 ; i++)
		if (this->getValue(c, x_tmp + i, y_tmp - i) == true && (GET_PERM(c) & other_perm) != 0 &&
				freeThree.checkFreeThree(y_tmp - i, x_tmp + i, other_player) == false)
			m_cell[y_tmp - i][x_tmp + i] = SET_PERM(m_cell[y_tmp - i][x_tmp + i], other_perm);
	//check droit
	for (i = 1; i <= 3 ; i++)
		if (this->getValue(c, x_tmp + i, y_tmp) == true && (GET_PERM(c) & other_perm) != 0 &&
				freeThree.checkFreeThree(y_tmp, x_tmp + i, other_player) == false)
			m_cell[y_tmp][x_tmp + i] = SET_PERM(m_cell[y_tmp][x_tmp + i], other_perm);
	//check bas droit
	for (i = 1; i <= 3 ; i++)
		if (this->getValue(c, x_tmp + i, y_tmp + i) == true && (GET_PERM(c) & other_perm) != 0 &&
				freeThree.checkFreeThree(y_tmp + i, x_tmp + i, other_player) == false)
			m_cell[y_tmp + i][x_tmp + i] = SET_PERM(m_cell[y_tmp + i][x_tmp + i], other_perm);
	//check bas
	for (i = 1; i <= 3 ; i++)
		if (this->getValue(c, x_tmp, y_tmp + i) == true && (GET_PERM(c) & other_perm) != 0 &&
				freeThree.checkFreeThree(y_tmp + i, x_tmp, other_player) == false)
			m_cell[y_tmp + i][x_tmp] = SET_PERM(m_cell[y_tmp + i][x_tmp], other_perm);
	//check bas gauche
	for (i = 1; i <= 3 ; i++)
		if (this->getValue(c, x_tmp - i, y_tmp + i) == true && (GET_PERM(c) & other_perm) != 0 &&
				freeThree.checkFreeThree(y_tmp + i, x_tmp - i, other_player) == false)
			m_cell[y_tmp + i][x_tmp - i] = SET_PERM(m_cell[y_tmp + i][x_tmp - i], other_perm);




}

std::string					Grid::getCaptureIa(void) const
{
	return (m_ia.getCapture());
}

t_way						Grid::checkCaptures(Player &player)
{
	unsigned int			i;
	t_way					way;

	for (way = NONE, i = 0; m_list_way[i].f != NULL; i++)
		if (((*this).*m_list_way[i].f)(player) == m_list_way[i].way)
		{
			player.addCapture();
			way = m_list_way[i].way;
		}
	return (way);
}