/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 20:03:42 by anovio-c          #+#    #+#             */
/*   Updated: 2024/09/05 20:08:24 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"
#include "../inc/ScavTrap.hpp"
#include "../inc/FragTrap.hpp"
#include "../inc/DiamondTrap.hpp"

int main( void ) {
	DiamondTrap	Groudon = DiamondTrap("groudon");
	
	Groudon.attack("Ember");
	Groudon.whoAmI();
	return (0);
}
