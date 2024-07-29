/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gprada-t <gprada-t@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 08:46:00 by gprada-t          #+#    #+#             */
/*   Updated: 2024/07/29 10:26:44 by gprada-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <iostream>

# include "Bureaucrat.hpp"

class	Bureaucrat;

class	AForm
{
	protected:
		const std::string	_name;
		bool			_isSigned;
		int			_gradeToSign;
		int			_gradeToExecute;

	public:
		AForm();
		AForm(const AForm &src);
		AForm(std::string name, const int gradeToSign, const int gradeToExec);
		virtual		~AForm();
		AForm		&operator=(const AForm &src);

		std::string	getName() const;
		bool		getIsSigned() const;
		int		getGradeToSign() const;
		int		getGradeToExecute() const;

		virtual void	beSigned(const Bureaucrat &autor) = 0;

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

std::ostream	&operator<<(std::ostream &out, const AForm &src);

#endif
