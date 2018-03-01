/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ia_player.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 11:43:03 by fpasquer          #+#    #+#             */
/*   Updated: 2018/03/01 15:36:35 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Ia_player.hpp"
//#define DEBUG

int const					Ia_player::start_min = 10000;
int const					Ia_player::start_max = -10000;
int const					Ia_player::win = 1;

							Ia_player::Ia_player(short grid[SIZE_GRID][SIZE_GRID])
{
	unsigned int			y_ia;
	unsigned int			x_ia;
	
	for (y_ia = 0; y_ia < SIZE_GRID; y_ia++)
		for (x_ia = 0; x_ia < SIZE_GRID; x_ia++)
			m_grid[y_ia][x_ia] = grid[y_ia][x_ia];
}

void						Ia_player::play(short grid[SIZE_GRID][SIZE_GRID], unsigned int &x,
				unsigned int &y, int const depth, size_t const nb_capture_player,
				size_t const  nb_capture_ia)
{
#ifdef RAND
	do
	{
		x = rand() % SIZE_GRID;
		y = rand() % SIZE_GRID;
	}	while (grid[y][x] != EMPTY_CELL);
#else
	unsigned int			y_ia;
	unsigned int			x_ia;
	int						max = Ia_player::start_max;
	int						tmp;
	Ia_player				ia_player(grid);

	std::cout << "Line : " << __LINE__ << " Player_capture : "<< nb_capture_player << " IA capture : " << nb_capture_ia << std::endl << "\t";
	ia_player.show(0, 0);
	for (y_ia = 0; y_ia < SIZE_GRID; y_ia++)
		for (x_ia = 0; x_ia < SIZE_GRID; x_ia++)
		{
			if (GET_VAL(ia_player.m_grid[y_ia][x_ia]) != EMPTY_CELL ||
					(GET_PERM(ia_player.m_grid[y_ia][x_ia]) & CAN_NOT_PLAY2) != 0)
				continue ;
			ia_player.m_grid[y_ia][x_ia] = SET_VAL(ia_player.m_grid[y_ia][x_ia], PLAYER2);
#ifdef DEBUG
				std::cout << "Line : " << __LINE__ << std::endl << "\t";
				ia_player.show(y_ia, x_ia);
#endif
			if ((tmp = ia_player.min(depth - 1, y_ia, x_ia)) > max)
			{
				max = tmp;
				y = y_ia;
				x = x_ia;
			}
			ia_player.m_grid[y_ia][x_ia] = SET_VAL(ia_player.m_grid[y_ia][x_ia], EMPTY_CELL);
		}
	std::cout << "Line : " << __LINE__ << std::endl << "\t";
	ia_player.show(0, 0);
	std::cout << std::endl<< std::endl;
#endif
}

int							Ia_player::min(int const depth, unsigned int const y, unsigned int const x)
{
	bool					retHaveWin = false;
	unsigned int			y_ia;
	unsigned int			x_ia;
	int						min = Ia_player::start_min;
	int						tmp;

	if ((retHaveWin = this->haveWin(y, x, PLAYER2)) == true || depth <= 0)
		return (this->eval(retHaveWin, PLAYER2, depth));
	for (y_ia = 0; y_ia < SIZE_GRID; y_ia++)
		for (x_ia = 0; x_ia < SIZE_GRID; x_ia++)
		{
			if (GET_VAL(this->m_grid[y_ia][x_ia]) != EMPTY_CELL ||
					(GET_PERM(this->m_grid[y_ia][x_ia]) & CAN_NOT_PLAY1) != 0)
				continue ;
			this->m_grid[y_ia][x_ia] = SET_VAL(this->m_grid[y_ia][x_ia], PLAYER1);
#ifdef DEBUG
				std::cout << "Line : " << __LINE__ << std::endl << "\t";
				this->show(y_ia, x_ia);
#endif
			if ((tmp = this->max(depth -1, y_ia, x_ia)) < min)
				min = tmp;
			this->m_grid[y_ia][x_ia] = SET_VAL(this->m_grid[y_ia][x_ia], EMPTY_CELL);
		}
	return (min);
}

int							Ia_player::max(int const depth, unsigned int const y, unsigned int const x)
{
	bool					retHaveWin = false;
	unsigned int			y_ia;
	unsigned int			x_ia;
	int						max = Ia_player::start_max;
	int						tmp;

	if ((retHaveWin = this->haveWin(y, x, PLAYER1)) == true || depth <= 0)
		return (this->eval(retHaveWin, PLAYER1, depth));
	for (y_ia = 0; y_ia < SIZE_GRID; y_ia++)
		for (x_ia = 0; x_ia < SIZE_GRID; x_ia++)
		{
			if (GET_VAL(this->m_grid[y_ia][x_ia]) != EMPTY_CELL ||
					(GET_PERM(this->m_grid[y_ia][x_ia]) & CAN_NOT_PLAY2) != 0)
				continue ;
				this->m_grid[y_ia][x_ia] = SET_VAL(this->m_grid[y_ia][x_ia], PLAYER2);
#ifdef DEBUG
				std::cout << "Line : " << __LINE__ << std::endl << "\t";
				this->show(y_ia, x_ia);
#endif
			if ((tmp = this->min(depth -1, y_ia, x_ia)) > max)
				max = tmp;
			this->m_grid[y_ia][x_ia] = SET_VAL(this->m_grid[y_ia][x_ia], EMPTY_CELL);
		}
	return (max);
}

bool						Ia_player::haveWin(unsigned int const y, unsigned int const x, short const val) const
{
	unsigned int			count1;
	unsigned int			count2;

	CountWin::countLeft(m_grid, y, x, val, count1);
	CountWin::countRight(m_grid, y, x, val, count2);
	if (count1 + count2 + 1 >= NB_STONE_WIN)
		return (true);
	CountWin::countTop(m_grid, y, x, val, count1);
	CountWin::countBottom(m_grid, y, x, val, count2);
	if (count1 + count2 + 1 >= NB_STONE_WIN)
		return (true);
	CountWin::countLeftTop(m_grid, y, x, val, count1);
	CountWin::countRightBottom(m_grid, y, x, val, count2);
	if (count1 + count2 + 1 >= NB_STONE_WIN)
		return (true);
	CountWin::countTopRight(m_grid, y, x, val, count1);
	CountWin::countBottomLeft(m_grid, y, x, val, count2);
	if (count1 + count2 + 1 >= NB_STONE_WIN)
		return (true);
	return (false);
}

void						Ia_player::show(unsigned int const y, unsigned int const x) const
{
	char					buff[5];
	unsigned int			y_ia;
	unsigned int			x_ia;
	std::string				str = "";

	for (y_ia = 0; y_ia < SIZE_GRID; y_ia++)
	{
		for (x_ia = 0; x_ia < SIZE_GRID; x_ia++)
		{
			if (y == y_ia && x == x_ia)
				str += "\033[31m";
			if (snprintf(buff, 5, "%4d", (int)m_grid[y_ia][x_ia]) > 0)
				str += m_grid[y_ia][x_ia] == ' ' ? "  . " : buff;
			if (y == y_ia && x == x_ia)
				str += "\033[0m";
		}
		str += "\n\t";
	}
	std::cout << str;
}

int							Ia_player::eval(bool const retHaveWin, char const player, int const depth) const
{
	int						ret;

	ret = retHaveWin == true ? Ia_player::win : 0;
	return (player == PLAYER1 ? ret * -1 * (depth + 1): ret * (depth + 1));
}
