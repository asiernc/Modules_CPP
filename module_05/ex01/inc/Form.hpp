/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 21:32:48 by anovio-c          #+#    #+#             */
/*   Updated: 2024/09/21 20:36:03 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <stdbool.h>
# include <stdexcept>
# include "Bureaucrat.hpp"

// Now that you have bureaucrats, let’s give them something to do. What better
// activity could there be than the one of filling out a stack of forms?
// Then, let’s make a Form class. It has:
// • A constant name.
// • A boolean indicating whether it is signed (at construction, it’s not).
// • A constant grade required to sign it.
// • And a constant grade required to execute it.
// All these attributes are private, not protected.
// The grades of the Form follow the same rules that apply to the Bureaucrat.
// Thus, the following exceptions will be thrown if a form grade is out of bounds:
// 	Form::GradeTooHighException and Form::GradeTooLowException.
// Same as before, write getters for all attributes and an overload of the
// insertion («) operator that prints all the form’s informations.
// Add also a beSigned() member function to the Form that takes a Bureaucrat 
// as parameter. It changes the form status to signed if the bureaucrat’s grade 
// is high enough (higher or egal to the required one). Remember, grade 1 is higher
//  than grade 2.
// If the grade is too low, throw a Form::GradeTooLowException.
// Lastly, add a signForm() member function to the Bureaucrat. If the form got 
// signed, it will print something like:
//    <bureaucrat> signed <form>
// Otherwise, it will print something like:
// <bureaucrat> couldn’t sign <form> because <reason>.
// Implement and turn in some tests to ensure everything works as expected.

class Bureaucrat;

class Form {
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeRequiredSign;
		const int			_gradeRequiredExec;
	public:
		class GradeTooHighException : public std::exception {
			public: 
				const char *what() const throw () {
					return ("Grade too high!");
				}
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw () {
					return ("Grade too low!");
				}
		};
		Form(void);
		Form(std::string name, int grade);
		Form(const Form &src);
		Form	&operator=(const Form &src);
		~Form(void);

		const std::string	getName(void) const;
		bool				getIfSigned(void) const;
		int			getGradeRequiredSign(void) const;
		int			getGradeRequiredExec(void) const;

		void				beSigned(const Bureaucrat src);
};

std::ostream	&operator<<(std::ostream &out, const Form &src);

#endif
