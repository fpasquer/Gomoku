/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ia_player.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 14:29:31 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/21 14:52:13 by amaindro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IA_PLAYER_HPP
# define IA_PLAYER_HPP

# include "../../Gomoku.hpp"
# include "../incs/Grid.hpp"
# include <stdlib.h>

class Ia_player
{
	public:
		static void			play(short grid[SIZE_GRID][SIZE_GRID], unsigned int const depth, unsigned int &x, unsigned int &y);
	
	private:
		static int			Max(Grid &grid_class, unsigned int const depth, short grid[SIZE_GRID][SIZE_GRID]);
		static int			Min(Grid &grid_class, unsigned int const depth, short grid[SIZE_GRID][SIZE_GRID]);
};

#endif
