/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HaveWin.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 11:44:05 by fpasquer          #+#    #+#             */
/*   Updated: 2018/03/22 16:24:59 by amaindro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Tools_incs/HaveWin.hpp"

							HaveWin::HaveWin(void) : CountStone()
{

}

							HaveWin::HaveWin(short const cell[SIZE_GRID][SIZE_GRID]) : CountStone(cell)
{

}

bool						HaveWin::haveWin(unsigned int const y,
		unsigned int const x, short const val, std::string const &capture, int *weight) const
{
	bool					ret;
	unsigned int			count1;
	unsigned int			count2;
	unsigned int			count_tmp1;
	unsigned int			count_tmp2;
	unsigned int			y_tmp;
	unsigned int			x_tmp;
	int						countered;
	int						tmp_weight = 0;

	ret = this->countLeft(y, x, val, count1) | this->countRight(y, x, val, count2);
	for (countered = 0, x_tmp = x - count1, y_tmp = y; countered <= NB_STONE_WIN - 1 && x_tmp <= x + count2; x_tmp++, countered++)
	{
		if (((this->countTop(y_tmp, x_tmp, val, count_tmp1) ^ this->countBottom(y_tmp, x_tmp, val, count_tmp2))
					&& count_tmp1 + count_tmp2 == 1) && y_tmp - (count_tmp1 + 1) < SIZE_GRID && y_tmp + (count_tmp2 + 1) < SIZE_GRID)
			countered = -1;
		if (((this->countLeftTop(y_tmp, x_tmp, val, count_tmp1) ^ this->countRightBottom(y_tmp, x_tmp, val, count_tmp2))
					&& count_tmp1 + count_tmp2 == 1) && y_tmp - (count_tmp1 + 1) < SIZE_GRID && y_tmp + (count_tmp2 + 1) < SIZE_GRID && x_tmp - (count_tmp1 + 1) < SIZE_GRID && x_tmp + (count_tmp2 + 1) < SIZE_GRID)
			countered = -1;
		if (((this->countTopRight(y_tmp, x_tmp, val, count_tmp1) ^ this->countBottomLeft(y_tmp, x_tmp, val, count_tmp2))
					&& count_tmp1 + count_tmp2 == 1) && y_tmp - (count_tmp1 + 1) < SIZE_GRID && y_tmp + (count_tmp2 + 1) < SIZE_GRID && x_tmp + (count_tmp1 + 1) < SIZE_GRID && x_tmp - (count_tmp2 + 1) < SIZE_GRID)
			countered = -1;
	}
	if (countered >= NB_STONE_WIN)
		return (true);
	//setting the alignment weight
	if (tmp_weight < countered * ret)
		tmp_weight = countered;

	ret = this->countTop(y, x, val, count1) | this->countBottom(y, x, val, count2);
	for (countered = 0, x_tmp = x, y_tmp = y - count1; countered <= NB_STONE_WIN - 1 && y_tmp <= y + count2; y_tmp++, countered++)
	{
		if (((this->countLeft(y_tmp, x_tmp, val, count_tmp1) ^ this->countRight(y_tmp, x_tmp, val, count_tmp2))
					&& count_tmp1 + count_tmp2 == 1) && x_tmp - (count_tmp1 + 1) < SIZE_GRID && x_tmp + (count_tmp2 + 1) < SIZE_GRID)
			countered = -1;
		if (((this->countLeftTop(y_tmp, x_tmp, val, count_tmp1) ^ this->countRightBottom(y_tmp, x_tmp, val, count_tmp2))
					&& count_tmp1 + count_tmp2 == 1) && y_tmp - (count_tmp1 + 1) < SIZE_GRID && y_tmp + (count_tmp2 + 1) < SIZE_GRID && x_tmp - (count_tmp1 + 1) < SIZE_GRID && x_tmp + (count_tmp2 + 1) < SIZE_GRID)
			countered = -1;
		if (((this->countTopRight(y_tmp, x_tmp, val, count_tmp1) ^ this->countBottomLeft(y_tmp, x_tmp, val, count_tmp2))
					&& count_tmp1 + count_tmp2 == 1) && y_tmp - (count_tmp1 + 1) < SIZE_GRID && y_tmp + (count_tmp2 + 1) < SIZE_GRID && x_tmp + (count_tmp1 + 1) < SIZE_GRID && x_tmp - (count_tmp2 + 1) < SIZE_GRID)
			countered = -1;
	}
	if (countered >= NB_STONE_WIN)
		return (true);
	//setting the alignment weight
	if (tmp_weight < countered * ret)
		tmp_weight = countered;

	ret = this->countLeftTop(y, x, val, count1) | this->countRightBottom(y, x, val, count2);
	for (countered = 0, x_tmp = x - count1, y_tmp = y - count1; countered <= NB_STONE_WIN - 1 && x_tmp <= x + count2; x_tmp++, y_tmp++, countered++)
	{
		if (((this->countTop(y_tmp, x_tmp, val, count_tmp1) ^ this->countBottom(y_tmp, x_tmp, val, count_tmp2))
					&& count_tmp1 + count_tmp2 == 1) && y_tmp - (count_tmp1 + 1) < SIZE_GRID && y_tmp + (count_tmp2 + 1) < SIZE_GRID)
			countered = -1;
		if (((this->countLeft(y_tmp, x_tmp, val, count_tmp1) ^ this->countRight(y_tmp, x_tmp, val, count_tmp2))
					&& count_tmp1 + count_tmp2 == 1) && x_tmp - (count_tmp1 + 1) < SIZE_GRID && x_tmp + (count_tmp2 + 1) < SIZE_GRID)
			countered = -1;
		if (((this->countTopRight(y_tmp, x_tmp, val, count_tmp1) ^ this->countBottomLeft(y_tmp, x_tmp, val, count_tmp2))
					&& count_tmp1 + count_tmp2 == 1) && y_tmp - (count_tmp1 + 1) < SIZE_GRID && y_tmp + (count_tmp2 + 1) < SIZE_GRID && x_tmp + (count_tmp1 + 1) < SIZE_GRID && x_tmp - (count_tmp2 + 1) < SIZE_GRID)
			countered = -1;
	}
	if (countered >= NB_STONE_WIN)
		return (true);
	//setting the alignment weight
	if (tmp_weight < countered * ret)
		tmp_weight = countered;

	ret = this->countTopRight(y, x, val, count1) | this->countBottomLeft(y, x, val, count2);
	for (countered = 0, x_tmp = x + count1, y_tmp = y - count1; countered <= NB_STONE_WIN - 1 && x_tmp >= x - count2 && x_tmp < SIZE_GRID; x_tmp--, y_tmp++, countered++)
	{
		if (((this->countTop(y_tmp, x_tmp, val, count_tmp1) ^ this->countBottom(y_tmp, x_tmp, val, count_tmp2))
					&& count_tmp1 + count_tmp2 == 1) && y_tmp - (count_tmp1 + 1) < SIZE_GRID && y_tmp + (count_tmp2 + 1) < SIZE_GRID)
			countered = -1;
		if (((this->countLeftTop(y_tmp, x_tmp, val, count_tmp1) ^ this->countRightBottom(y_tmp, x_tmp, val, count_tmp2))
					&& count_tmp1 + count_tmp2 == 1) && y_tmp - (count_tmp1 + 1) < SIZE_GRID && y_tmp + (count_tmp2 + 1) < SIZE_GRID && x_tmp - (count_tmp1 + 1) < SIZE_GRID && x_tmp + (count_tmp2 + 1) < SIZE_GRID)
			countered = -1;
		if (((this->countLeft(y_tmp, x_tmp, val, count_tmp1) ^ this->countRight(y_tmp, x_tmp, val, count_tmp2))
					&& count_tmp1 + count_tmp2 == 1) && x_tmp - (count_tmp1 + 1) < SIZE_GRID && x_tmp + (count_tmp2 + 1) < SIZE_GRID)
			countered = -1;
	}
	if (countered >= NB_STONE_WIN)
		return (true);
	//setting the alignment weight
	if (tmp_weight < countered * ret)
		tmp_weight = countered;

	if (weight != NULL)
	{
		switch (tmp_weight)
		{
			case 4 ... SIZE_GRID : *weight = 150;
					break ;
			case 3: *weight = 10;
					break ;
			case 2: *weight = 1;
					break ;
			default: *weight = 0;
		}
		*weight += capture.size() * 50;
	}
	return (capture.size() >= NB_WIN_CAPTURE ? true : false);
}
