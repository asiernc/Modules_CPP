/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 19:28:15 by anovio-c          #+#    #+#             */
/*   Updated: 2024/08/13 21:12:32 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP

#define CONTACT_HPP

# include <iostream>
# include <string>
# include <cctype>

class Contact
{
	public:
		Contact(void);
		~Contact(void);

		// Getters and setters
		std::string		getFirstName(void);
		std::string		getLastName(void);
		std::string		getNickname(void);
		std::string		getPhoneNumber(void);
		std::string		getDarkestSecret(void);
		void			setFirstName(std::string str);
		void			setLastName(std::string str);
		void			setNickname(std::string str);
		bool			setPhoneNumber(std::string str);
		void			setDarkestSecret(std::string str);
		
	private:
		std::string		_firstName;
		std::string		_lastName;
		std::string		_nickname;
		std::string		_phonenum;
		std::string		_secret;
};
#endif
