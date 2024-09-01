/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 20:03:42 by anovio-c          #+#    #+#             */
/*   Updated: 2024/08/29 20:04:22 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"

int main( void ) {
	ClapTrap Rayquaza("Rayquaza");
	ClapTrap RayquazaShiny = Rayquaza;
	ClapTrap RayquazaShinyHack[2];
	
	Rayquaza.attack("Dragon claw");
	Rayquaza.takeDamage(10);
	Rayquaza.takeDamage(20);
	Rayquaza.beRepaired(20);
	Rayquaza.takeDamage(20);
	return (0);
}
