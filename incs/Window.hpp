/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 22:37:42 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/05 23:01:17 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_HPP
# define WINDOW_HPP

# include <ncurses.h>
# include <stdlib.h>
# include <string>
# include "Gomoku.hpp"

class Window
{
	public:
							Window(void);
		bool				show(std::string const &left, std::string const &right);
							~Window(void);
	public:
		unsigned int		m_cols;
		unsigned int		m_lines;
		WINDOW				*m_win_left;
		WINDOW				*m_win_right;
};

#endif