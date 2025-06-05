/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 21:52:18 by Matprod           #+#    #+#             */
/*   Updated: 2025/06/05 18:30:21 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <stdio.h>
#include <cstdlib>

template <typename T, typename Function>
void iter(T* array, size_t length, Function func) {
	for (size_t i = 0; i < length; ++i) {
		func(array[i]);
	}
}