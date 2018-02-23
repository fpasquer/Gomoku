/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ia_player.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 11:43:03 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/23 16:31:08 by amaindro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Ia_player.hpp"

void						Ia_player::play
		(short grid[SIZE_GRID][SIZE_GRID], unsigned int const depth, unsigned int &max_x, unsigned int &max_y)
{
	int		max = -10000;
	int		tmp;
	short	val;
	Grid	grid_class(grid);

	for(int y = 0; y < SIZE_GRID; y++)//a remplacer par un tableau des cases vides
	{
		for(int x = 0; x < SIZE_GRID; x++)
		{
			grid_class.getValue(val, x, y);
			if(val == EMPTY_CELL)
			{
				grid_class.setValue('O', x, y);
				if(grid_class.haveWin(y, x, 'O', "") == true)
				{
					std::cout << "START x :" << x << " y :" << y <<std::endl;
					std::cout << "START won" <<std::endl;
					max_y = y;
					max_x = x;
					return ;
				}
				tmp = Ia_player::Min(grid_class, depth - 1, grid);

				if(tmp > max)
				{
					max = tmp;
					max_y = y;
					max_x = x;
				}
				grid_class.setValue(EMPTY_CELL, x, y);
			}
		}
	}
}

int							Ia_player::Max
		(Grid &grid_class, unsigned int const depth, short grid[SIZE_GRID][SIZE_GRID])
{
	//std::cout << "MAX" <<std::endl;
	if(depth == 0)
	{
		//std::cout << "Depth" <<std::endl;
		return (0);
	}

	int		max = -10000;
	int		tmp;
	short	val;

	for(int y = 0; y < SIZE_GRID; y++)
	{
		for(int x = 0; x < SIZE_GRID; x++)
		{
			grid_class.getValue(val, x, y);
			if(val == EMPTY_CELL)
			{
				grid_class.setValue('O', x, y);
				//std::cout << "MAX x :" << x << " y :" << y <<std::endl;
				if(grid_class.haveWin(y, x, 'O', "") == true)
				{
					grid_class.setValue(EMPTY_CELL, x, y);
					std::cout << "MAX won" <<std::endl;
					return (1 * depth);
				}
				tmp = Ia_player::Min(grid_class, depth - 1, grid);

				if(tmp > max)
				{
					max = tmp;
				}
				grid_class.setValue(EMPTY_CELL, x, y);
			}
		}
	}

	return max;

}

int							Ia_player::Min
		(Grid &grid_class, unsigned int const depth, short grid[SIZE_GRID][SIZE_GRID])
{
	//std::cout << "MIN" <<std::endl;
	if(depth == 0)
	{
		//std::cout << "Depth" <<std::endl;
		return (0);
	}

	int		min = 10000;
	int		tmp;
	short	val;

	for(int y = 0; y < SIZE_GRID; y++)
	{
		for(int x = 0; x < SIZE_GRID; x++)
		{
			grid_class.getValue(val, x, y);
			if(val == EMPTY_CELL)
			{
				grid_class.setValue('X', x, y);
				if(grid_class.haveWin(y, x, 'X', "") == true)
				{
					grid_class.setValue(EMPTY_CELL, x, y);
					std::cout << "MIN x :" << x << " y :" << y <<std::endl;
					std::cout << "MIN won" <<std::endl;
					return (-1 * depth);
				}
				tmp = Ia_player::Max(grid_class, depth - 1, grid);

				if(tmp < min)
				{
					min = tmp;
				}
				grid_class.setValue(EMPTY_CELL, x, y);
			}
		}
	}

	return min;

}
