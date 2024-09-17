/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 21:23:43 by anovio-c          #+#    #+#             */
/*   Updated: 2024/09/11 20:44:12 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AMateria.hpp"

AMateria::AMateria() : _type("Default") {
	std::cout << "AMateria default constructor" << std::endl;
}

AMateria::AMateria(const std::string &type) : _type(type) {
	std::cout << "AMateria default parameterixed constructor" << std::endl;
}

AMateria::AMateria(const AMateria &src) {
	*this = src;
}

AMateria	&AMateria::operator=(const AMateria &src) {
	if (this != &src) {
		this->_type = src.getType();
	}
	return (*this);
}

const std::string	&AMateria::getType(void) const {
	return (this->_type);
}

void	AMateria::use(ICharacter &target) {
	(void)target;
	std::cout << "You can't use me directly!" << std::endl;
}

AMateria::~AMateria() {
	std::cout << "AMateria destructor" << std::endl;
}
