/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CountWin.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 11:47:10 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/26 12:36:02 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COUNT_WIN_HPP
# define COUNT_WIN_HPP

# include "../../Gomoku.hpp"

class CountWin
{
	public:
		static bool			countLeft(short const grid[SIZE_GRID][SIZE_GRID], unsigned int const y, unsigned int const x, short const val, unsigned int &count);
		static bool			countRight(short const grid[SIZE_GRID][SIZE_GRID], unsigned int const y, unsigned int const x, short const val, unsigned int &count);
		static bool			countTop(short const grid[SIZE_GRID][SIZE_GRID], unsigned int const y, unsigned int const x, short const val, unsigned int &count);
		static bool			countBottom(short const grid[SIZE_GRID][SIZE_GRID], unsigned int const y, unsigned int const x, short const val, unsigned int &count);
		static bool			countLeftTop(short const grid[SIZE_GRID][SIZE_GRID], unsigned int const y, unsigned int const x, short const val, unsigned int &count);
		static bool			countRightBottom(short const grid[SIZE_GRID][SIZE_GRID], unsigned int const y, unsigned int const x, short const val, unsigned int &count);
		static bool			countTopRight(short const grid[SIZE_GRID][SIZE_GRID], unsigned int const y, unsigned int const x, short const val, unsigned int &count);
		static bool			countBottomLeft(short const grid[SIZE_GRID][SIZE_GRID], unsigned int const y, unsigned int const x, short const val, unsigned int &count);
};

#endif