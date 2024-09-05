/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 20:32:11 by anovio-c          #+#    #+#             */
/*   Updated: 2024/09/04 21:27:17 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"


Dog::Dog() : AAnimal() {
	std::cout << "Dog default constructor called" << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain();
}

Dog::Dog(const Dog &src) : AAnimal("Dog") {
	std::cout << "Dog copy constructor called" << std::endl;
	*this = src;
	this->_brain = new Brain(*src._brain);
}

Dog	&Dog::operator=(const Dog &src) {
	std::cout << "Dog equal operator called" << std::endl;
	if (this != &src) {
		AAnimal::operator=(src);
		delete this->_brain;
		this->_brain = new Brain(*src._brain);
	}
	return (*this);
}

Dog::~Dog() {
	delete this->_brain;
	std::cout << "Dog destructor called" << std::endl;
}

std::string	Dog::getType(void) {
	return (this->_type);
}

void	Dog::makeSound() const{
	std::cout << "Woof Woof!" << std::endl;
}

void	Dog::setIdea(int index, const std::string &idea) {
	this->_brain->setIdea(index, idea);
}

std::string	Dog::getIdea(int index) {
	return (this->_brain->getIdea(index));
}
