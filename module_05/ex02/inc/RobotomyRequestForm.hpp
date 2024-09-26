/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 20:20:03 by anovio-c          #+#    #+#             */
/*   Updated: 2024/09/25 20:32:18 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

# undef SIGN_GRADE
# define SIGN_GRADE 25
# undef EXEC_GRADE
# define EXEC_GRADE 5

class RobotomyRequestForm : public AForm {
	private:
		std::string	_target;
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &src);
		virtual ~RobotomyRequestForm(void);
		
		RobotomyRequestForm &operator=(const RobotomyRequestForm &src);
		std::string			getTarget(void) const ;

		virtual void		beSigned(const Bureaucrat src);
		void				runForm(void) const;
		
};

#endif