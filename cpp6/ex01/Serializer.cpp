/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 17:28:01 by Matprod           #+#    #+#             */
/*   Updated: 2025/06/05 17:28:04 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

uintptr_t	Serializer::serialize( Data *data ) {
	return (reinterpret_cast<uintptr_t>(data));
}

Data	*Serializer::deserialize( uintptr_t ptr ) {
	return (reinterpret_cast<Data *>(ptr));
}