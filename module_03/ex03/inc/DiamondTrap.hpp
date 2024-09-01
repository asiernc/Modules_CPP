/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 20:39:45 by anovio-c          #+#    #+#             */
/*   Updated: 2024/08/28 21:38:49 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_H
# define DIAMONDTRAP_H

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

// Diamondtrap, tiene como objetivo ser un objeto que hereda un solo subobjeto de ClapTrap 
// mezcla de ScavTrap y FragTrap.
// un objeto que tiene dos subobjetos distintos de clase ClapTrap, uno a traves de ScavTrap
// y otro a traves de FragTrap.
// Lo que se puede hacer es utilizar la palabra "virtual" delante de los especificadores
// de la clase de ambos, para indidcar que solo existe un subobjeto de ClapTrap compartido
// por estos dos. ex =
	//1		=== class ScavTrap : public ClapTrap ==> heredaba un subobjeto de ClapTrap,
	//		--------------------------------------------------------------------
	//2			class ScavTrap : virtual public ClapTrap
	// 			class FragTrap : virtual public ClapTrap   ==> indica que solo existe un
														// 	   solo subobjeto ClapTrap.

class DiamondTrap : public ScavTrap, public FragTrap {
	private:
		std::string _name;
	public:
		DiamondTrap(void);
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &src);
		DiamondTrap	&operator=(const DiamondTrap &src);
		~DiamondTrap(void);
		
		using ScavTrap::attack;
		void	whoAmI(void);
};

#endif
