/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Gomoku_client.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 20:25:51 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/06 21:08:39 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GOMOKU_CLIENT_HPP
# define GOMOKU_CLIENT_HPP

# define SIZE_GRID 15
# define SIZE_BUFF 7
# define MIN_LINES SIZE_GRID * 2 + 1
# define MIN_COLS (SIZE_GRID * 4 + 1) * 2
# define EMPTY_CELL " "
# define KEY_ESC_ (char[]){27, 0, 0, 0, 0, 0, 0}
# define KEY_ARROW_RIGHT_ (char[]){27, 91, 67, 0, 0, 0, 0}
# define KEY_ARROW_DOWN_ (char[]){27, 91, 66, 0, 0, 0, 0}
# define KEY_ARROW_UP_ (char[]){27, 91, 65, 0, 0, 0, 0}
# define KEY_ARROW_LEFT_ (char[]){27, 91, 68, 0, 0, 0, 0}
# define KEY_SPACE_ (char[]){32, 0, 0, 0, 0, 0, 0}
# define MIN_PORT 1
# define MAX_PORT 0xffff

# include <ncurses.h>

#endif