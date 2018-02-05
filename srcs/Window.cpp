/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 22:37:45 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/05 23:21:59 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Window.hpp"

							Window::Window(void)
{
	initscr();
	m_cols = COLS;
	m_lines = LINES;
	m_win_left = subwin(stdscr, LINES, COLS / 2, 0, 0);
	m_win_right = subwin(stdscr, LINES, COLS / 2, 0, COLS / 2);
	wclear(m_win_left);
	wclear(m_win_right);
	box(m_win_left, ACS_VLINE, ACS_HLINE);
	box(m_win_right, ACS_VLINE, ACS_HLINE);
	wrefresh(m_win_left);
	wrefresh(m_win_right);
	curs_set(false);
}

bool						Window::show(std::string const &left, std::string const &right)
{
	unsigned int			x;
	unsigned int			y;

	if (m_lines < MIN_LINES || m_cols < MIN_COLS)
		return (false);
	x = (m_cols - SIZE_GRID) / 2;
	y = (m_lines - SIZE_GRID) / 2;
	wclear(m_win_left);
	box(m_win_left, ACS_VLINE, ACS_HLINE);
	mvwprintw(m_win_left, 1, 1, left.c_str());
	wrefresh(m_win_left);
	return (true);
	mvwprintw(m_win_left, x, y, left.c_str());
	mvwprintw(m_win_right, x, y, right.c_str());
}

							Window::~Window(void)
{
	free(m_win_left);
	free(m_win_right);
	m_win_left = NULL;
	m_win_right = NULL;
	curs_set(true);
	endwin();
}