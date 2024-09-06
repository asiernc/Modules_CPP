/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 20:03:42 by anovio-c          #+#    #+#             */
/*   Updated: 2024/09/05 18:54:30 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"

int main( void ) {
	ClapTrap Rayquaza("Rayquaza");
	ClapTrap RayquazaShiny = Rayquaza;
	ClapTrap RayquazaShinyHack[2];
	
	Rayquaza.attack("Dragon claw");
	Rayquaza.takeDamage(10);
	Rayquaza.beRepaired(20);
	return (0);
}
