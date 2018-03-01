/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CountStone.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 09:21:07 by fpasquer          #+#    #+#             */
/*   Updated: 2018/03/01 14:08:47 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COUNT_STONE_HPP
# define COUNT_STONE_HPP

# include "Cell.hpp"
# include <string>

class CountStone : public Cell
{
    public:
                            CountStone(void);
        bool				countLeft(unsigned int const y, unsigned int const x, short const val, unsigned int &count) const;
		bool				countRight(unsigned int const y, unsigned int const x, short const val, unsigned int &count) const;
		bool				countTop(unsigned int const y, unsigned int const x, short const val, unsigned int &count) const;
		bool				countBottom(unsigned int const y, unsigned int const x, short const val, unsigned int &count) const;
		bool				countLeftTop(unsigned int const y, unsigned int const x, short const val, unsigned int &count) const;
		bool				countRightBottom(unsigned int const y, unsigned int const x, short const val, unsigned int &count) const;
		bool				countTopRight(unsigned int const y, unsigned int const x, short const val, unsigned int &count) const;
		bool				countBottomLeft(unsigned int const y, unsigned int const x, short const val, unsigned int &count) const;

		bool				getLineNbStone(unsigned int const y, unsigned int const x, short const val, unsigned int &count) const;
		bool				getColNbStone(unsigned int const y, unsigned int const x, short const val, unsigned int &count) const;
		bool				getDiagLeftTopRightBottomNbStone(unsigned int const y, unsigned int const x, short const val, unsigned int &count) const;
		bool				getDiagRightTopLeftBottomNbStone(unsigned int const y, unsigned int const x, short const val, unsigned int &count) const;
};

#endif