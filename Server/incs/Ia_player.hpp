/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ia_player.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 14:29:31 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/14 15:31:56 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IA_PLAYER_HPP
# define IA_PLAYER_HPP

# include "../../Gomoku.hpp"
# include <stdlib.h>

class Ia_player
{
	public:
		static void			play(char grid[SIZE_GRID][SIZE_GRID], unsigned int const depth, unsigned int &x, unsigned int &y);
	
	private:
		static int			Max(char grid[SIZE_GRID][SIZE_GRID], unsigned int const depth);
		static int			Min(char grid[SIZE_GRID][SIZE_GRID], unsigned int const depth);
};

#endif
