/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Gomoku.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 08:52:08 by fpasquer          #+#    #+#             */
/*   Updated: 2018/03/16 14:14:44 by amaindro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GOMOKU_HPP
# define GOMOKU_HPP

# define GET_VAL(cell) (char)cell
# define GET_PERM(cell) cell >> 8
# define SET_VAL(cell, val) (GET_PERM(cell) << 8) + val
# define SET_PERM(cell, perm) ((GET_PERM(cell) ^ perm) << 8) + GET_VAL(cell)
# define CLEAR_VAL(cell) SET_VAL(cell, 0)
# define CLEAR_PERM(cell) (0x0 << 8) + GET_VAL(cell)
# define CLEAR_PERM_PLAYER(cell, val, perm) SET_VAL(cell, val); SET_PERM(cell, (GET_PERM(cell) ^ perm))
# define PERM_UP(cell, perm) (((GET_PERM(cell) & perm) == 0) ? false : true)

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
# define CAN_NOT_PLAY1 0x1 //00000001
# define CAN_NOT_PLAY2 0x2 //00000010

typedef enum				e_way
{
	NONE = 0x0,
	LEFT = 0x1,
	LEFT_TOP = 0x2,
	TOP = 0x4,
	TOP_RIGHT = 0x8,
	RIGHT = 0x10,
	RIGHT_BOTTOM = 0x20,
	BOTTOM = 0x40,
	BOTTOM_LEFT = 0x80
}							t_way;

# define RELEVANT 0x400
# define RELEVANT_IA 0x800
# define UNSET_RELEVANT 0xBFF
# define UNSET_RELEVANT_IA 0x7FF

# define QUIT		"QUIT     "
# define IA			"IA       "
# define TIME_SPEND	"TIME     "
# define ERROR		"ERROR    "
# define LAN		"LAN      "
# define CONNECTED	"CONNECTED"
# define CONNECTED2	"CONNECTE2"

#endif
