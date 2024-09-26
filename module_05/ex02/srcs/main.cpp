/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 20:25:07 by anovio-c          #+#    #+#             */
/*   Updated: 2024/09/25 20:33:50 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

int main(void) {
	Bureaucrat	zidane = Bureaucrat("Zidane", 40);
	ShrubberyCreationForm test1 = ShrubberyCreationForm("hola");
	
	//std::cout << zidaneContract << std::endl;
	try
	{
		for (int i = 0; i < 5; i++) {
			zidane.incrementGrade();
			std::cout << zidane << std::endl;
		}
	}
	catch (const std::exception &iepa)
	{
		std::cerr << "Error: " << iepa.what() << std::endl << std::endl;
	}
	//zidaneContract.beSigned(zidane);
	//std::cout << zidaneContract << std::endl;

	
	// for example, I don't know what exception
	// try
	// {
	// 	Bureaucrat person2 = Bureaucrat("Marvin", 0);
	// 	std::cout << person2 << std::endl;
	// }
	// catch (const std::exception &e)
	// {
	// 	std::cerr << "Error: " << e.what() << std::endl << std::endl;
	// }
	
	// try
	// {
	// 	Bureaucrat person1 = Bureaucrat("Iota", 140);
	// 	std::cout << person1 << std::endl;
	// 	Bureaucrat person2 = Bureaucrat("Ukelele", 45);
	// 	std::cout << person2 << std::endl;
	// 	Bureaucrat person3 = Bureaucrat("Dragonite", 167);
	// 	std::cout << person3 << std::endl;
	// 	Bureaucrat person4 = Bureaucrat("Jupiter", 189);
	// 	std::cout << person4 << std::endl;
	// }
	// catch(const Bureaucrat::GradeTooHighException &e)
	// {
	// 	std::cerr << "Error: " << e.what() << std::endl;
	// }
	// catch(const Bureaucrat::GradeTooLowException &e)
	// {
	// 	std::cerr << "Error: " << e.what() << std::endl;
	// }
	return (0);
}
