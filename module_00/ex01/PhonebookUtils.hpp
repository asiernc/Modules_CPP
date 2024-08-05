/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhonebookUtils.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 19:28:30 by anovio-c          #+#    #+#             */
/*   Updated: 2024/08/05 19:28:31 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOKUTILS_HPP

# define PHONEBOOKUTILS_HPP

# include <iostream>
# include <string>
# include "Contact.hpp"

# define MAX_CHARACTERS 10

std::string		parse_line(std::string str);
void			display_header(void);
int				display_contacts(Contact contact[8]);

#endif
