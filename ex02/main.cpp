/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gprada-t <gprada-t@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 10:43:26 by gprada-t          #+#    #+#             */
/*   Updated: 2024/07/29 12:44:24 by gprada-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define SEPARATOR "------------------------------------"

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int	main()
{
	std::string name = "Constitution";
	Bureaucrat	GrandMaster("Grand Master", 4);
	ShrubberyCreationForm		Constitution;
/*
	try
	{
		GrandMaster.signForm(Constitution);
		test3.beSigned(GrandMaster);
		std::cout << test3;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}*/
	std::cout << GrandMaster;
	std::cout << Constitution;
	return 0;
}
