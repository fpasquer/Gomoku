/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ia_player.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 14:29:31 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/26 14:40:09 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IA_PLAYER_HPP
# define IA_PLAYER_HPP

# include "../../Gomoku.hpp"
# include <stdlib.h>
# include "CountWin.hpp"
# include <iostream>

class Ia_player
{
	public:
		static void			play(short grid[SIZE_GRID][SIZE_GRID], unsigned int &x, unsigned int &y, int const depth);
	
	private:
							Ia_player(short grid[SIZE_GRID][SIZE_GRID]);
		short				m_grid[SIZE_GRID][SIZE_GRID];
		static int const	start_min;
		static int const	start_max;
		static int const	win;
		bool				haveWin(unsigned int const y, unsigned int const x, short const val) const;
		int					eval(bool const retHaveWin, char const player, int const depth) const;
		int					max(int const depth, unsigned int const y, unsigned int const x);
		int					min(int const depth, unsigned int const y, unsigned int const x);
		void				show(unsigned int const y, unsigned int const x) const;
};

#endif
