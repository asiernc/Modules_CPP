/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 21:32:48 by anovio-c          #+#    #+#             */
/*   Updated: 2024/09/22 19:53:06 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <stdbool.h>
# include <stdexcept>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
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
		class FormNotSigned : public std::exception {
			public:
				virtual const char *what() const throw() {
					return ("Form has not been signed yet.");
				}
		};
		AForm(void);
		AForm(std::string name, int gradeSign, int gradeExec);
		AForm(const AForm &src);
		AForm	&operator=(const AForm &src);
		virtual ~AForm(void);

		const std::string	getName(void) const;
		bool				getIfSigned(void) const;
		int					getGradeRequiredSign(void) const;
		int					getGradeRequiredExec(void) const;
		// si la funcion de una clase va a ser abstracta, para que la pueda
		// utilizar otra clase recuerda! ha de ser virtual pura ==> virtual (..) = 0
		void				execute(Bureaucrat const &executor) const;
		virtual void		beSigned(const Bureaucrat src);
		
		//static AForm		*makeForm(std::string formName, std::string formTarget);
		virtual void		runForm(void) const = 0;
};

std::ostream	&operator<<(std::ostream &out, const AForm &src);

#endif
