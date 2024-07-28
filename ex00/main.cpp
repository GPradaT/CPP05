/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gprada-t <gprada-t@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 10:43:26 by gprada-t          #+#    #+#             */
/*   Updated: 2024/07/28 08:46:00 by gprada-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define SEPARATOR "------------------------------------"

#include "Bureaucrat.hpp"

int	main()
{
	Bureaucrat	myLord;

	Bureaucrat Gi("Guille", 120);
	std::cout << SEPARATOR << std::endl;
	Bureaucrat Good("GrandMaster", 1);
	try
	{
		Bureaucrat tooLow("Guille", 0);
	}
	catch (const std::exception &excpt){
		std::cerr << excpt.what() << std::endl;
	}
	try
	{
		Bureaucrat tooHigh("Guille", 151);
	}
	catch (const std::exception &excpt)
	{
		std::cerr << excpt.what() << std::endl;
	}
	std::cout << SEPARATOR << std::endl;
	std::cout << Gi;
	std::cout << Good;
	int i = -1;
	while (++i < 20)
	{
		try
		{
			Gi.decrementGrade();
			std::cout << Gi;
			Good.incrementGrade();
			std::cout << Good;
		}
		catch (const std::exception &excpt)
		{
			std::cerr << excpt.what() << std::endl;
		}
		std::cout << SEPARATOR << std::endl;
	}
	std::cout << SEPARATOR << std::endl;
	std::cout << Gi;
	std::cout << Good;
	return 0;
}
