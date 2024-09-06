/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 20:03:37 by anovio-c          #+#    #+#             */
/*   Updated: 2024/09/05 19:29:30 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
# define CLAPTRAP_H

# include <iostream>

class ClapTrap {
	protected: //for inheritance
		std::string	_name;
		int			_hitPoints;
		int			_energyPoints;
		int			_attackDamage;
		
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &src);
		virtual ~ClapTrap();
		ClapTrap		&operator=(const ClapTrap &src);

		void 			attack(const std::string& target);
		void 			takeDamage(unsigned int amount);
		void 			beRepaired(unsigned int amount);
		
		std::string		getName(void) const;
		unsigned int	getHitPoints(void) const;
		unsigned int	getEnergyPoints(void) const;
		unsigned int	getAttackDamage(void) const;

		// For testing (not exercise)
		virtual void	setHitPoints(int hitPoints);
};

#endif
