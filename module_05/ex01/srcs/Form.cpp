/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 21:50:24 by anovio-c          #+#    #+#             */
/*   Updated: 2024/09/21 20:42:49 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Form.hpp"

Form::Form(void)
	: _name("Default"), _signed(false), _gradeRequiredSign(150)
	, _gradeRequiredExec(150) {
		std::cout << "Form Default constructor called" << std::endl;
}

Form::Form(std::string name, int grade)
	: _name(name), _signed(false), _gradeRequiredSign(grade)
	, _gradeRequiredExec(grade) {
		if (grade < 1)
			throw Form::GradeTooLowException();
		else if (grade > 150)
			throw Form::GradeTooHighException();
}

Form::Form(const Form &src)
	: _name(src.getName()), _signed(src.getIfSigned())
	, _gradeRequiredSign(src.getGradeRequiredSign())
	, _gradeRequiredExec(src.getGradeRequiredExec()) {
		std::cout << "Copy constructor called." << std::endl;
}

Form	&Form::operator=(const Form &src) {
	if (this != &src) {
		this->_signed = src.getIfSigned();
	}
	return (*this);
}

Form::~Form(void) {
}

const std::string	Form::getName(void) const {
	return (this->_name);
}

bool	Form::getIfSigned(void) const {
	return (this->_signed);
}

int	Form::getGradeRequiredSign(void) const {
	return (this->_gradeRequiredSign);
}

int	Form::getGradeRequiredExec(void) const {
	return (this->_gradeRequiredExec);
}

void	Form::beSigned(const Bureaucrat src) {
	if (src.getGrade() > this->getGradeRequiredSign())
		throw Form::GradeTooLowException();
	std::cout << this->getName() << " form is signed by " << src.getName() << std::endl;
	this->_signed = true;
}

std::ostream	&operator<<(std::ostream &out, const Form &src) {
	out << "Form name: " << src.getName() << ".\n"
		<< "Signed: " << src.getIfSigned() << ".\n"
		<< "Grade required for sign: " << src.getGradeRequiredSign() << ".\n"
		<< "Grade required for execute: " << src.getGradeRequiredExec() << ".\n";
	return (out);
}
