/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 12:41:22 by anovio-c          #+#    #+#             */
/*   Updated: 2024/09/07 21:17:46 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

// The Character possesses an inventory of 4 slots, which means 4
// Materias at most. The inventory is empty at construction. They
// equip the Materias in the first empty slot they find. This means,
// in this order: from slot 0 to slot 3. In case they try to add a
// Materia to a full inventory, or use/unequip an unexisting Materia,
// don’t do anything (but still, bugs are forbidden). The unequip()
// member function must NOT delete the Materia!

# include "ICharacter.hpp"
# define INVENTORY_SIZE 4

class Character : public ICharacter {
	protected:
		std::string	_name;
		AMateria	*_inventory[INVENTORY_SIZE];
	public:
		Character();
		Character(std::string &name);
		Character(const Character &src);
		Character	&operator=(const Character &src);
		virtual ~Character();

		const std::string &getName(void) const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif