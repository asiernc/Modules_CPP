/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 13:06:43 by anovio-c          #+#    #+#             */
/*   Updated: 2024/08/10 19:28:14 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie	*zombie = NULL;

	zombie = Zombie::zombieHorde(5, "shreck");
	std::cout << "Pointer direction of zombie horde is:"
		<< &zombie
		<< std::endl;
	delete [] zombie;
	return (0);
}
