/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:32:02 by anovio-c          #+#    #+#             */
/*   Updated: 2024/09/21 20:37:57 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"

Bureaucrat::Bureaucrat(void) : _name("default"), _grade(150) {
	std::cout << "Default Constructor called." << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) {
	std::cout << "Parameterixed Constructor called." << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	std::cout << name  << " with grade "<< grade << " was inserted in our database." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src._name), _grade(src._grade) {
	std::cout << "Copy Constructor called." << std::endl;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &src) {
	if (this != &src) {
		// name is constant ==> doesn't change.
		//this->_name = src.getName();
		this->_grade = src.getGrade();
	}
	return (*this);
}

Bureaucrat::~Bureaucrat(void) {
	std::cout << "Default destructor called." << std::endl;
}

std::string		Bureaucrat::getName(void) const {
	return (this->_name);
}

int	Bureaucrat::getGrade(void) const {
	return (this->_grade);
}

void	Bureaucrat::decrementGrade(void) {
	if (this->getGrade() + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

void	Bureaucrat::incrementGrade(void) {
	if (this->getGrade() - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::signForm(Form &form) const {
    if (form.getIfSigned()) {
        std::cout << this->_name << " cannot sign " << form.getName() << " because it is already signed." << std::endl;
    } else {
        try {
            form.beSigned(*this);
            std::cout << this->_name << " signed " << form.getName() << "." << std::endl;
        } catch (Form::GradeTooLowException &e) {
            std::cout << this->_name << " couldn't sign " << form.getName() << " because the lowest grade to sign is " << form.getGradeRequiredSign() << std::endl;
        }
    }
}

std::ostream	&operator<<(std::ostream &out, Bureaucrat &src) {
	out << src.getName() << ", bureaucrat grade " << src.getGrade() <<  ".";
	return (out);
}
