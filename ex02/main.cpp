/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gprada-t <gprada-t@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 10:43:26 by gprada-t          #+#    #+#             */
/*   Updated: 2024/07/28 12:03:00 by gprada-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define SEPARATOR "------------------------------------"

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	Bureaucrat	GrandMaster("Grand Master", 4);
	Form		Constitution("Constitution", 1, 1);

	try
	{
		Form		test1(Constitution);
		Form		test3 = test1;
		std::cout << test1;
		std::cout << test3;
		GrandMaster.signForm(Constitution);
		Constitution.beSigned(GrandMaster);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << GrandMaster;
	std::cout << Constitution;
	return 0;
}
