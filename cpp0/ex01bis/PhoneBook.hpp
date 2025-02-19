/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:54:48 by Matprod           #+#    #+#             */
/*   Updated: 2025/02/13 20:30:45 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include <cstdlib>
# include "Contact.hpp"

typedef	std::string string;

class PhoneBook {

	public:
		PhoneBook();
		void	add();
		void	search();
		void	show_full_contact();
	private:
		int		_nb_contact;
		Contact	_contacts[8];

};

#endif