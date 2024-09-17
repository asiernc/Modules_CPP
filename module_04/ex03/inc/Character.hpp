/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 12:41:22 by anovio-c          #+#    #+#             */
/*   Updated: 2024/09/11 21:05:38 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# define INVENTORY_SIZE 4

class Character : public ICharacter {
	protected:
		std::string	_name;
		AMateria	*_inventory[INVENTORY_SIZE];
	public:
		Character(void);
		Character(const std::string &name);
		Character(const Character &src);
		Character	&operator=(const Character &src);
		virtual ~Character();

		const std::string &getName(void) const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif
