/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 20:35:11 by anovio-c          #+#    #+#             */
/*   Updated: 2024/09/24 21:27:32 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ShrubberyCreationForm.hpp"
//# include "AForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void)
	: AForm("Shrubbery Creation", SIGN_GRADE, EXEC_GRADE), _target("Default") {
	
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("Shrubbery Creation", SIGN_GRADE, EXEC_GRADE), _target(target) {
	
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
	: AForm("Shrubbery Creation", SIGN_GRADE, EXEC_GRADE), _target(src._target + "_copy") {
	*this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void){
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src) {
	(void)src;
	return (*this);
}

std::string	ShrubberyCreationForm::getTarget(void) const {
	return (this->_target);
}

void	ShrubberyCreationForm::runForm(void) const {
	std::fstream	fileObj;
	std::string		filename;
	std::string		tree;
	
	filename = this->getTarget() + "_shrubbery";
	fileObj.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	fileObj.open(filename.c_str());
	tree =
		"     *\n"
        "    ***\n"
        "   *****\n"
        "  *******\n"
        " *********\n"
        "***********\n"
        "    |||\n"
        "    |||\n";
	fileObj << tree << std::endl;
}
