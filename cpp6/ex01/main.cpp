/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 17:27:53 by Matprod           #+#    #+#             */
/*   Updated: 2025/06/05 17:27:58 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"

int	main( void ) {
	Data		*data = new Data;
	uintptr_t	ptr;

	data->str = "Hello world !";
	data->num = 42;
	cout << "Before :" << endl;
	cout << "data->str: " << data->str << endl;
	cout << "data->num: " << data->num << endl;
	cout << "data ptr: " << data << endl; 

	cout << endl << "Serialization" << endl;
	ptr = Serializer::serialize(data);
	cout << "Derialization" << endl << endl;
	data = Serializer::deserialize(ptr);
	
	cout << "After :" << endl;
	cout << "data->str: " << data->str << endl;
	cout << "data->num: " << data->num << endl;
	cout << "data ptr: " << data << endl; 

	delete data;
	return (0);
}