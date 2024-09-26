/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 20:21:23 by anovio-c          #+#    #+#             */
/*   Updated: 2024/09/23 20:45:37 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void)
	: AForm("Presidential Pardon", SIGN_GRADE, EXEC_GRADE), _target("Default") {
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: AForm("Presidential Pardon", SIGN_GRADE, EXEC_GRADE), _target(target) {
		std::cout << "Presidential Pardon Form Form is created with sign grade: "
			<< SIGN_GRADE << " and exec grade: " << EXEC_GRADE << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src)
	: AForm("Presidential Pardon", SIGN_GRADE, EXEC_GRADE), _target(src.getName() + "_copy") {
		*this = src;
	}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &src) {
		(void)src;
		return *this;
	}

PresidentialPardonForm::~PresidentialPardonForm(void) {
	
}

std::string	PresidentialPardonForm::getTarget(void) const {
	return this->_target;
}

void	PresidentialPardonForm::runForm(void) const{
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
