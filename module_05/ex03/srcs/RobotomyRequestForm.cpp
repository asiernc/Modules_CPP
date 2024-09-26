/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 20:21:23 by anovio-c          #+#    #+#             */
/*   Updated: 2024/09/26 18:51:26 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RobotomyRequestForm.hpp"
# include <cstdlib>
# include <ctime>

RobotomyRequestForm::RobotomyRequestForm(void)
	: AForm("Robotomy Request", SIGN_GRADE, EXEC_GRADE), _target("Default") {
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm("Robotomy Request", SIGN_GRADE, EXEC_GRADE), _target(target) {
		std::cout << "Robotomy Request Form is created with sign grade: "
		<< SIGN_GRADE << " and exec grade: " << EXEC_GRADE << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
	: AForm("Robotomy Request", SIGN_GRADE, EXEC_GRADE), _target(src.getName() + "_copy") {
		*this = src;
	}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &src) {
		(void)src;
		return *this;
	}

RobotomyRequestForm::~RobotomyRequestForm(void) {
	
}

void	RobotomyRequestForm::runForm(void) const {
	// Semilla para la generación de números aleatorios
    std::srand(std::time(0));
    // Generar un número aleatorio entre 1 y 2
    int randomNum = std::rand() % 2 + 1;
	
	std::cout << LIGHT_BLUE << "Making some drilling noises" << RESET << std::endl;
	if (randomNum == 1)
		std::cout << GREEN << this->_target << " has been robotomized successfully." << RESET << std::endl;
	else
		std::cout << RED << "The robotomization has failed for " << this->_target << RESET << std::endl;
}

std::string	RobotomyRequestForm::getTarget(void) const {
	return this->_target;
}
