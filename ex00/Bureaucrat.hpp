/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gprada-t <gprada-t@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 10:43:26 by gprada-t          #+#    #+#             */
/*   Updated: 2024/07/28 08:31:36 by gprada-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>

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
