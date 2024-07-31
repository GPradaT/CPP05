/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gprada-t <gprada-t@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 08:46:00 by gprada-t          #+#    #+#             */
/*   Updated: 2024/07/31 08:53:35 by gprada-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <iostream>
# include <fstream>

# include "Bureaucrat.hpp"

class	Bureaucrat;

class	AForm
{
	protected:
		const std::string	_name;
		bool			_isSigned;
		const int		_gradeToSign;
		const int		_gradeToExecute;

	public:
		AForm();
		AForm(const std::string name);
		AForm(const AForm &src);
		AForm(std::string name, const int gradeToSign, const int gradeToExec);
		virtual		~AForm();
		AForm		&operator=(const AForm &src);

		std::string	getName() const;
		bool		getIsSigned() const;
		int		getGradeToSign() const;
		int		getGradeToExecute() const;

		void		beSigned(const Bureaucrat &autor);
		virtual void	execute(const Bureaucrat &executor) const = 0;

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
