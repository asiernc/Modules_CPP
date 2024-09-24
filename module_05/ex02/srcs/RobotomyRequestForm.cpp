/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 20:21:23 by anovio-c          #+#    #+#             */
/*   Updated: 2024/09/24 21:27:47 by anovio-c         ###   ########.fr       */
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
	std::cout << "Making some drilling noises" << std::endl;
	if (randomNum == 1)
		std::cout << this->_target << " has been robotomized successfully." << std::endl;
	else
		std::cout << "The robotomization has failed for " << this->_target << std::endl;
}

std::string	RobotomyRequestForm::getTarget(void) const {
	return this->_target;
}