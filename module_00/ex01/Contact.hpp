/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 19:28:15 by anovio-c          #+#    #+#             */
/*   Updated: 2024/08/12 15:03:03 by anovio-c         ###   ########.fr       */
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
	static bool		onlySpaces(std::string str);

	// Getters and setters
	std::string		getFname(void);
	std::string		getLname(void);
	std::string		getNickname(void);
	std::string		getPhoneNumber(void);
	std::string		getDarkestSecret(void);
	bool			setFname(std::string str);
	bool			setLname(std::string str);
	bool			setNickname(std::string str);
	bool			setPhoneNumber(std::string str);
	bool			setDarkestSecret(std::string str);
};
#endif
