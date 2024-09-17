/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 21:51:27 by anovio-c          #+#    #+#             */
/*   Updated: 2024/09/11 20:59:48 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
}

Ice::Ice(const Ice &src) : AMateria(src) {
}

Ice	&Ice::operator=(const Ice &src) {
	(void)src;
	return *this;
}

Ice::~Ice() {
}

Ice	*Ice::clone() const {
	return (new Ice(*this));
}

void	Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
