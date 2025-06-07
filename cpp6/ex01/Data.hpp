/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 17:27:48 by Matprod           #+#    #+#             */
/*   Updated: 2025/06/05 17:27:50 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>
# include <string>
# include <stdint.h>

using	std::string;
using	std::cout;
using	std::endl;

class	Data {
	private:
		Data(const Data &src);
		Data	&operator=(const Data &rhs);
	public:
		~Data();
		Data();
		string	str;
		int		num;
};

#endif