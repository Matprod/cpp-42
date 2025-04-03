/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:37:13 by Matprod           #+#    #+#             */
/*   Updated: 2025/04/02 14:13:40 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

# define BLACK "\033[0;30m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define MAGENTA "\033[0;35m"
# define CYAN "\033[0;36m"
# define WHITE "\033[0;37m"

# define BOLD_BLACK "\033[1;30m"
# define BOLD_RED "\033[1;31m"
# define BOLD_GREEN "\033[1;32m"
# define BOLD_YELLOW "\033[1;33m"
# define BOLD_BLUE "\033[1;34m"
# define BOLD_MAGENTA "\033[1;35m"
# define BOLD_CYAN "\033[1;36m"
# define BOLD_WHITE "\033[1;37m"

# define RESET "\033[0m"

using std::cout;
using std::endl;
using std::string;
using std::cin;

typedef std::string string;

class WrongAnimal {
	public:
		WrongAnimal();
		WrongAnimal(string name);
		WrongAnimal(WrongAnimal const &rhs);
		WrongAnimal &operator=(WrongAnimal const &rhs);
		virtual ~WrongAnimal();
		virtual string	getType() const;
		virtual	string	getName() const;
		void	makeSound( void ) const;
	protected:
		string	_type;
		string	_name;
};

