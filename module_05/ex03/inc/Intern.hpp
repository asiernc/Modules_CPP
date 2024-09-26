/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:05:59 by anovio-c          #+#    #+#             */
/*   Updated: 2024/09/26 18:43:25 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include "AForm.hpp"

class Intern {
	public:
		Intern(void);
		Intern(const Intern &src);
		Intern	&operator=(const Intern &src);
		~Intern(void);

		class FormCreateError : public std::exception {
			const char *what() const throw() {
				return ("Error creating the form...");
			}
		};
		// static functions not need a instance to run.
		static AForm *createShrubbery(std::string target);
		static AForm *createRobotomy(std::string target);
		static AForm *createPresidential(std::string target);
		AForm *makeForm(std::string formName, std::string formTarget);
};
