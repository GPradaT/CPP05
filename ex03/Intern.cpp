/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gprada-t <gprada-t@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 08:46:00 by gprada-t          #+#    #+#             */
/*   Updated: 2024/07/31 21:24:52 by gpradat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern CONSTRUCTOR" << std::endl;
}

Intern::~Intern()
{
	std::cout << "Intern DESTRUCTOR" << std::endl;
}

Intern::Intern(const Intern &src)
{
	*this = src;
}

Intern	&Intern::operator=(const Intern &src)
{
	(void)src;
	return *this;
}

const char  *Intern::typeFormNotFound::what() const throw()
{
	return "We don't have this shitForm type you're looking for";
}

AForm	*makeShrubbery(std::string target)
{
	return new ShrubberyCreationForm(target);
}

AForm	*makeRobotomy(std::string target)
{
	return new RobotomyRequestForm(target);
}

AForm	*makePardon(std::string target)
{
	return new PresidentialPardonForm(target);
}

AForm	*Intern::makeForm(std::string typeForm, std::string target)
{
	std::string     typeForms[3] = {SHRUBBERY, ROBOTOMY, PARDON};
	Form	makeForm[3] = {makeShrubbery, makeRobotomy, makePardon};

	try
	{
		for (int i = 0; i < 4; i++)
		{
			if (typeForm == typeForms[i])
				return makeForm[i](target);
		}
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	throw typeFormNotFound();
}
