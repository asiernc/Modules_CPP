/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 20:47:17 by anovio-c          #+#    #+#             */
/*   Updated: 2024/08/10 21:22:26 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
# include <iostream>

class HumanB
{
private:
	Weapon		*_weapon;
	std::string	_name;
public:
	HumanB(std::string);
	void	attack(void);
	void	setWeapon(Weapon &weapon);
	~HumanB();
};

#endif
