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

#include "Cure.hpp"

Cure::Cure() : AMateria("Cure") {
}

Cure::Cure(const Cure &src) {
	*this = src;
}
Cure	&Cure::operator=(const Cure &src) {
	(void)src;
	return *this;
}

Cure::~Cure() {
}

Cure	*Cure::clone() const {
	return (new Cure());// new Cure(*this)?? 
}

void	Cure::use(ICharacter &target) {
	std::cout << "* heals " target.getName() << "' wounds *" << std::endl;
}