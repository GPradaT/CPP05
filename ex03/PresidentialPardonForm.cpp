/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gprada-t <gprada-t@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 08:46:00 by gprada-t          #+#    #+#             */
/*   Updated: 2024/07/31 09:43:53 by gprada-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon Form", 25, 5)
{
	_isSigned = false;
	std::cout << "PresidentialPardonForm Default CONSTRUCTOR" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm ("Presidential Pardon Form", 25, 5)
{
	_isSigned = false;
	_target = target;
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
		_target = src._target;
		_isSigned = src._isSigned;
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
		throw PresidentTooLowException();
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

const char	*PresidentialPardonForm::PresidentTooLowException::what() const throw()
{
	return "U ARE NOT PRESIDENT .l.. u cannot execute b*** .";
}
