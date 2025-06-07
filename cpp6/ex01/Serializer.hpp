/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 17:28:07 by Matprod           #+#    #+#             */
/*   Updated: 2025/06/05 17:28:09 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <stdint.h>
# include "Data.hpp"

class	Serializer {
	private:
		~Serializer();
		Serializer(const Serializer &src);
		Serializer	&operator=(const Serializer &rhs);
		Serializer();
	public:
		static uintptr_t	serialize(Data *data);
		static Data	*deserialize(uintptr_t raw);
};

#endif