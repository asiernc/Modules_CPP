/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 20:03:42 by anovio-c          #+#    #+#             */
/*   Updated: 2024/08/29 20:26:06 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"
#include "../inc/ScavTrap.hpp"

int main( void ) {
	ClapTrap Rayquaza("Rayquaza");
	ClapTrap RayquazaShiny = Rayquaza;
	ClapTrap RayquazaShinyHack[2];
	ScavTrap	Cyndaquil("Cyndaquil");
	
	Cyndaquil.attack("Dragon claw");
	Cyndaquil.takeDamage(10);
	Cyndaquil.takeDamage(20);
	Cyndaquil.beRepaired(20);
	Cyndaquil.takeDamage(20);
	Cyndaquil.guardGate();
	Cyndaquil.guardGate();
	return (0);
}
