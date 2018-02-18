/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Gomoku.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 08:52:08 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/18 10:03:25 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GOMOKU_HPP
# define GOMOKU_HPP

# define SIZE_CMD 10
# define SIZE_GRID 19
# define MIN_DEEP 1
# define MAX_DEEP 10
# define EMPTY_CELL ' '
# define PLAYER1 'X'
# define PLAYER2 'O'
# define INIT_SOCK -1
# define NB_STONE_WIN 5
# define NB_WIN_CAPTURE 10
# define MASK_VAL_CELL 0x00FF
# define MASK_CAN_PLAY 0xFF00
# define CAN_NOT_PLAY1 0x1
# define CAN_NOT_PLAY2 0x2

# define QUIT		"QUIT     "
# define IA			"IA       "
# define TIME_SPEND	"TIME     "
# define ERROR		"ERROR    "
# define LAN		"LAN      "
# define CONNECTED	"CONNECTED"
# define CONNECTED2	"CONNECTE2"

#endif