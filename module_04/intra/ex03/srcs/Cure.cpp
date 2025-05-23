/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 21:51:27 by anovio-c          #+#    #+#             */
/*   Updated: 2024/09/06 22:07:26 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
	std::cout << YELLOW << "Cure constructor called" << RESET << std::endl;
}

Cure::Cure(const Cure &src) : AMateria(src) {
}

Cure	&Cure::operator=(const Cure &src) {
	if (this != &src)
        AMateria::operator=(src); 
	return (*this);
}

Cure::~Cure() {
	std::cout << RED << "Cure Destructor called"<< RESET << std::endl;
}

Cure	*Cure::clone() const {
	return (new Cure(*this));
}

void	Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName() << "' wounds *" << std::endl;
}
