/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:03:47 by Matprod           #+#    #+#             */
/*   Updated: 2025/02/12 18:55:18 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include "iostream"
#include "iomanip"
#include "cstdlib"
#include <string>

typedef	std::string string;

class	Contact {
	public:
		string	get_first_name();
		string	get_last_name();
		string	get_nickname();
		string	get_phone_number();
		string	get_darkest_secret();
		void	set_first_name();
		void	set_last_name();
		void	set_nickname();
		void	set_phone_number();
		void	set_darkest_secret();
		void	show_contact(int id);
		void	print_trunc(string str);
	private:
		string	_first_name;
		string	_last_name;
		string	_nickname;
		string	_phone_number;
		string	_darkest_secret;
};





#endif