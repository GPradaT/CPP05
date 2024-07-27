/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gprada-t <gprada-t@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 10:43:26 by gprada-t          #+#    #+#             */
/*   Updated: 2024/07/27 12:07:58 by gprada-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	Bureaucrat	myLord;
	Bureaucrat Gi("Guille", 120);
	
	std::cout << Gi << std::endl;

	return 0;
}
