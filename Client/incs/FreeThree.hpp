/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FreeThree.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 13:21:16 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/14 15:45:53 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_THREE_HPP
# define FREE_THREE_HPP

# include "Player.hpp"
# include "Grid.hpp"

class FreeThree
{
	public:
							FreeThree(Grid const &grid, Player const &player);
		bool				checkFreeThree(void);

	private:
		typedef struct		s_checkFreeT
		{
			bool			(FreeThree::*f)(void);
		}					t_checkFreet;
		static t_checkFreet const
							m_func[];
		Grid const			m_grid;
		Player const		m_player;
		bool				checkFTLeft(void);
		bool				checkFTTopLeft(void);
		bool				checkFTTop(void);
		bool				checkFTTopRight(void);
		bool				checkFTRight(void);
		bool				checkFTBottom(void);
		bool				checkFTBottomRight(void);
		bool				checkFTBottomLeft(void);
};

#endif