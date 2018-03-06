/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Grid.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 07:57:19 by fpasquer          #+#    #+#             */
/*   Updated: 2018/03/06 10:41:20 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRID_HPP
# define GRID_HPP

# include "../../Tools_incs/Captures.hpp"
# include "../../Tools_incs/Gomoku.hpp"
# include "../../Tools_incs/HaveWin.hpp"
# include "Client.hpp"
# include <string>

class Grid :  public Captures , public HaveWin
{
	public:
							Grid(void);
		bool				readInfoGrid(Client const & player);
		bool				setValue(short const val, unsigned int const y, unsigned int const x, char *way_capture);
		bool				unsetValueAgent(std::string *ptr, char const flag_way,
				short const val, unsigned int const y1, unsigned int const x1,
				unsigned int const y2, unsigned int const x2, char const way_captures);
		bool				unsetValue(short const val, unsigned int const y, unsigned int const x, char const way_capture);
		unsigned int		getDepth(void) const;
		std::string			getNbCaptureIa(void) const;
		std::string			getNbCapturePlayer(void) const;
		void				show(unsigned int const y, unsigned int const x) const;

	private:
		unsigned int		m_depth;
		std::string			m_nb_capture_ia;
		std::string			m_nb_capture_player;
};

#endif