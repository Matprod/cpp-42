/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoisin <mvoisin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 21:27:09 by Matprod           #+#    #+#             */
/*   Updated: 2025/04/03 12:59:35 by mvoisin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	{
		std::cout << "\033[1;29mHuman A(crazyman)!\033[0m" << std::endl << std::endl;
		Weapon knife = Weapon("knife 🔪");
		HumanA crazyman("crazyman", knife);
		crazyman.attack();
		knife.setType("axe 🪓");
		crazyman.attack();
	}
	{
		std::cout << std::endl << "\033[1;29mHuman B(psychopath)!\033[0m" << std::endl << std::endl;
		Weapon pistol = Weapon("pistol 🔫");
		HumanB psychopath("psychopath");
		psychopath.attack();
		psychopath.setWeapon(pistol);
		psychopath.attack();
		pistol.setType("dagger 🗡️ ");
		psychopath.attack();
	}
	return 0;
}