/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 20:03:42 by anovio-c          #+#    #+#             */
/*   Updated: 2024/09/05 19:27:23 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"
#include "../inc/ScavTrap.hpp"

int main( void ) {
	//ClapTrap Rayquaza("Rayquaza");
	//ClapTrap RayquazaShiny = Rayquaza;
	//ClapTrap RayquazaShinyHack[2];
	ScavTrap	cyndaquil("cyndaquil");
	ScavTrap	charizard("charizard");
	
	for (int i = 0; i < 5; i++) {
		cyndaquil.attack("Charizard");
		charizard.takeDamage(20);
	}
	cyndaquil.beRepaired(20);
	charizard.beRepaired(20);
	cyndaquil.setHitPoints(0);
	cyndaquil.attack("chikorita");
	cyndaquil.guardGate();
	cyndaquil.guardGate();
	return (0);
}
