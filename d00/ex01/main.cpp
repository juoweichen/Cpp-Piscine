/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juochen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 13:21:27 by juochen           #+#    #+#             */
/*   Updated: 2019/01/21 13:21:29 by juochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PersonInfo.hpp"

void printFitWidth(std::string str)
{
	char tmp[11];

	for (int i = 0; i < 10; i++)
		tmp[i] = ' ';
	tmp[10] = '\0';
	str.copy(tmp, 10, 0);
	if (str.length()> 10)
		tmp[9] = '.';
	std::cout << tmp << "|";
}

void searchInfo(PersonInfo *info, int infoCounter)
{
	char buf[2] = {0};
	int searchIndex;

	//print info content
	std::cout << "|   index  |first name|last name |nickname  |" << std::endl;
	for (int i = 0; i < infoCounter; i++)
	{
		std::cout << "|     " << i << "    |";
		printFitWidth(info[i].firstName);
		printFitWidth(info[i].lastName);
		printFitWidth(info[i].nickName);
		std::cout << std::endl;
	}
	//ask user to input index
	std::cout << "Enter index for more detail: ";
	std::cin >> buf;
	if (isdigit(buf[0]) && (searchIndex = buf[0] - '0') >= 0 && searchIndex < infoCounter)
	{
		std::cout << "target index: " << searchIndex << std::endl;
		std::cout << "First Name: " << info[searchIndex].firstName << std::endl;
		std::cout << "Last Name: " << info[searchIndex].lastName << std::endl;
		std::cout << "Nick Name: " << info[searchIndex].nickName << std::endl;
		std::cout << "Login: " << info[searchIndex].login << std::endl;
		std::cout << "Postal Address: " << info[searchIndex].postalAddress << std::endl;
		std::cout << "Email Address: " << info[searchIndex].emailAddress << std::endl;
		std::cout << "Phone Number: " << info[searchIndex].phoneNumber << std::endl;
		std::cout << "Birthday Date: " << info[searchIndex].birthdayDate << std::endl;
		std::cout << "Favorite Meal: " << info[searchIndex].favoriteMeal << std::endl;
		std::cout << "Underwear Color: " << info[searchIndex].underwearColor << std::endl;
		std::cout << "Darkest Secert: " << info[searchIndex].darkestSecret << std::endl;
	}
	else
		std::cout << "Incorrect index number :P" << std::endl;
}

void addInfo(PersonInfo *info, int infoCounter)
{
	infoCounter = infoCounter - 1;
	std::cout << "First Name: ";
	std::cin >> info[infoCounter].firstName;
	std::cout << "Last Name: ";
	std::cin >> info[infoCounter].lastName;
	std::cout << "Nick Name: ";
	std::cin >> info[infoCounter].nickName;
	std::cout << "Login: ";
	std::cin >> info[infoCounter].login;
	std::cout << "Postal Address: ";
	std::cin >> info[infoCounter].postalAddress;
	std::cout << "Email Address: ";
	std::cin >> info[infoCounter].emailAddress;
	std::cout << "Phone Number: ";
	std::cin >> info[infoCounter].phoneNumber;
	std::cout << "Birthday Date: ";
	std::cin >> info[infoCounter].birthdayDate;
	std::cout << "Favorite Meal: ";
	std::cin >> info[infoCounter].favoriteMeal;
	std::cout << "Underwear Color: ";
	std::cin >> info[infoCounter].underwearColor;
	std::cout << "Darkest Secert: ";
	std::cin >> info[infoCounter].darkestSecret;
}

int main(void)
{
	char command[10] = {0};
	PersonInfo info[8];
	int infoCounter = 0;

	while (1)
	{
		std::cout << "Please Enter: EXIT | ADD | SEARCH > ";
		std::cin >> command;
		if (strcmp(command, "EXIT") == 0)
		{
			exit (0);
		}
		else if (strcmp(command, "ADD") == 0)
		{
			if (infoCounter > 8)
			{
				std::cout << "Phonebook full...can't add more contact info" << std::endl;
				continue ;
			}
			infoCounter++;
			addInfo(info, infoCounter);
		}
		else if (strcmp(command, "SEARCH") == 0)
		{
			searchInfo(info, infoCounter);
		}
		else
			std::cout << "irrelevant input, please try again..." << std::endl;
		std::cin.clear();
    	std::cin.ignore( 10000 , '\n' );
	}
	return 0;
}