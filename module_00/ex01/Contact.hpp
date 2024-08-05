/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 19:28:15 by anovio-c          #+#    #+#             */
/*   Updated: 2024/08/05 19:28:16 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP

#define CONTACT_HPP

# include <iostream>
# include <string>
# include <stdbool.h>
# include <cctype>

class Contact
{
private:
	std::string	fname;
	std::string	lname;
	std::string	nickname;
	std::string	phonenum;
	std::string	secret;
public:
	Contact(void);
	~Contact(void);
	static bool	only_spaces(std::string str);

	// Getters and setters
	std::string		get_fname(void);
	std::string		get_lname(void);
	std::string		get_nickname(void);
	std::string		get_phoneNumber(void);
	std::string		get_darkestSecret(void);
	bool			set_fname(std::string str);
	bool			set_lname(std::string str);
	bool			set_nickname(std::string str);
	bool			set_phoneNumber(std::string str);
	bool			set_darkestSecret(std::string str);
};
#endif
