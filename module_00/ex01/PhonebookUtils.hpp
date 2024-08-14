/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhonebookUtils.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 19:28:30 by anovio-c          #+#    #+#             */
/*   Updated: 2024/08/14 19:48:35 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOKUTILS_HPP

# define PHONEBOOKUTILS_HPP

# include <iostream>
# include <string>
# include "Contact.hpp"

# define MAX_CHARACTERS 10
# define MAX_CONTACTS 8

std::string		parse_line(std::string str);
void			display_header(void);
int				display_contacts(Contact contact[MAX_CONTACTS]);
bool			onlySpaces(std::string str);
bool			checkPhoneNumber(std::string str);

#endif
