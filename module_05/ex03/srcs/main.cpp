/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 20:25:07 by anovio-c          #+#    #+#             */
/*   Updated: 2024/09/26 19:53:50 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "Intern.hpp"
# include <string>

static void	test1(void) {
	Bureaucrat	hasbulla = Bureaucrat("hasbulla", 1);
	Intern 		pichi = Intern();
	AForm 		*form1 = pichi.makeForm("robotomy request", "machu");
	pichi.makeForm("robotomy creator", "machu");
	try {
		form1->beSigned(hasbulla);
		hasbulla.executeForm(*form1);
	}
	catch (const std::exception &iepa)
	{
		std::cerr << "Error: " << iepa.what() << std::endl << std::endl;
	}
	delete form1;
}


int main(void) {
	test1();
	return (0);
}
