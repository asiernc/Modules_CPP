/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 20:25:39 by anovio-c          #+#    #+#             */
/*   Updated: 2024/09/11 20:22:29 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"

Cat::Cat() : AAnimal() {
	std::cout << "Cat default constructor called" << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain();
}

Cat::Cat(const Cat &src) : AAnimal("cat") {
	std::cout << "Cat copy constructor called" << std::endl;
	*this = src;
}

Cat	&Cat::operator=(const Cat &src) {
	std::cout << "Cat equal operator called" << std::endl;
	if (this != &src) {
		this->_type = src._type;
		this->_brain = new Brain(*src._brain);
		// quiero una copia del objeto, no una copia del puntero
		// por eso se hace *src._brain, y no src._brain,
		// si es con . y no con -> es porque lo que obtenemos 
		// es una referencia de src no un puntero.
	}
	return (*this);
}

Cat::~Cat() {
	delete this->_brain;
	std::cout << "Cat destructor called" << std::endl;
}

std::string	Cat::getType(void) const {
	return (this->_type);
}

void	Cat::makeSound() const {
	std::cout << "Meeeeoooooooow!" << std::endl;
}

void	Cat::setIdea(int index, const std::string &idea) {
	this->_brain->setIdea(index, idea);
}

std::string	Cat::getIdea(int index) {
	return (this->_brain->getIdea(index));
}
