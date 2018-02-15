/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ia_player.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 11:43:03 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/15 15:31:56 by amaindro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Ia_player.hpp"

void						Ia_player::play
		(char grid[SIZE_GRID][SIZE_GRID], unsigned int const depth, unsigned int &max_x, unsigned int &max_y)
{
	int		max = -10000;
	int		tmp;
	Grid	grid_class(grid);

	for(int y = 0; y < SIZE_GRID; y++)
	{
		for(int x = 0; x < SIZE_GRID; x++)
		{
			if(grid[y][x] == EMPTY_CELL)
			{
				grid[y][x] = 'O';
				tmp = Ia_player::Min(grid_class, depth - 1, grid);

				if(tmp > max)
				{
					max = tmp;
					max_y = y;
					max_x = x;
				}
				grid[y][x] = EMPTY_CELL;
			}
		}
	}
}

int							Ia_player::Max
		(Grid &grid_class, unsigned int const depth, char grid[SIZE_GRID][SIZE_GRID])
{
	if(depth == 0 || grid_class.haveWin(grid_class.getLastY(), grid_class.getLastX(), 'X') == true)
	{
		return (-1 * depth);
	}

	int max = -10000;
	int tmp;

	for(int y = 0; y < SIZE_GRID; y++)
	{
		for(int x = 0; x < SIZE_GRID; x++)
		{
			if(grid[y][x] == EMPTY_CELL)
			{
				grid[y][x] = 'O';
				tmp = Ia_player::Min(grid_class, depth - 1, grid);

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
		(Grid &grid_class, unsigned int const depth, char grid[SIZE_GRID][SIZE_GRID])
{
	if(depth == 0 || grid_class.haveWin(grid_class.getLastY(), grid_class.getLastX(), 'O') == true)
	{
		return (1 * depth);
	}

	int min = 10000;
	int tmp;

	for(int y = 0; y < SIZE_GRID; y++)
	{
		for(int x = 0; x < SIZE_GRID; x++)
		{
			if(grid[y][x] == EMPTY_CELL)
			{
				grid[y][x] = 'X';
				tmp = Ia_player::Max(grid_class, depth - 1, grid);

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
