/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 20:47:23 by Matprod           #+#    #+#             */
/*   Updated: 2025/03/09 21:26:23 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "iostream"
#include "iomanip"
#include "cstdlib"
#include <string>
#include "Weapon.hpp"

typedef	std::string string;

class HumanA {
	public:
		void	attack();
		HumanA();
		HumanA(string name, Weapon &Weapon);
		~HumanA();
	private:
		string _name;
		Weapon &_weapon;
};


#endif