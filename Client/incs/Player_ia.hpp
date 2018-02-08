/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player_ia.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 09:55:46 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/08 09:57:45 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_IA_HPP
# define PLAYER_IA_HPP

# include "Player.hpp"

class Player_ia : public Player
{
	public:
							Player_ia(unsigned int const &x = 0, unsigned int const &y = 0);

	public:
		bool				setX(unsigned int const &x);
		bool				setY(unsigned int const &y);
};

#endif