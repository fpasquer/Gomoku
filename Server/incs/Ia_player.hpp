/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ia_player.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 14:29:31 by fpasquer          #+#    #+#             */
/*   Updated: 2018/03/15 08:58:42 by amaindro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IA_PLAYER_HPP
# define IA_PLAYER_HPP

# include "../../Tools_incs/Gomoku.hpp"
# include <stdlib.h>
# include "CountWin.hpp"
# include <iostream>
# include "Grid.hpp"

class Ia_player
{
	public:
		static void			play(Grid &grid, unsigned int &x,
				unsigned int &y);
	
	private:
							Ia_player(Grid &grid);
		Grid				&m_grid;
		static int const	start_min;
		static int const	start_max;
		static int const	win;
		bool				haveWin(unsigned int const y, unsigned int const x, short const val) const;
		int					eval(bool const retHaveWin, char const player, int const depth) const;
		int					max(int const depth, unsigned int const y, unsigned int const x, int prev_branch);
		int					min(int const depth, unsigned int const y, unsigned int const x, int prev_branch);
		void				show(unsigned int const line, unsigned int const y, unsigned int const x, int const max) const;
};

#endif
