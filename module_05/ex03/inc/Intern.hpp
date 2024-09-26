/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:05:59 by anovio-c          #+#    #+#             */
/*   Updated: 2024/09/26 15:18:22 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "AForm.hpp"

class Intern {
	public:
		Intern(void);
		Intern(const Intern &src);
		Intern	&operator=(const Intern &src);
		~Intern(void);

		AForm *makeForm(std::string formName, std::string formTarget);
}

