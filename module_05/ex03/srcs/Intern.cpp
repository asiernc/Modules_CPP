/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:18:43 by anovio-c          #+#    #+#             */
/*   Updated: 2024/09/26 19:52:21 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Intern.hpp"
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"

Intern::Intern(void) {
	
}

Intern::Intern(const Intern &src) {
	*this = src;
}

Intern &Intern::operator=(const Intern &src) {
	(void)src;
	return (*this);
}

Intern::~Intern(void) {
	
}

AForm *Intern::createShrubbery(std::string target) {
	return (new ShrubberyCreationForm(target));
}
AForm *Intern::createRobotomy(std::string target) {
	return (new RobotomyRequestForm(target));
}

AForm *Intern::createPresidential(std::string target) {
	return (new PresidentialPardonForm(target));
}

AForm	*Intern::makeForm(std::string formName, std::string formTarget) {
	AForm				*form = NULL;
	const std::string	formNames[] =
		{"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm				*(*formsfuncs[])(std::string target) =
		{&createShrubbery, &createRobotomy, &createPresidential};

	for (int i = 0; i < 3; i++) {
		if (formName == formNames[i]) {
			form = formsfuncs[i](formTarget);
			std::cout << "Intern creates form: " << form->getName() << std::endl;
			return (form);
		}
	}
	std::cout << RED << "Error creating form.. The form name '" << formName << "' is not correct." << std::endl;
	std::cout << "Please use for example: \"shruberry creation\"" << RESET << std::endl;
	return (NULL);
}
