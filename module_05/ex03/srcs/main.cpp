/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 20:25:07 by anovio-c          #+#    #+#             */
/*   Updated: 2024/09/26 14:48:01 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include <string>

static void	test1(void) {
	Bureaucrat	zidane = Bureaucrat("Zidane", 149);
	ShrubberyCreationForm test1 = ShrubberyCreationForm("hola");
	
	try
	{
		test1.beSigned(zidane);
	}
	catch (const std::exception &iepa)
	{
		std::cerr << "Error: " << iepa.what() << std::endl << std::endl;
	}
}

static void test2(void) {
	Bureaucrat eto = Bureaucrat("eto", 30);
	RobotomyRequestForm *form = new RobotomyRequestForm("eto");
	
	for (int i = 0; eto.getGrade() > form->getGradeRequiredSign(); i++) {
		eto.incrementGrade();
		std::cout << YELLOW << eto << RESET << std::endl;
	}
	try {
		form->beSigned(eto);
		if (form->getIfSigned() == true) {
			try {
				form->execute(eto);
			}
			catch (std::exception &hola) {
				std::cerr << "Error: " << hola.what() << std::endl;
			}
		}
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	for (int i = 0; eto.getGrade() > form->getGradeRequiredExec(); i++) {
		eto.incrementGrade();
		std::cout << YELLOW << eto << RESET << std::endl;
	}
	try {
		if (form->getIfSigned() == true) {
			try {
				form->execute(eto);
			}
			catch (std::exception &hola) {
				std::cerr << "Error: " << hola.what() << std::endl;
			}
		}
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	delete form;
}

static void test3(void) {
	Bureaucrat eto = Bureaucrat("eto", 30);
	ShrubberyCreationForm *form = new ShrubberyCreationForm("eto");
	
	try {
		form->beSigned(eto);
		if (form->getIfSigned() == true) {
			try {
				form->execute(eto);
			}
			catch (std::exception &hola) {
				std::cerr << "Error: " << hola.what() << std::endl;
			}
		}
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	delete form;
}

static void test4(void) {
	Bureaucrat eto = Bureaucrat("eto", 130);
	PresidentialPardonForm *form = new PresidentialPardonForm("eto");
	
	try {
		form->beSigned(eto);
		if (form->getIfSigned() == true)
			eto.executeForm(*form);
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	delete form;
}

/*int	test5(void) {
	std::string	str;
	std::string name;
	int			grade;
	
	std::cout << "Write Bureaucrat name: " << std::endl;
	if (std::getline(std::cin, str) && str != "") {
		name = str;
	}
	std::cout << "Write Bureaucrat grade (Hint: 1~150): " << std::endl;
	if (std::getline(std::cin, str) && str != "") {
        try {
            grade = std::stoi(str);
        } catch (const std::invalid_argument &e) {
            std::cerr << "Error: El valor ingresado no es un número válido." << std::endl;
            return 1;
        } catch (const std::out_of_range &e) {
            std::cerr << "Error: El número ingresado está fuera del rango permitido." << std::endl;
            return 1;
        }
	}
	Bureaucrat bur = Bureaucrat(name, grade);
	std::cout << "Write 1 for create Shrubbery Creation form." << std::endl;
	std::cout << "Write 2 for create Robotomy Request form." << std::endl;
	std::cout << "Write 3 for create Presidential Pardon form." << std::endl;
	if (std::getline(std::cin, str) && str != "") {
		try {
			grade = std::stoi(str);
		} catch (const std::invalid_argument &e) {
			std::cerr << "Error: El valor ingresado no es un número válido." << std::endl;
			return 1;
		} catch (const std::out_of_range &e) {
			std::cerr << "Error: El número ingresado está fuera del rango permitido." << std::endl;
			return 1;
		}
	}
	switch (grade) {
		case 1:
			ShrubberyCreationForm form = ShrubberyCreationForm(name);
			try {
				form.beSigned(bur);
				if (form.getIfSigned() == true) {
						bur.executeForm(form);
				}
			}
			catch (std::exception &e) {
				std::cerr << "Error: " << e.what() << std::endl;
			}
		default:
			break ;
	}
}*/

int main(void) {
	std::string str;
	
	std::cout << "Write 1 for run Shrubbery without required sign grade test" << std::endl;
	std::cout << "Write 2 for run Robotomy Creation form SIGN & EXEC test" << std::endl;
	std::cout << "Write 3 for run Shrubbery form SIGN & EXEC test" << std::endl;
	std::cout << "Write 4 for run Presidential Pardon form SIGN & EXEC test" << std::endl;
	std::cout << "Write 5 for custom test."<< std::endl;
	if (std::getline(std::cin, str) && str != "") {
		switch (str[0]) {
			case '1':
				test1();
				break ;
			case '2':
				test2();
				break ;
			case '3':
				test3();
				break ;
			case '4':
				test4();
				break ;
			// case '5':
			// 	test5();
			// 	break ;
			default:
				break ;
		}
	}
	return (0);
}
