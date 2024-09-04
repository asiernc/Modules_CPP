/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 20:28:21 by anovio-c          #+#    #+#             */
/*   Updated: 2024/09/02 14:20:56 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>
# include <stdbool.h>

class Zombie {
	public:
		Zombie();
		void	setName(std::string name);
		void	announce(void);
		static	Zombie	*newZombie(std::string name);
		void	randomChump(std::string name);
		~Zombie();
	private:
		std::string	_name;

};

#endif
