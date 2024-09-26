/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:28:02 by anovio-c          #+#    #+#             */
/*   Updated: 2024/09/26 11:52:14 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept>
# include "AForm.hpp"

# define RESET   "\033[0m"
# define RED     "\033[31m"
# define YELLOW  "\033[33m"
# define LIGHT_BLUE "\033[36m"
# define GREEN   "\033[32m" 

class AForm;

class Bureaucrat {
	private:
		const std::string	_name;
		int			_grade;
	public:
		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw() {
					return ("Grade too high!");
				}
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw() {
					return ("Grade too low!");
				}
		};
		Bureaucrat(void);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &src);
		Bureaucrat	&operator=(const Bureaucrat &src);
		~Bureaucrat(void);

		std::string	getName(void) const;
		int			getGrade(void) const;
		void		incrementGrade(void);
		void		decrementGrade(void);
		void		signForm(AForm &form) const;
		
		void		executeForm(AForm const &form) const;
		// Lastly, add the executeForm(AForm const & form) member function
		// to the Bureau- crat. It must attempt to execute the form.
		// If it’s successful, print something like:
   		// 	<bureaucrat> executed <form>
		// If not, print an explicit error message.
};

std::ostream	&operator<<(std::ostream &out, Bureaucrat &src);

#endif
