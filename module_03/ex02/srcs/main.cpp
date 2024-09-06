/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 20:03:42 by anovio-c          #+#    #+#             */
/*   Updated: 2024/09/05 20:04:07 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"
#include "../inc/ScavTrap.hpp"
#include "../inc/FragTrap.hpp"

int main( void ) {
	// ClapTrap	Rayquaza("Rayquaza");
	// ClapTrap	RayquazaShiny = Rayquaza;
	// ClapTrap	RayquazaShinyHack[2];
	ScavTrap	snorlax("snorlax");
	FragTrap	cyndaquil("cyndaquil");
	
	for (int i = 0; i < 5; i++) {
		cyndaquil.attack("snorlax");
		snorlax.takeDamage(20);
	}
	cyndaquil.beRepaired(20);
	snorlax.beRepaired(20);
	cyndaquil.attack("snorlax");
	snorlax.guardGate();
	snorlax.guardGate();
	cyndaquil.highFivesGuys();
	return (0);
}
