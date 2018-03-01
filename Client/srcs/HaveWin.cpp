/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HaveWin.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 11:44:05 by fpasquer          #+#    #+#             */
/*   Updated: 2018/03/01 12:58:37 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/HaveWin.hpp"

                            HaveWin::HaveWin(void) : CountStone()
{
    
}

bool						HaveWin::haveWin(Player const &player) const
{
	return (this->haveWin(player.getY(), player.getX(), player.getValue(),
			player.getCapture()));
}

bool						HaveWin::haveWin(unsigned int const y,
		unsigned int const x, short const val, std::string const &capture) const
{
	unsigned int			count1;
	unsigned int			count2;
	unsigned int			count_tmp1;
	unsigned int			count_tmp2;
	unsigned int			y_tmp;
	unsigned int			x_tmp;
	bool					countered;

	countered = false;

	this->countLeft(y, x, val, count1);
	this->countRight(y, x, val, count2);
	if (count1 + count2 + 1 >= NB_STONE_WIN)
	{
		for (x_tmp = x - count1, y_tmp = y; countered == false && x_tmp < x + count2; x_tmp++)
		{
			if ((this->countTop(y_tmp, x_tmp, val, count_tmp1) ^ this->countBottom(y_tmp, x_tmp, val, count_tmp2))
					&& count_tmp1 + count_tmp2 == 1)
				countered = true;
			if ((this->countLeftTop(y_tmp, x_tmp, val, count_tmp1) ^ this->countRightBottom(y_tmp, x_tmp, val, count_tmp2))
					&& count_tmp1 + count_tmp2 == 1)
				countered = true;
			if ((this->countTopRight(y_tmp, x_tmp, val, count_tmp1) ^ this->countBottomLeft(y_tmp, x_tmp, val, count_tmp2))
					&& count_tmp1 + count_tmp2 == 1)
				countered = true;
		}
		if (countered == false)
			return (true);
	}
	this->countTop(y, x, val, count1);
	this->countBottom(y, x, val, count2);
	if (count1 + count2 + 1 >= NB_STONE_WIN)
	{
		for (x_tmp = x, y_tmp = y - count1; countered == false && y_tmp < y + count2; y_tmp++)
		{
			if ((this->countLeft(y_tmp, x_tmp, val, count_tmp1) ^ this->countRight(y_tmp, x_tmp, val, count_tmp2))
					&& count_tmp1 + count_tmp2 == 1)
				countered = true;
			if ((this->countLeftTop(y_tmp, x_tmp, val, count_tmp1) ^ this->countRightBottom(y_tmp, x_tmp, val, count_tmp2))
					&& count_tmp1 + count_tmp2 == 1)
				countered = true;
			if ((this->countTopRight(y_tmp, x_tmp, val, count_tmp1) ^ this->countBottomLeft(y_tmp, x_tmp, val, count_tmp2))
					&& count_tmp1 + count_tmp2 == 1)
				countered = true;
		}
		if (countered == false)
			return (true);
	}
	this->countLeftTop(y, x, val, count1);
	this->countRightBottom(y, x, val, count2);
	if (count1 + count2 + 1 >= NB_STONE_WIN)
	{
		for (x_tmp = x - count1, y_tmp = y - count1; countered == false && x_tmp < x + count2; x_tmp++, y_tmp++)
		{
			if ((this->countTop(y_tmp, x_tmp, val, count_tmp1) ^ this->countBottom(y_tmp, x_tmp, val, count_tmp2))
					&& count_tmp1 + count_tmp2 == 1)
				countered = true;
			if ((this->countLeft(y_tmp, x_tmp, val, count_tmp1) ^ this->countRight(y_tmp, x_tmp, val, count_tmp2))
					&& count_tmp1 + count_tmp2 == 1)
				countered = true;
			if ((this->countTopRight(y_tmp, x_tmp, val, count_tmp1) ^ this->countBottomLeft(y_tmp, x_tmp, val, count_tmp2))
					&& count_tmp1 + count_tmp2 == 1)
				countered = true;
		}
		if (countered == false)
			return (true);
	}
	this->countTopRight(y, x, val, count1);
	this->countBottomLeft(y, x, val, count2);
	if (count1 + count2 + 1 >= NB_STONE_WIN)
	{
		for (x_tmp = x + count1, y_tmp = y - count1; countered == false && y_tmp < y + count2; x_tmp--, y_tmp++)
		{
			if ((this->countTop(y_tmp, x_tmp, val, count_tmp1) ^ this->countBottom(y_tmp, x_tmp, val, count_tmp2))
					&& count_tmp1 + count_tmp2 == 1)
				countered = true;
			if ((this->countLeftTop(y_tmp, x_tmp, val, count_tmp1) ^ this->countRightBottom(y_tmp, x_tmp, val, count_tmp2))
					&& count_tmp1 + count_tmp2 == 1)
				countered = true;
			if ((this->countLeft(y_tmp, x_tmp, val, count_tmp1) ^ this->countRight(y_tmp, x_tmp, val, count_tmp2))
					&& count_tmp1 + count_tmp2 == 1)
				countered = true;
		}
		if (countered == false)
			return (true);
	}
	return (capture.size() >= NB_WIN_CAPTURE ? true : false);
}