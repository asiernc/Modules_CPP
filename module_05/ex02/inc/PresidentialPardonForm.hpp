/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 20:34:52 by anovio-c          #+#    #+#             */
/*   Updated: 2024/09/23 20:37:31 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"
# include <fstream>

// PresidentialPardonForm: Required grades: sign 145, exec 137
// Create a file <target>_shrubbery in the working directory,
// and writes ASCII trees inside it.

# undef SIGN_GRADE
# define SIGN_GRADE 145
# undef EXEC_GRADE
# define EXEC_GRADE 137

class PresidentialPardonForm : public AForm {
	private:
		const std::string	_target;
	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &src);
		virtual ~PresidentialPardonForm(void);

		PresidentialPardonForm	&operator=(const PresidentialPardonForm &src);
		std::string				getTarget(void) const;
		virtual void					runForm(void) const;
};

#endif