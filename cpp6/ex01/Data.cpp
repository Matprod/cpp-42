/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 17:27:35 by Matprod           #+#    #+#             */
/*   Updated: 2025/06/05 17:27:42 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data( void ) {
}

Data::~Data( void ) {
}

Data::Data( const Data &rhs) {
	(void)rhs;
}

Data	&Data::operator=( const Data &rhs) {
	(void)rhs;
	return (*this);
}
