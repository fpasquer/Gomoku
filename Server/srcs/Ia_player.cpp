/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ia_player.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 11:43:03 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/26 11:51:17 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Ia_player.hpp"
# define MIN_MAX

int const					Ia_player::start_min = -10000;
int const					Ia_player::start_max = 10000;
int const					Ia_player::win = 10000;

							Ia_player::Ia_player(short grid[SIZE_GRID][SIZE_GRID])
{
	unsigned int			y_ia;
	unsigned int			x_ia;
	
	for (y_ia = 0; y_ia < SIZE_GRID; y_ia++)
		for (x_ia = 0; x_ia < SIZE_GRID; x_ia++)
			m_grid[y_ia][x_ia] = grid[y_ia][x_ia];
}

void						Ia_player::play(short grid[SIZE_GRID][SIZE_GRID], unsigned int &x, unsigned int &y, int const depth)
{
#ifdef RAND
	do
	{
		x = rand() % SIZE_GRID;
		y = rand() % SIZE_GRID;
	}	while (grid[y][x] != EMPTY_CELL);
#endif
#ifdef MIN_MAX
	unsigned int			y_ia;
	unsigned int			x_ia;
	int						max = Ia_player::start_max;
	int						tmp;
	Ia_player				ia_player(grid);
	
	for (y_ia = 0; y_ia < SIZE_GRID; y_ia++)
		for (x_ia = 0; x_ia < SIZE_GRID; x_ia++)
		{
			if (GET_VAL(ia_player.m_grid[y_ia][x_ia]) != EMPTY_CELL ||
					(GET_PERM(ia_player.m_grid[y_ia][x_ia]) & CAN_NOT_PLAY2) != 0)
				continue ;
			ia_player.m_grid[y_ia][x_ia] = SET_VAL(ia_player.m_grid[y_ia][x_ia], PLAYER2);
			if ((tmp = ia_player.min(depth - 1, y_ia, x_ia)) > max)
			{
				max = tmp;
				y = y_ia;
				x = x_ia;
			}
			ia_player.m_grid[y_ia][x_ia] = SET_VAL(ia_player.m_grid[y_ia][x_ia], EMPTY_CELL);
		}
#endif
}

int							Ia_player::min(int const depth, unsigned int const y, unsigned int const x)
{
	bool					retHaveWin = false;
	unsigned int			y_ia;
	unsigned int			x_ia;
	int						min = Ia_player::start_min;
	int						tmp;

	if (depth <= 0 || (retHaveWin = this->haveWin(y, x, PLAYER2)) == true)
		return (this->eval(retHaveWin, PLAYER2));
	for (y_ia = 0; y_ia < SIZE_GRID; y_ia++)
		for (x_ia = 0; x_ia < SIZE_GRID; x_ia++)
		{
			if (GET_VAL(this->m_grid[y_ia][x_ia]) != EMPTY_CELL ||
					(GET_PERM(this->m_grid[y_ia][x_ia]) & CAN_NOT_PLAY1) != 0)
				continue ;
			this->m_grid[y_ia][x_ia] = SET_VAL(this->m_grid[y_ia][x_ia], PLAYER1);
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

	if (depth <= 0 || (retHaveWin = this->haveWin(y, x, PLAYER1)) == true)
		return (this->eval(retHaveWin, PLAYER1));
	for (y_ia = 0; y_ia < SIZE_GRID; y_ia++)
		for (x_ia = 0; x_ia < SIZE_GRID; x_ia++)
		{
			if (GET_VAL(this->m_grid[y_ia][x_ia]) != EMPTY_CELL ||
					(GET_PERM(this->m_grid[y_ia][x_ia]) & CAN_NOT_PLAY2) != 0)
				continue ;
			this->m_grid[y_ia][x_ia] = SET_VAL(this->m_grid[y_ia][x_ia], PLAYER2);
			if ((tmp = this->min(depth -1, y_ia, x_ia)) > max)
				max = tmp;
			this->m_grid[y_ia][x_ia] = SET_VAL(this->m_grid[y_ia][x_ia], EMPTY_CELL);
		}
	return (max);
}

bool						Ia_player::haveWin(unsigned int const y, unsigned int const x, short const val) const
{
	if (y == x == val)
		return (false);
	return (false);
}

int							Ia_player::eval(bool const retHaveWin, char const player) const
{
	int						ret;

	ret = retHaveWin == true ? Ia_player::win : 1;
	return (player == PLAYER2 ? ret * -1: ret);
}

// int							Ia_player::Max
// 		(char grid[SIZE_GRID][SIZE_GRID], unsigned int const depth)
// {
// 	/*if(depth == 0 || gagnant(grid) !=0)
// 	{
// 		return eval(grid);
// 	}*/

// 	int max = -10000;
// 	int tmp;

// 	for(int y = 0; y < 3; y++)
// 	{
// 		for(int x = 0; x < 3; x++)
// 		{
// 			if(grid[y][x] == EMPTY_CELL)
// 			{
// 				grid[y][x] = 'X';
// 				tmp = Ia_player::Min(grid, depth - 1);

// 				if(tmp > max)
// 				{
// 					max = tmp;
// 				}
// 				grid[y][x] = EMPTY_CELL;
// 			}
// 		}
// 	}

// 	return max;

// }

// int							Ia_player::Min
// 		(char grid[SIZE_GRID][SIZE_GRID], unsigned int const depth)
// {
// 	/*if(depth == 0 || gagnant(grid) !=0)
// 	{
// 		return eval(grid);
// 	}*/

// 	int min = 10000;
// 	int tmp;

// 	for(int y = 0; y < 3; y++)
// 	{
// 		for(int x = 0; x < 3; x++)
// 		{
// 			if(grid[y][x] == EMPTY_CELL)
// 			{
// 				grid[y][x] = 'O';
// 				tmp = Ia_player::Max(grid, depth - 1);

// 				if(tmp < min)
// 				{
// 					min = tmp;
// 				}
// 				grid[y][x] = EMPTY_CELL;
// 			}
// 		}
// 	}

// 	return min;

// }

/*int		get_score(int player, char grid[SIZE_GRID][SIZE_GRID], unsigned int const depth, unsigned int &x, unsigned int &y)
  {
  int		score;

  y = 0;
  while (y < SIZE_GRID && GAME_IS_NOT_OVER && depth < 0)
  {
  x = 0;
  while (x < SIZE_GRID && GAME_IS_NOT_OVER && depth < 0)
  {
  if (grid[y][x] == EMPTY_CELL)
  {
  grid[y][x] = (player == 1) ? 'X' : 'O';
  score = get_score(player * -1, grid, depth - 1, x, y);
  grid[y][x] = EMPTY_CELL;
  }
  x++;
  }
  y++;
  }
  return ((player == 1)? get_max(score) : get_min(score));
  }*/
