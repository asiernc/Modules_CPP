/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 20:32:11 by anovio-c          #+#    #+#             */
/*   Updated: 2024/09/25 16:05:11 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"

Dog::Dog() : AAnimal() {
	std::cout << "Dog default constructor called" << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain();
}

Dog::Dog(const Dog &src) : AAnimal("dog") {
	std::cout << "Dog copy constructor called" << std::endl;
	*this = src;
	// aqui ya se esta llamando al operator= this no tiene brain, no
	// se ha inicializado
	// delete _brain;
	//this->_brain = new Brain(*src._brain);
}

Dog &Dog::operator=(const Dog &src) {
	std::cout << "Dog equal operator called" << std::endl;
	if (this != &src)
	{
		this->_type = src._type;
		this->_brain = new Brain(*src._brain);
	}
	return (*this);
}

Dog::~Dog() {
	// delete calls brain destructor!!! brain destructor is in
	// charge of releasing the array of ideas of brain
	delete this->_brain;
	std::cout << "Dog destructor called" << std::endl;
}

std::string Dog::getType(void) const {
	return (this->_type);
}

/*void Dog::makeSound() const {
	std::cout << "Woof Woof!" << std::endl;
}*/

void Dog::setIdea(int index, const std::string &idea) {
	this->_brain->setIdea(index, idea);
}

std::string Dog::getIdea(int index) {
	return (this->_brain->getIdea(index));
}
