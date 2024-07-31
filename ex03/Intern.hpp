/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gprada-t <gprada-t@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 08:46:00 by gprada-t          #+#    #+#             */
/*   Updated: 2024/07/31 17:10:03 by gprada-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# define SHRUBBERY "shrubbery form"
# define ROBOTOMY "robotomy request"
# define PARDON "presidential pardon"

# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

typedef AForm*	(*Form)(std::string);

class	Intern
{
	public:
		Intern();
		~Intern();
		Intern(const Intern &src);
		Intern	&operator=(const Intern &src);
		
		AForm	*makeForm(std::string typeForm, std::string target);
		class	typeFormNotFound : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

#endif
