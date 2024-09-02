/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 12:59:30 by anovio-c          #+#    #+#             */
/*   Updated: 2024/08/10 13:25:07 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*Zombie::zombieHorde(int N, std::string name) {
	Zombie	*zombie;

	zombie = new Zombie[N];
	for (int i = 0; i < N; i++) {
		zombie[i].setName(name);
		zombie[i].announce();
	}
	return (zombie);
}
