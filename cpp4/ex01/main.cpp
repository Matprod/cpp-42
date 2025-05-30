/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoisin <mvoisin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 13:42:47 by Matprod           #+#    #+#             */
/*   Updated: 2025/04/16 17:30:02 by mvoisin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"
#include <ctime>
#include <cstdlib> 

int getRandomNumber(int min, int max) {
    int randomNum = std::rand() % (max - min + 1) + min; // Générer un nombre entier aléatoire entre min et max inclus

    return randomNum; // Retourner le nombre aléatoire généré
}

string	getRandomIdea(int i) {
	string	ideas[10] = {
		"I want to eat a pizza 🍕",
		"I want to eat a burger 🍔",
		"I want to eat a hot dog 🌭",
		"I want to eat a sandwich 🥪",
		"I want to eat a salad 🥗",
		"I want to eat a soup 🥣",
		"I want to eat a cake 🍰",
		"I want to eat a ice cream 🍦",
		"I want to eat a chocolate 🍫",
		"I want to eat a donut 🍩"
	};

	return ideas[i];
}

void	BrainTest( void ) {
	cout << BOLD_WHITE"[PLEASE TYPE ENTER]" << endl;
	cin.get();
	cout << "\033[2J\033[1;1H";
	cout << BOLD_WHITE"╔═══════════════════════════════════════════════════╗" << endl;
	cout << BOLD_WHITE"╠═══════════════════════════════════════════════════╣" << endl;
	cout << BOLD_WHITE"║            🧠 SOME TEST FOR BRAINS 🧠            ║" << endl;
	cout << BOLD_WHITE"╠═══════════════════════════════════════════════════╣" << endl;
	cout << BOLD_WHITE"╚═══════════════════════════════════════════════════╝" << endl << endl;

	cout << BOLD_GREEN"Creation of the cat 😺:" << endl;

	cout << YELLOW"\033[3mNormal constructor" RESET << endl;
	const Cat		*garfield = new Cat("Garfield");

	cout << BOLD_WHITE"[PLEASE TYPE ENTER]" << endl;
	cin.get();
	cout << BOLD_BLUE"The cat will now introduce himself 😺:" BLUE << endl;
	cout << "Hello ! I am a " << garfield->getType() << " and my name is " << garfield->getName() << " 🧠" << endl;

	cout << BOLD_WHITE"[PLEASE TYPE ENTER]" << endl;
	cin.get();
	cout << BOLD_MAGENTA"The cat will make a sound 🗣️ :" MAGENTA << endl;
	garfield->makeSound();

	cout << BOLD_WHITE"[PLEASE TYPE ENTER]" << endl;
	cin.get();
	cout << BOLD_YELLOW"[\033[3mWhat happens when we print an empty brain ? 🤔 :" RESET << endl;
	garfield->printIdeas();
	cout << BOLD_YELLOW"[\033[3mWhat happens when we add an empty idea in the brain ? 🤔 :" RESET << endl;
	garfield->addIdea("");
	cout << endl << BOLD_BLUE"Now, we will fill his little brain ! 🧠" BLUE << endl;

	for (int i = 0; i < 97; i++)
		garfield->addIdea(getRandomIdea(getRandomNumber(0, 9)));
	
	// LOOP TO ADD IDEAS TO THE BRAIN OF THE CAT 🧠
	string	input;
	while (input != "exit")
	{
		cout << BOLD_CYAN"Please enter an idea for the cat or type 'exit 🧠 :" CYAN << endl;
		getline(cin, input);
		if (cin.eof())
			break ;
		if (input == "exit")
			break ;
		garfield->addIdea(input);
	} 
	garfield->printIdeas();
	
	cout << BOLD_WHITE"[PLEASE TYPE ENTER]" << endl;
	cin.get();
	cout << BOLD_YELLOW"\033[3mWhat happens when we init a new cat with the copy constructor ? 🤔 :" RESET << endl;
	cout << YELLOW"\033[3mCopy constructor" RESET << endl;
	cout << BOLD_WHITE"[PLEASE TYPE ENTER]" << endl;
	cin.get();
	const Cat	garfield_copy(*garfield);
	cout << BOLD_WHITE"[PLEASE TYPE ENTER]" << endl;
	cin.get();
	cout << BOLD_YELLOW"\033[3mWhat happens when we print the ideas of the copy cat ? 🤔 :" RESET << endl;
	garfield_copy.printIdeas();
	cout << BOLD_WHITE"[PLEASE TYPE ENTER]" << endl;
	cin.get();
	cout << BOLD_RED"Destruction of the cats:" << endl;

	delete garfield;
}

int main(){
	std::srand(std::time(0));
	BrainTest();
	return (0);
}

/* int main()
{
	Animal	*array[10];
	for (int i = 0; i < 10; i++)
		if (i % 2 == 0)
			array[i] = new Dog();
		else
			array[i] = new Cat();
	for (int i = 0; i < 10; i++)
		array[i]->makeSound();
	for (int i = 0; i < 10; i++)
		delete array[i];
	return (0);
} */
