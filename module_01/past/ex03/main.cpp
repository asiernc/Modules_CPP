/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 13:06:43 by anovio-c          #+#    #+#             */
/*   Updated: 2024/08/14 21:13:36 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	{
		Weapon club = Weapon("Charizard");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("Pikachu");
		bob.attack();
	}
	{
		Weapon club = Weapon("Torchic");
		HumanB jim("Jim");
		jim.attack();
		jim.setWeapon(club);
		jim.attack();
		club.setType("Rayquaza");
		jim.attack();
	}
	return (0);
}

