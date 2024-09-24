/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 21:50:24 by anovio-c          #+#    #+#             */
/*   Updated: 2024/09/24 21:14:55 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AForm.hpp"

AForm::AForm(void)
	: _name("Default"), _signed(false), _gradeRequiredSign(150)
	, _gradeRequiredExec(150) {
		std::cout << "AForm Default constructor called" << std::endl;
}

AForm::AForm(std::string name, int gradeSign, int gradeExec)
	: _name(name), _signed(false), _gradeRequiredSign(gradeSign)
	, _gradeRequiredExec(gradeExec) {
		if (gradeSign < 1 || gradeExec < 1)
			throw AForm::GradeTooLowException();
		else if (gradeSign > 150 || gradeExec > 150)
			throw AForm::GradeTooHighException();
}

AForm::AForm(const AForm &src)
	: _name(src.getName()), _signed(src.getIfSigned())
	, _gradeRequiredSign(src.getGradeRequiredSign())
	, _gradeRequiredExec(src.getGradeRequiredExec()) {
		std::cout << "Copy constructor called." << std::endl;
}

AForm	&AForm::operator=(const AForm &src) {
	if (this != &src) {
		this->_signed = src.getIfSigned();
	}
	return (*this);
}

AForm::~AForm(void) {
}

const std::string	AForm::getName(void) const {
	return (this->_name);
}

bool	AForm::getIfSigned(void) const {
	return (this->_signed);
}

int	AForm::getGradeRequiredSign(void) const {
	return (this->_gradeRequiredSign);
}

int	AForm::getGradeRequiredExec(void) const {
	return (this->_gradeRequiredExec);
}

void	AForm::beSigned(const Bureaucrat src) {
	if (src.getGrade() > this->getGradeRequiredSign())
		throw AForm::GradeTooLowException();
	std::cout << this->getName() << " Aform is signed by " << src.getName() << std::endl;
	this->_signed = true;
}

void	AForm::execute(Bureaucrat const &executor) const {
	// if form is signed, and bureucrat have grade to exec, execute
	if (this->getIfSigned() == false)
		throw AForm::FormNotSigned();
	if (executor.getGrade() > this->getGradeRequiredExec())
		throw AForm::GradeTooLowException();
	this->runForm();
	// para que una clase abstracta pueda llamar a funciones
	// que seran de sus objetos propios, no los que hereda de AForm
	// cada uno tiene su funcion runForm, para que se pueda llamar desde
	// AForm, deben de ser todas las runForm virtuales, y pura la de la abstracta
}

std::ostream	&operator<<(std::ostream &out, const AForm &src) {
	out << "AForm name: " << src.getName() << ".\n"
		<< "Signed: " << src.getIfSigned() << ".\n"
		<< "Grade required for sign: " << src.getGradeRequiredSign() << ".\n"
		<< "Grade required for execute: " << src.getGradeRequiredExec() << ".\n";
	return (out);
}
