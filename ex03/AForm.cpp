/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gprada-t <gprada-t@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 08:46:00 by gprada-t          #+#    #+#             */
/*   Updated: 2024/07/31 09:28:10 by gprada-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("Default"), _isSigned(false), _gradeToSign(150),
	_gradeToExecute(150)
{
	std::cout << "AForm DEFAULT constructor" << std::endl;
}

AForm::AForm(const std::string name) : _name(name), _isSigned(false),
	_gradeToSign(150), _gradeToExecute(150)
{
	std::cout << "AForm PARAMETRIZED constructor" << std::endl;
}

AForm::AForm(const AForm &src) : _name(src._name), _isSigned(src._isSigned),
	_gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute)
{
	std::cout << "Copy AForm constructor called" << std::endl;
}

AForm::AForm(std::string name, const int gradeToSign, const int gradeToExec)
	: _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExec)
{
	if (gradeToSign < 1 || gradeToExec < 1)
		throw GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExec > 150)
		throw GradeTooLowException();
	_isSigned = false;
}

AForm::~AForm()
{
	std::cout << "AForm destructor" << std::endl;
}

AForm	&AForm::operator=(const AForm &src)
{
	if (this != &src)
	{
		_isSigned = (src._isSigned);
	}
	return *this;
}

std::ostream &operator<<(std::ostream &out, const AForm &src)
{
	out << "AForm: " << src.getName() << ", Sign status: "
		<< (src.getIsSigned() ? "signed" : "not signed")
		<< ", Grade to sign: " << src.getGradeToSign()
		<< ", Grade to execute: " << src.getGradeToExecute()
		<< std::endl;
	return out;
}

const char	*AForm::GradeTooHighException::what() const throw()
{
	return "You need lower grade.";
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return "You need higher grade.";
}

std::string	AForm::getName() const
{
	return this->_name;
}

bool		AForm::getIsSigned() const
{
	return this->_isSigned;
}

int		AForm::getGradeToSign() const
{
	return this->_gradeToSign;
}

int		AForm::getGradeToExecute() const
{
	return this->_gradeToExecute;
}

void		AForm::beSigned(const Bureaucrat &autor)
{
	if (autor.getGrade() > getGradeToSign())
		throw GradeTooLowException();
	_isSigned = true;
}
