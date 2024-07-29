/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gprada-t <gprada-t@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 10:43:26 by gprada-t          #+#    #+#             */
/*   Updated: 2024/07/29 10:22:40 by gprada-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define SEPARATOR "------------------------------------"

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int	main()
{
	std::string name = "Constitution";
	Bureaucrat	GrandMaster("Grand Master", 4);
	ShrubberyCreationForm		Constitution(name);
/*
	try
	{
		ShrubberyCreationForm		test1(Constitution);
		ShrubberyCreationForm		test3 = test1;
		std::cout << test1;
		std::cout << test3;
		GrandMaster.signForm(Constitution);
		Constitution.beSigned(GrandMaster);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}*/
	std::cout << GrandMaster;
	std::cout << Constitution;
	return 0;
}
