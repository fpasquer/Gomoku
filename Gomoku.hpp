/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Gomoku.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 08:52:08 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/09 08:46:34 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GOMOKU_HPP
# define GOMOKU_HPP

/*
	OFFLINE 2 joueurs sur le meme plateau avec le meme processus
	ONLINE 1 joueur vs IA su serveur
	LAN 2 joueurs sur le meme plateau avec chacun leur processus
*/

typedef enum				e_type_online
{
	OFFLINE, ONLINE, LAN_TYPE
}							t_type_online;

# define SIZE_CMD 10
# define SIZE_GRID 19
# define MIN_DEEP 1
# define MAX_DEEP 10
# define EMPTY_CELL ' '
# define PLAYER1 'X'
# define PLAYER2 'O'
# define LAN_STR "LAN"

# define QUIT		"QUIT     "
# define IA			"IA       "
# define TIME_SPEND	"TIME     "
# define ERROR		"ERROR    "
# define LAN		"LAN      "

#endif