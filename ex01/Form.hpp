/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gprada-t <gprada-t@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 08:46:00 by gprada-t          #+#    #+#             */
/*   Updated: 2024/07/28 10:36:13 by gprada-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>

class	Form
{
	private:
		const std::string	_name;
		bool			_isSigned;
		int			_gradeToSign;
		int			_gradeToExecute;

	public:
		Form();
		~Form();
		Form(const Form &src);
		Form(std::string name, const int gradeToSign, const int gradeToExec);
		Form	&operator=(const Form &src);

		std::string		getName() const;
		bool			getIsSigned() const;
		int			getGradeToSign() const;
		int			getGradeToExecute() const;

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

std::ostream	&operator<<(std::ostream &out, const Form &src);

#endif
