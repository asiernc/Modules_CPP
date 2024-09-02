/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 20:39:01 by anovio-c          #+#    #+#             */
/*   Updated: 2024/09/02 11:42:21 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void) {
	Zombie	*zombie = NULL;
	Zombie	zombie_stack;

	zombie_stack.randomChump("stacker");
	zombie = Zombie::newZombie("heaper");
	delete zombie;
	return (0);
}
