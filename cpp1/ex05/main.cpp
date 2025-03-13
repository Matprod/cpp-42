/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 23:12:57 by Matprod           #+#    #+#             */
/*   Updated: 2025/03/12 23:22:00 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "harl.hpp"

int	main(void) {
	Harl	client;
	client.complain("DEBUG");
	client.complain("INFO");
	client.complain("WARNING");
	client.complain("ERROR");
	client.complain("TEST");
}