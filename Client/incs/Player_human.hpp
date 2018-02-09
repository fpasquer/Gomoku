/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player_human.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 08:56:50 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/09 08:59:56 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HUMAIN_HPP
# define PLAYER_HUMAIN_HPP

# include "Player.hpp"
# include "Client.hpp"

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
		void				enable(void);
		void				disable(void);
		bool				isEnable(void) const;
		void				set_online(std::string const &addr, int const &port, std::string const &type_online);
		t_type_online		isOnline(void) const;
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
		bool				m_enable;
		t_type_online		m_type_online;
};

#endif