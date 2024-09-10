/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 12:48:14 by anovio-c          #+#    #+#             */
/*   Updated: 2024/09/07 21:15:50 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

// Your Character must have a constructor taking its name as a parameter.
// Any copy (using copy constructor or copy assignment operator) of a
//  Character must be deep. During copy, the Materias of a Character
//  must be deleted before the new ones are added to their inventory.
//  Of course, the Materias must be deleted when a Character is
//  destroyed.
Character::Character() : _name("Default") {
	for (int i = 0; i < INVENTORY_SIZE; i++) {
		this->_inventory[i] = NULL;
	};
}

Character::Character(std::string &name) : _name(name) {
	for (int i = 0; i < INVENTORY_SIZE; i++) {
		this->_inventory[i] = NULL;
	};
}

Character::Character(const Character &src) {
	*this = src;
}

Character	&Character::operator=(const Character &src) {
	if (this != &src) {
		this->_name = src._name;
		for (int i = 0; i < INVENTORY_SIZE; i++) {
			if (this->_inventory[i])
				delete this->_inventory[i];
			if (src._inventory[i])
				this->_inventory[i] = src._inventory[i]->clone();
			else
				this->_inventory[i] = NULL;
		};
	}
	return (*this);
}

const std::string &Character::getName(void) const {
	return (this->_name);
}

void Character::equip(AMateria* m) {
	for (int i = 0; i < INVENTORY_SIZE; i++) {
		if (this->_inventory[i] == NULL) {
			this->_inventory[i] = m;
			std::cout << this->_name << "'s equips with " << m->getType() << " in index " << i << std::endl;
			return ;
		}
	}
	std::cout << this->_name << " cannot be equiped. His inventory is full." << std::endl;
}
void Character::unequip(int idx) {
	if (idx >= 0 && idx < INVENTORY_SIZE) {
		std::cout << this->_name << " unequip his materia " << this->_inventory[idx]->getType() << std::endl;
		// delete ?
		delete this->_inventory[idx];
		this->_inventory[idx] = NULL;
	}
	else
		std::cout << this->_name << " cannot be unequip. His index inventory is empty." << std::endl;
	
}
void Character::use(int idx, ICharacter &target) {
	if (this->_inventory[idx] != NULL) {
		std::cout << this->_name << "use his "
		<< this->_inventory[idx]->getType() <<
		"matter against " << target.getName() << std::endl;
	}
}

