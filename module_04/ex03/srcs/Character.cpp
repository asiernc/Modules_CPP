/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 12:48:14 by anovio-c          #+#    #+#             */
/*   Updated: 2024/09/11 21:06:05 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name("Default") {
	for (int i = 0; i < INVENTORY_SIZE; i++) {
		this->_inventory[i] = NULL;
	};
}

Character::Character(const std::string &name) : _name(name) {
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

Character::~Character() {
	for (int i = 0; i < INVENTORY_SIZE; i++)
		if (this->_inventory[i])
			delete this->_inventory[i];
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
		// delete ? verificar previo
		delete this->_inventory[idx];
		this->_inventory[idx] = NULL;
	}
	else
		std::cout << this->_name << " cannot be unequip. His index inventory is empty." << std::endl;
	
}
void Character::use(int idx, ICharacter &target) {
	if (idx >= 0 && idx < INVENTORY_SIZE && this->_inventory[idx] != NULL)
		this->_inventory[idx]->use(target);
	else
		std::cout << "You can't use anything." << std::endl;
}
