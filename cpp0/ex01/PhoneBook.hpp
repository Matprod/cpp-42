/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:03:37 by Matprod           #+#    #+#             */
/*   Updated: 2025/02/12 18:57:11 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include <cstdlib>
# include "Contact.hpp"

typedef	std::string string;

class	PhoneBook {
	public:
		PhoneBook();
		void	add();
		void	search();
		void	show_format_contact();
	private:
		int		_nb_contact;
		Contact	_contacts[8];
};

#endif

