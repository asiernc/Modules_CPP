/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 20:34:52 by anovio-c          #+#    #+#             */
/*   Updated: 2024/09/26 18:50:47 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <fstream>

// ShrubberyCreationForm: Required grades: sign 145, exec 137
// Create a file <target>_shrubbery in the working directory,
// and writes ASCII trees inside it.

# undef SIGN_GRADE
# define SIGN_GRADE 145
# undef EXEC_GRADE
# define EXEC_GRADE 137

class ShrubberyCreationForm : public AForm {
	private:
		const std::string	_target;
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &src);
		virtual ~ShrubberyCreationForm(void);

		ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &src);
		std::string				getTarget(void) const;
		// Para que shrubbery no sea considerada abstracta como AForm, debe
		// heredar todas las funciones virtuales puras de AForm.
		//virtual void			beSigned(const Bureaucrat src);
		virtual void			runForm(void) const;
};

#endif
