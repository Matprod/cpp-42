/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 18:49:28 by Matprod           #+#    #+#             */
/*   Updated: 2025/06/05 18:52:38 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "header.hpp"

// Codes ANSI pour les couleurs
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"

// Fonction pour nettoyer l’écran
void clearScreen() {
	system("clear");
}

// Fonction pour afficher une séparation visuelle
void printSeparator() {
	std::cout << CYAN << "\n----------------------------------------\n" << RESET;
}

// Fonction pour attendre une interaction utilisateur
void waitForUser() {
	std::cout << YELLOW << "\nAppuyez sur Entree pour continuer..." << RESET;
	std::cin.get();
	std::cout << std::endl;
		
}

// Fonction template pour afficher les éléments
template <typename T>
void print(const T& value) {
	std::cout << value << " ";
}

// Fonction template pour incrémenter les éléments non-const
template <typename T>
void increment(T& value) {
	++value;
}

// Fonction pour mettre en majuscule (compatible C++98)
void toUpper(std::string& str) {
	for (size_t i = 0; i < str.length(); ++i) {
		str[i] = std::toupper(str[i]);
	}
}

// Fonction pour doubler les valeurs (remplace la lambda)
void doubleValue(int& value) {
	value *= 2;
}

int main() {
	clearScreen();
	std::cout << BLUE << "Diapositive 1 : Affichage d’un tableau d’entiers\n" << RESET;
	waitForUser();
	int intArray[] = {1, 2, 3, 4, 5};
	size_t intLength = sizeof(intArray) / sizeof(intArray[0]);
	std::cout << GREEN << "Valeurs du tableau : " << RESET;
	iter(intArray, intLength, print<int>);
	std::cout << std::endl;
	printSeparator();
	std::cout << BLUE << "Diapositive 2 : Incrementer un tableau d’entiers\n" << RESET;
	waitForUser();
	std::cout << GREEN << "Valeurs avant incrementation : " << RESET;
	iter(intArray, intLength, print<int>);
	std::cout << std::endl;
		
	iter(intArray, intLength, increment<int>);
	std::cout << GREEN << "Valeurs apres incrementation : " << RESET;
	iter(intArray, intLength, print<int>);
	std::cout << std::endl;
	waitForUser();
	clearScreen();
		

	// Test 3 : Tableau de doubles
	std::cout << BLUE << "Diapositive 3 : Affichage d’un tableau de doubles\n" << RESET;
	waitForUser();
	double doubleArray[] = {1.1, 2.2, 3.3};
	size_t doubleLength = sizeof(doubleArray) / sizeof(doubleArray[0]);
	std::cout << GREEN << "Valeurs du tableau : " << RESET;
	iter(doubleArray, doubleLength, print<double>);
	waitForUser();
	clearScreen();

	// Test 4 : Tableau de chaînes de caractères
	std::cout << BLUE << "Diapositive 4 : Transformation d’un tableau de chaînes\n" << RESET;
	waitForUser();
	std::string stringArray[] = {"bonjour", "monde", "cpp"};
	size_t stringLength = sizeof(stringArray) / sizeof(stringArray[0]);
	std::cout << GREEN << "Valeurs avant transformation (toUpper) : " << RESET;
	iter(stringArray, stringLength, print<std::string>);
	std::cout << std::endl;
		
	iter(stringArray, stringLength, toUpper);
	std::cout << GREEN << "Valeurs apres transformation (toUpper) : " << RESET;
	iter(stringArray, stringLength, print<std::string>);
	std::cout << std::endl;
	waitForUser();
	clearScreen();	

	// Test 5 : Tableau const d'entiers

	std::cout << BLUE << "Diapositive 5 : Affichage d’un tableau const d’entiers\n" << RESET;
	waitForUser();
	const int constIntArray[] = {10, 20, 30};
	size_t constIntLength = sizeof(constIntArray) / sizeof(constIntArray[0]);
	std::cout << GREEN << "Valeurs du tableau : " << RESET;
	iter(constIntArray, constIntLength, print<int>);
	std::cout << std::endl;
	waitForUser();
	clearScreen();
		

	// Test 6 : Doubler un tableau d’entiers

	std::cout << BLUE << "Diapositive 6 : Doubler un tableau d’entiers\n" << RESET;
	waitForUser();
	std::cout << GREEN << "Valeurs avant transformation (x2) : " << RESET;
	iter(intArray, intLength, print<int>);
	std::cout << std::endl;
		
	iter(intArray, intLength, doubleValue);
	std::cout << GREEN << "Valeurs apres transformation (x2) : " << RESET;
	iter(intArray, intLength, print<int>);
	std::cout << std::endl;
	waitForUser();
	clearScreen();

	// Conclusion
	printSeparator();
	std::cout << MAGENTA << "Fin des tests ! Merci d’avoir utilise ce programme.\n" << RESET;
	waitForUser();

	return 0;
}