/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ia_player.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 11:43:03 by fpasquer          #+#    #+#             */
/*   Updated: 2018/03/15 09:07:18 by amaindro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Ia_player.hpp"
//#define DEBUG

int const					Ia_player::start_min = 10000;
int const					Ia_player::start_max = -10000;
int const					Ia_player::win = 1;

							Ia_player::Ia_player(Grid &grid) : m_grid(grid)
{

}

void						Ia_player::play(Grid &grid, unsigned int &x, unsigned int &y)
{
#ifdef RAND
	do
	{
		x = rand() % SIZE_GRID;
		y = rand() % SIZE_GRID;
	}	while (grid[y][x] != EMPTY_CELL);
	return ;
#else
	char					way_captures;
	short					c;
	unsigned int			y_ia;
	unsigned int			x_ia;
	int						max = Ia_player::start_max;
	int						tmp;
	Ia_player				ia_player(grid);

	for (y_ia = 0; y_ia < SIZE_GRID; y_ia++)
		for (x_ia = 0; x_ia < SIZE_GRID; x_ia++)
		{
			if (ia_player.m_grid.getValue(c, x_ia, y_ia) == false || GET_VAL(c) != EMPTY_CELL ||
					(GET_PERM(c) & CAN_NOT_PLAY2) != 0 ||
					ia_player.m_grid.setValue(PLAYER2, y_ia, x_ia, &way_captures) == false)
				continue ;
#ifdef DEBUG
				std::cout << "Line : " << __LINE__ << std::endl << "\t";
				ia_player.show(y_ia, x_ia);
#endif
			if ((tmp = ia_player.min(ia_player.m_grid.getDepth() - 1, y_ia, x_ia, max)) > max)
			{
				ia_player.show(__LINE__, y_ia, x_ia, tmp);
				max = tmp;
				y = y_ia;
				x = x_ia;
			}
			ia_player.m_grid.unsetValue(PLAYER2, y_ia, x_ia, way_captures);
		}
#endif
}

int							Ia_player::min(int const depth, unsigned int const y, unsigned int const x, int prev_branch)
{
	char					way_captures;
	short					c;
	bool					retHaveWin = false;
	unsigned int			y_ia;
	unsigned int			x_ia;
	int						min = Ia_player::start_min;
	int						tmp;

	if ((retHaveWin = this->m_grid.haveWin(y, x, PLAYER2, this->m_grid.getNbCaptureIa())) == true || depth <= 0)
		return (this->eval(retHaveWin, PLAYER2, depth));
	for (y_ia = 0; y_ia < SIZE_GRID; y_ia++)
		for (x_ia = 0; x_ia < SIZE_GRID; x_ia++)
		{
			if (this->m_grid.getValue(c, x_ia, y_ia) == false || GET_VAL(c) != EMPTY_CELL ||
					(GET_PERM(c) & CAN_NOT_PLAY1) != 0 || this->m_grid.setValue(PLAYER1, y_ia, x_ia, &way_captures) == false)
				continue ;
#ifdef DEBUG
				std::cout << "Line : " << __LINE__ << std::endl << "\t";
				this->show(y_ia, x_ia);
#endif
			if ((tmp = this->max(depth -1, y_ia, x_ia, min)) < min)
				min = tmp;
			if (tmp <= prev_branch)
			{
				this->m_grid.unsetValue(PLAYER1, y_ia, x_ia, way_captures);
				return (min);
			}
			this->m_grid.unsetValue(PLAYER1, y_ia, x_ia, way_captures);
		}
	return (min);
}

int							Ia_player::max(int const depth, unsigned int const y, unsigned int const x, int prev_branch)
{
	char					way_captures;
	short					c;
	bool					retHaveWin = false;
	unsigned int			y_ia;
	unsigned int			x_ia;
	int						max = Ia_player::start_max;
	int						tmp;

	if ((retHaveWin = this->m_grid.haveWin(y, x, PLAYER1, this->m_grid.getNbCapturePlayer())) == true || depth <= 0)
		return (this->eval(retHaveWin, PLAYER1, depth));
	for (y_ia = 0; y_ia < SIZE_GRID; y_ia++)
		for (x_ia = 0; x_ia < SIZE_GRID; x_ia++)
		{
			if (this->m_grid.getValue(c, x_ia, y_ia) == false || GET_VAL(c) != EMPTY_CELL ||
					(GET_PERM(c) & CAN_NOT_PLAY2) != 0 || this->m_grid.setValue(PLAYER2, y_ia, x_ia, &way_captures) == false)
				continue ;
#ifdef DEBUG
			std::cout << "Line : " << __LINE__ << std::endl << "\t";
			this->show(y_ia, x_ia);
#endif
			if ((tmp = this->min(depth -1, y_ia, x_ia, max)) > max)
				max = tmp;
			if (tmp >= prev_branch)
			{
				this->m_grid.unsetValue(PLAYER2, y_ia, x_ia, way_captures);
				return (max);
			}
			this->m_grid.unsetValue(PLAYER2, y_ia, x_ia, way_captures);
		}
	return (max);
}

void						Ia_player::show(unsigned int const line, unsigned int const y, unsigned int const x, int const max) const
{
	std::cout << "Line : " << line << " MAX = " << max << std::endl << "\t";
	this->m_grid.show(y, x);
	std::cout << std::endl<< std::endl;
}

int							Ia_player::eval(bool const retHaveWin, char const player, int const depth) const
{
	int						ret;

	ret = retHaveWin == true ? Ia_player::win : 0;
	return (player == PLAYER1 ? ret * -1 * (depth + 1): ret * (depth + 1));
}
