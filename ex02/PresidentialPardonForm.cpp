/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gprada-t <gprada-t@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 08:46:00 by gprada-t          #+#    #+#             */
/*   Updated: 2024/07/30 17:33:59 by gprada-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon Form")
{
	_gradeToSign = 25;
	_gradeToExecute = 5;
	std::cout << "PresidentialPardonForm Default CONSTRUCTOR" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm ("Presidential Pardon Form")
{
	_target = target;
	_gradeToSign = 25;
	_gradeToExecute = 5;
	std::cout << "PresidentialPardonForm Parametrized CONSTRUCTOR" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src)
{
	
	std::cout << "Copy PresidentialPardonForm CONSTRUCTOR" << std::endl;
	*this = src;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm DESTRUCTOR" << std::endl;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	if (this != &src)
	{
		_isSigned = src._isSigned;
		_gradeToSign = src._gradeToSign;
		_gradeToExecute = src._gradeToExecute;
	}
	return *this;
}

void	PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	if (getIsSigned() && executor.getGrade() < getGradeToExecute())
	{
		std::cout << _target
			<< "has been pardoned by Zaphod Beeblebrox."
			<< std::endl;
	}
	else
		throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &out, const PresidentialPardonForm &src)
{
	out << "Form: " << src.getName() << ", Sign status: "
		<< (src.getIsSigned() ? "signed" : "not signed")
		<< ", Grade to sign: " << src.getGradeToSign()
		<< ", Grade to execute: " << src.getGradeToExecute()
		<< std::endl;
	return out;
}
/*
const char	*PresidentialPardonForm::GradeTooLowException::what() const throw()
{
	return "ROBOTOMY FAILED.";
}


const char	*PresidentialPardonForm::GradeTooHighException::what() const throw()
{
	return "You need lower grade.";
}
*/
