/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 19:28:36 by anovio-c          #+#    #+#             */
/*   Updated: 2024/08/14 19:36:59 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP

# define PHONEBOOK_HPP

# include <stdbool.h>
# include "Contact.hpp"

# define MAX_CONTACTS 8

class Phonebook
{
	public:
		Phonebook(void);
		~Phonebook(void);
		void 	add(void);
		void 	search(void);
		void	showHelp(void);
		void 	print(Contact Contact);
		void	print_contact(Contact contact);
		Contact get_contact(int _index);
		
	private:
		int				_index;
		Contact			_contacts[MAX_CONTACTS];
		bool			checkFirstName(Contact &Shallow);
		bool			checkLastName(Contact &Shallow);
		bool			checkNickName(Contact &Shallow);
		bool			checkPhoneNum(Contact &Shallow);
		bool			checkDarkestSecret(Contact &Shallow);
		bool			checkContact(Contact Shallow);
};


#endif
