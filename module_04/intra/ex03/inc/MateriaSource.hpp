/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 21:23:04 by anovio-c          #+#    #+#             */
/*   Updated: 2024/09/19 19:52:30 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# include "Character.hpp"

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
