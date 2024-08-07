/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gprada-t <gprada-t@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 10:43:26 by gprada-t          #+#    #+#             */
/*   Updated: 2024/07/31 09:41:04 by gprada-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define SEPARATOR "------------------------------------"

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main()
{
	{
	std::string name = "Constitution";
	Bureaucrat	GrandMaster("Grand Master", 14);
	ShrubberyCreationForm		Constitution(name);

	try
	{
		AForm	*test3 = new ShrubberyCreationForm("SuckerPlace");
		GrandMaster.signForm(Constitution);
		test3->beSigned(GrandMaster);
		test3->execute(GrandMaster);
		delete test3;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	GrandMaster.executeForm(Constitution);
	std::cout << GrandMaster;
	std::cout << Constitution;
	}
	std::cout << SEPARATOR << std::endl;
	{
	std::string name = "Constitution";
	Bureaucrat	GrandMaster("Grand Master", 14);
	RobotomyRequestForm		Constitution(name);

	try
	{
		AForm	*test3 = new RobotomyRequestForm("SuckerPlace");
		GrandMaster.signForm(Constitution);
		test3->beSigned(GrandMaster);
		test3->execute(GrandMaster);
		delete test3;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	GrandMaster.executeForm(Constitution);
	std::cout << GrandMaster;
	std::cout << Constitution;
	}
	std::cout << SEPARATOR << std::endl;
	{
	std::string name = "Constitution";
	Bureaucrat	GrandMaster("Grand Master", 7);
	PresidentialPardonForm		Constitution(name);

	try
	{
		AForm	*test3 = new PresidentialPardonForm("Ur mom");
		GrandMaster.signForm(Constitution);
		test3->beSigned(GrandMaster);
		test3->execute(GrandMaster);
		delete test3;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	GrandMaster.executeForm(Constitution);
	std::cout << GrandMaster;
	std::cout << Constitution;
	}
	return 0;
}
