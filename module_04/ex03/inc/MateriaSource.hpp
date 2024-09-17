/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 21:23:04 by anovio-c          #+#    #+#             */
/*   Updated: 2024/09/11 20:34:55 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# include "Character.hpp"

// • learnMateria(AMateria*)
// Copies the Materia passed as a parameter and store it in memory so
// it can be cloned later. Like the Character, the MateriaSource can
// know at most 4 Materias. They are not necessarily unique.
// • createMateria(std::string const &)
// Returns a new Materia. The latter is a copy of the Materia previously
//  learned by the MateriaSource whose type equals the one passed as
//  parameter. Returns 0 if the type is unknown.
// In a nutshell, your MateriaSource must be able to learn "templates"
// of Materias to create them when needed. Then, you will be able to
// generate a new Materia using just a string that identifies its type.

class MateriaSource : public IMateriaSource {
	protected:
		AMateria	*_materiasLearned[INVENTORY_SIZE];
	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource &src);
		MateriaSource	&operator=(const MateriaSource &src);
		virtual	~MateriaSource(void);

		void 		learnMateria(AMateria *materia);
		AMateria* 	createMateria(std::string const &type);
};

#endif
