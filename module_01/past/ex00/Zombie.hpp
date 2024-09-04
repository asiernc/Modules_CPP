/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 20:28:21 by anovio-c          #+#    #+#             */
/*   Updated: 2024/08/09 21:27:10 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// • Zombie* newZombie( std::string name );
// It creates a zombie, name it, and return it so you can use it outside of the function scope.
// • void randomChump( std::string name );
// It creates a zombie, name it, and the zombie announces itself.

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
