/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 19:28:36 by anovio-c          #+#    #+#             */
/*   Updated: 2024/08/12 15:04:41 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP

# define PHONEBOOK_HPP

# include "Contact.hpp"

# define MAX_CONTACTS 8

class Phonebook
{
	private:
		Contact	_contacts[8];
		int		_index;
	public:
		Phonebook(void);
		~Phonebook(void);
		void 	add(void);
		void 	search(void);
		void	showHelp(void);
		void 	print(Contact Contact);
		void	print_contact(Contact contact);

		Contact get_contact(int _index);
};


#endif
