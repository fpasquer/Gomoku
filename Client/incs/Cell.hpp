/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cell.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 20:27:05 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/06 21:04:57 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CELL_HPP
# define CELL_HPP

# include "../incs/Gomoku_client.hpp"
# include <string>
# include "Player.hpp"

class Cell
{
	public:
							Cell(void);
		bool				setVal(Player const &player);
		std::string			getVal(void) const;

	private:
		std::string			m_val;
};

#endif