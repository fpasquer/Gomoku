/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player_human.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 08:56:50 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/10 20:47:33 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HUMAIN_HPP
# define PLAYER_HUMAIN_HPP

# include "Player.hpp"
# include "Client.hpp"

typedef enum				e_type_connect
{
	OFFLINE, ONLINE, ONLINE_LAN
}							t_type_connect;

# define ONLINE_LAN_STR "LAN"

class Player_human : public Player
{
	public:
							Player_human(unsigned int const &x = 0, unsigned int const &y = 0, unsigned int const &deep = INIT_DEEP);
		bool				checkKeySelect(std::string const &key);
		unsigned int		getDeep(void) const;
		bool				moveLeft(void);
		bool				moveRight(void);
		bool				moveUp(void);
		bool				moveDown(void);
		bool				deepMore(void);
		bool				deepMinus(void);
		void				set_online(std::string const &addr, int const &port, std::string const &type_connect);
		t_type_connect		isOnline(void) const;
		ssize_t				send_to_server(void const *data, size_t const &len) const;
		ssize_t				read_from_server(void *data, size_t const &len) const;

	private:
		typedef struct		s_cmd
		{
			char			*key;
			bool			(Player_human::*f) (void);
		}					t_cmd;
		static t_cmd const	m_cmd[];
		bool				isSpace(void);
		unsigned int		m_deep;
		Client				m_client;
		t_type_connect		m_type_connect;
};

#endif