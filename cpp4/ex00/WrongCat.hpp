/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoisin <mvoisin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:40:03 by Matprod           #+#    #+#             */
/*   Updated: 2025/04/16 15:40:19 by mvoisin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
private:
	string _type;
public:
	WrongCat();
	WrongCat(string name);
	WrongCat(WrongCat const &rhs);
	WrongCat &operator=(WrongCat const &rhs);
	~WrongCat();
	string	getType() const;
	string	getName() const;
};