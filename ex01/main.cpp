/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gprada-t <gprada-t@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 10:43:26 by gprada-t          #+#    #+#             */
/*   Updated: 2024/07/28 10:52:45 by gprada-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define SEPARATOR "------------------------------------"

#include "Bureaucrat.hpp"
#include "Form.hpp"
int main() {
    try {
        // Crear una instancia de Form con los argumentos apropiados
        Form test1("Form1", 5, 10);

        // Crear una copia de test1 utilizando el constructor de copia
        Form test3(test1);

        // Imprimir el objeto Form para verificar los valores
        std::cout << test3 << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
/*
int	main()
{
	Bureaucrat	GrandMaster("Grand Master", 1);
	Form		Constitution("Constitution", 1, 1);

	try
	{
		Form		test1();
		Form		test3 = test1;
		
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << GrandMaster;
	return 0;
}*/
