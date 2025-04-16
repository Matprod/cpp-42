/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoisin <mvoisin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:29:43 by Matprod           #+#    #+#             */
/*   Updated: 2025/04/16 15:45:21 by mvoisin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void	animalsTest( void ) {
	cout << "\033[2J\033[1;1H";
	cout << BOLD_WHITE"╔═══════════════════════════════════════════════════╗" << endl;
	cout << BOLD_WHITE"╠═══════════════════════════════════════════════════╣" << endl;
	cout << BOLD_WHITE"║           🐗 SOME TEST FOR ANIMALS 🐗             ║" << endl;
	cout << BOLD_WHITE"╠═══════════════════════════════════════════════════╣" << endl;
	cout << BOLD_WHITE"╚═══════════════════════════════════════════════════╝" << endl << endl;

	cout << BOLD_GREEN"Creation of the animals 🐗:" << endl;
	cout << YELLOW"\033[3mDefault constructor" RESET << endl;
	const	Animal	default_animal;
	cout << YELLOW"\033[3mNormal constructor" RESET << endl;
	const	Animal	scrat = Animal("Scrat ");
	cout << YELLOW"\033[3mCopy constructor" RESET << endl;
	const	Animal	scrat_copy(scrat);
	cout << YELLOW"\033[3mAssignement constructor" RESET << endl;
	const	Animal	scrat_assign = scrat;

	cin.get();
	cout << BOLD_BLUE"The animals will now introduce themselves 🐗:" BLUE << endl;
	cout << "Hello ! I am a " << default_animal.getType() << " and my name is " << default_animal.getName() << " 🐗" << endl;
	cout << "Hello ! I am a " << scrat.getType() << " and my name is " << scrat.getName() << " 🐗" << endl;
	cout << "Hello ! I am a " << scrat_copy.getType() << " and my name is " << scrat_copy.getName() << " 🐗" << endl;
	cout << "Hello ! I am a " << scrat_assign.getType() << " and my name is " << scrat_assign.getName() << " 🐗" << endl;

	cin.get();
	cout << BOLD_MAGENTA"The animals will make a sound 🗣️ :" MAGENTA << endl;
	default_animal.makeSound();
	scrat.makeSound();

	cin.get();
	cout << BOLD_RED"Destruction of the animals:" << endl;
	
}

void	catsTest( void ) {
	cin.get();
	cout << "\033[2J\033[1;1H";
	cout << BOLD_WHITE"╔═══════════════════════════════════════════════════╗" << endl;
	cout << BOLD_WHITE"╠═══════════════════════════════════════════════════╣" << endl;
	cout << BOLD_WHITE"║             😺 SOME TEST FOR CATS 😺              ║" << endl;
	cout << BOLD_WHITE"╠═══════════════════════════════════════════════════╣" << endl;
	cout << BOLD_WHITE"╚═══════════════════════════════════════════════════╝" << endl << endl;

	cout << BOLD_GREEN"Creation of the cats 😺:" << endl;
	cout << YELLOW"\033[3mDefault constructor" RESET << endl;
	const Animal	*default_cat = new Cat();
	cout << YELLOW"\033[3mNormal constructor" RESET << endl;
	const Cat		*norminet = new Cat("Norminet");
	cout << YELLOW"\033[3mCopy constructor" RESET << endl;
	const Cat	norminet_copy(*norminet);
	cout << YELLOW"\033[3mAssignement constructor" RESET << endl;
	const Cat	norminet_assignement = *norminet;

	cin.get();
	cout << BOLD_BLUE"The cats will now introduce themselves 😺:" BLUE << endl;
	cout << "Hello ! I am a " << default_cat->getType() << " and my name is " << default_cat->getName() << " 😺" << endl;
	cout << "Hello ! I am a " << norminet->getType() << " and my name is " << norminet->getName() << " 😺" << endl;
	cout << "Hello ! I am a " << norminet_copy.getType() << " and my name is " << norminet_copy.getName() << " 😺" << endl;
	cout << "Hello ! I am a " << norminet_assignement.getType() << " and my name is " << norminet_assignement.getName() << " 😺" << endl;

	cin.get();
	cout << BOLD_MAGENTA"The cats will make a sound 🗣️ :" MAGENTA << endl;
	default_cat->makeSound();
	norminet->makeSound();

	cin.get();
	cout << BOLD_RED"Destruction of the cats:" << endl;
	
	delete default_cat;
	delete norminet;
}

void	dogsTest( void ) {
	cin.get();
	cout << "\033[2J\033[1;1H";
	cout << BOLD_WHITE"╔═══════════════════════════════════════════════════╗" << endl;
	cout << BOLD_WHITE"╠═══════════════════════════════════════════════════╣" << endl;
	cout << BOLD_WHITE"║             🐕 SOME TEST FOR DOGS 🐕              ║" << endl;
	cout << BOLD_WHITE"╠═══════════════════════════════════════════════════╣" << endl;
	cout << BOLD_WHITE"╚═══════════════════════════════════════════════════╝" << endl << endl;

	cout << BOLD_GREEN"Creation of the dogs 🐕:" << endl;
	cout << YELLOW"\033[3mDefault constructor" RESET << endl;
	const Animal	*default_dog = new Dog();
	cout << YELLOW"\033[3mNormal constructor" RESET << endl;
	const Dog		*alan = new Dog("Rex");
	cout << YELLOW"\033[3mCopy constructor" RESET << endl;
	const Dog		alan_copy(*alan);
	cout << YELLOW"\033[3mAssignement constructor" RESET << endl;
	const Dog		alan_assignement = *alan;

	cin.get();
	cout << BOLD_BLUE"The dogs will now introduce themselves 🐕:" BLUE << endl;
	cout << "Hello ! I am a " << default_dog->getType() << " and my name is " << default_dog->getName() << " 🐕" << endl;
	cout << "Hello ! I am a " << alan->getType() << " and my name is " << alan->getName() << " 🐕" << endl;
	cout << "Hello ! I am a " << alan_copy.getType() << " and my name is " << alan_copy.getName() << " 🐕" << endl;
	cout << "Hello ! I am a " << alan_assignement.getType() << " and my name is " << alan_assignement.getName() << " 🐕" << endl;

	cin.get();
	cout << BOLD_MAGENTA"The dogs will make a sound 🗣️ :" MAGENTA << endl;
	default_dog->makeSound();
	alan->makeSound();

	cin.get();
	cout << BOLD_RED"Destruction of the dogs:" << endl;
	
	delete default_dog;
	delete alan;
}

void	wrongCatTest( void ) {
	cin.get();
	cout << "\033[2J\033[1;1H";
	cout << BOLD_WHITE"╔═══════════════════════════════════════════════════╗" << endl;
	cout << BOLD_WHITE"╠═══════════════════════════════════════════════════╣" << endl;
	cout << BOLD_WHITE"║          🦁 SOME TEST FOR WRONG_CATS 🦁           ║" << endl;
	cout << BOLD_WHITE"╠═══════════════════════════════════════════════════╣" << endl;
	cout << BOLD_WHITE"╚═══════════════════════════════════════════════════╝" << endl << endl;

	cout << BOLD_GREEN"Creation of the \"cats\" 🦁:" << endl;
	cout << YELLOW"\033[3mDefault constructor" RESET << endl;
	WrongAnimal	*default_lion = new WrongCat();
	cout << YELLOW"\033[3mNormal constructor" RESET << endl;
	WrongCat		*lion = new WrongCat("Nordminette");
	cout << YELLOW"\033[3mCopy constructor" RESET << endl;
	const WrongCat		lion_copy(*lion);
	cout << YELLOW"\033[3mAssignement constructor" RESET << endl;
	const WrongCat		lion_assignement = *lion;

	cin.get();
	cout << BOLD_BLUE"The \"cats\" will now introduce themselves 🦁:" BLUE << endl;
	cout << "Hello ! I am a " << default_lion->getType() << " and my name is " << default_lion->getName() << " 🦁" << endl;
	cout << "Hello ! I am a " << lion->getType() << " and my name is " << lion->getName() << " 🦁" << endl;
	cout << "Hello ! I am a " << lion_copy.getType() << " and my name is " << lion_copy.getName() << " 🦁" << endl;
	cout << "Hello ! I am a " << lion_assignement.getType() << " and my name is " << lion_assignement.getName() << " 🦁" << endl;

	cin.get();
	cout << BOLD_MAGENTA"The \"cats\" will make a sound 🗣️ :" MAGENTA << endl;
	default_lion->makeSound();
	lion->makeSound();

	cin.get();
	cout << BOLD_RED"Destruction of the \"cats\":" << endl;
	
	delete default_lion;
	delete lion;
}

int main()
{
	animalsTest();
	catsTest();
	dogsTest();
	wrongCatTest();
} 

/* int main()
{
const WrongAnimal* meta = new WrongAnimal();
const Animal* j = new Dog();
const WrongAnimal* i = new WrongCat();
std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
i->makeSound(); //will output the cat sound!
j->makeSound();
meta->makeSound();
return 0;
} */