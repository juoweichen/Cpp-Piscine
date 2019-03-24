/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juochen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 13:22:05 by juochen           #+#    #+#             */
/*   Updated: 2019/01/21 13:22:06 by juochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PERSONINFO_H
# define PERSONINFO_H

#include <iostream>

class PersonInfo {
	public:
		std::string firstName;
		std::string lastName;
		std::string nickName;
		std::string login;
		std::string postalAddress;
		std::string emailAddress;
		std::string phoneNumber;
		std::string birthdayDate;
		std::string favoriteMeal;
		std::string underwearColor;
		std::string darkestSecret;

		PersonInfo(void);
		~PersonInfo(void);
};

#endif
