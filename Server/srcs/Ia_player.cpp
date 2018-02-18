/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ia_player.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 11:43:03 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/18 09:54:07 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Ia_player.hpp"

void						Ia_player::play
		(short grid[SIZE_GRID][SIZE_GRID], unsigned int &x, unsigned int &y)
{
	do
	{
		x = rand() % SIZE_GRID;
		y = rand() % SIZE_GRID;
	}	while (grid[y][x] != EMPTY_CELL);
}

int							Ia_player::Max
		(char grid[SIZE_GRID][SIZE_GRID], unsigned int const depth)
{
	/*if(depth == 0 || gagnant(grid) !=0)
	{
		return eval(grid);
	}*/

	int max = -10000;
	int tmp;

	for(int y = 0; y < 3; y++)
	{
		for(int x = 0; x < 3; x++)
		{
			if(grid[y][x] == EMPTY_CELL)
			{
				grid[y][x] = 'X';
				tmp = Ia_player::Min(grid, depth - 1);

				if(tmp > max)
				{
					max = tmp;
				}
				grid[y][x] = EMPTY_CELL;
			}
		}
	}

	return max;

}

int							Ia_player::Min
		(char grid[SIZE_GRID][SIZE_GRID], unsigned int const depth)
{
	/*if(depth == 0 || gagnant(grid) !=0)
	{
		return eval(grid);
	}*/

	int min = 10000;
	int tmp;

	for(int y = 0; y < 3; y++)
	{
		for(int x = 0; x < 3; x++)
		{
			if(grid[y][x] == EMPTY_CELL)
			{
				grid[y][x] = 'O';
				tmp = Ia_player::Max(grid, depth - 1);

				if(tmp < min)
				{
					min = tmp;
				}
				grid[y][x] = EMPTY_CELL;
			}
		}
	}

	return min;

}

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
