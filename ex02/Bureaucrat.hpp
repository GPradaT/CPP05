/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gprada-t <gprada-t@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 10:43:26 by gprada-t          #+#    #+#             */
/*   Updated: 2024/07/28 12:02:29 by gprada-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>

# include "Form.hpp"

class	Form;

class	Bureaucrat
{
	private:
		const std::string	_name;
		int			_grade;
	
	public:
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &src);
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat	&operator=(const Bureaucrat &src);

		std::string	getName() const;
		int		getGrade() const;

		void		incrementGrade();
		void		decrementGrade();
		void		signForm(Form &toSign);
		class	GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();	
		};
		class	GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &src);

#endif
