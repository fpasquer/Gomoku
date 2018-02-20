/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FreeThree.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 13:21:16 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/20 11:01:35 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_THREE_HPP
# define FREE_THREE_HPP

# include "Player.hpp"
# include "Grid.hpp"

class FreeThree
{
	public:
							FreeThree(Grid const &grid);
		bool				checkFreeThree(unsigned int const y, unsigned int const x, short const val) const;

	private:
		typedef struct		s_checkFreeT
		{
			bool			(FreeThree::*f)(unsigned const int, unsigned const int, short const) const;
		}					t_checkFreet;
		static t_checkFreet const
							m_func[];
		Grid const			m_grid;
		bool				checkFTLeft(unsigned const int y_tmp, unsigned const int x_tmp, short const val) const;
		bool				checkFTTopLeft(unsigned const int y_tmp, unsigned const int x_tmp, short const val) const;
		bool				checkFTTop(unsigned const int y_tmp, unsigned const int x_tmp, short const val) const;
		bool				checkFTTopRight(unsigned const int y_tmp, unsigned const int x_tmp, short const val) const;
		bool				checkFTRight(unsigned const int y_tmp, unsigned const int x_tmp, short const val) const;
		bool				checkFTBottomRight(unsigned const int y_tmp, unsigned const int x_tmp, short const val) const;
		bool				checkFTBottom(unsigned const int y_tmp, unsigned const int x_tmp, short const val) const;
		bool				checkFTBottomLeft(unsigned const int y_tmp, unsigned const int x_tmp, short const val) const;
};

#endif