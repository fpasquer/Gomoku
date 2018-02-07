/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cell.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 20:27:05 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/07 11:35:50 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CELL_HPP
# define CELL_HPP

# include "../incs/Gomoku_client.hpp"
# include "Player.hpp"

class Cell
{
	public:
							Cell(void);
		bool				setVal(Player const &player);
		bool				setVal(char const &c);
		char				getVal(void) const;

	private:
		char				m_val;
};

#endif