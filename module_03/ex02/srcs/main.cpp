/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 20:03:42 by anovio-c          #+#    #+#             */
/*   Updated: 2024/08/30 20:17:15 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"
#include "../inc/ScavTrap.hpp"
#include "../inc/FragTrap.hpp"

int main( void ) {
	ClapTrap	Rayquaza("Rayquaza");
	ClapTrap	RayquazaShiny = Rayquaza;
	ClapTrap	RayquazaShinyHack[2];
	ScavTrap	Snorlax("Snorlax");
	FragTrap	Cyndaquil("Cyndaquil");
	
	Snorlax.guardGate();
	Cyndaquil.attack("Ember");
	Cyndaquil.takeDamage(10);
	Cyndaquil.takeDamage(20);
	Cyndaquil.beRepaired(20);
	Cyndaquil.takeDamage(20);
	Cyndaquil.highFivesGuys();
	
	//Cyndaquil.guardGate();
	return (0);
}
