/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 20:25:39 by anovio-c          #+#    #+#             */
/*   Updated: 2024/09/04 10:35:28 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"

Cat::Cat() : Animal() {
	std::cout << "Cat default constructor called" << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain();
}

Cat::Cat(const Cat &src) : Animal() {
	std::cout << "Cat copy constructor called" << std::endl;
	this->_brain = new Brain(*src._brain);
}

Cat	&Cat::operator=(const Cat &src) {
	std::cout << "Cat equal operator called" << std::endl;
	if (this != &src) {
		Animal::operator=(src);
		delete this->_brain;
		this->_brain = new Brain(*src._brain);
		// quiero una copia del objeto, no una copia del puntero
		// por eso se hace *src._brain, y no src._brain,
		// si es con . y no con -> es porque lo que obtenemos 
		// es una referencia de src no un puntero.
	}
	return (*this);
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
}

std::string	Cat::getType(void) const {
	return (this->_type);
}

void	Cat::makeSound() const {
	std::cout << "Meeeeoooooooow!" << std::endl;
}

Brain	*Cat::getBrain() const {
	return (this->_brain);
}

void	Cat::setIdea(int index, std::string idea) {
	this->_brain->setIdea(index, idea);
}

std::string	Cat::getIdea(int index) {
	return (this->_brain->getIdea(index));
}
