/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gprada-t <gprada-t@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 08:46:00 by gprada-t          #+#    #+#             */
/*   Updated: 2024/07/29 12:38:06 by gprada-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
{
	_gradeToSign = 145;
	_gradeToExecute = 137;
	std::cout << "ShrubberyCreationForm CONSTRUCTOR" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
{
	
	std::cout << "Copy ShrubberyCreationForm CONSTRUCTOR" << std::endl;
	*this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm DESTRUCTOR" << std::endl;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	if (this != &src)
	{
		_isSigned = src._isSigned;
		_gradeToSign = src._gradeToSign;
		_gradeToExecute = src._gradeToExecute;
	}
	return *this;
}

std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm &src)
{
	out << "ShrubberyCreationForm: " << src.getName() << ", Sign status: "
		<< (src.getIsSigned() ? "signed" : "not signed")
		<< ", Grade to sign: " << src.getGradeToSign()
		<< ", Grade to execute: " << src.getGradeToExecute()
		<< std::endl;
	return out;
}
/*
const char	*ShrubberyCreationForm::GradeTooHighException::what() const throw()
{
	return "You need lower grade.";
}

const char	*ShrubberyCreationForm::GradeTooLowException::what() const throw()
{
	return "You need higher grade.";
}

std::string	ShrubberyCreationForm::getName() const
{
	return this->_name;
}

bool		ShrubberyCreationForm::getIsSigned() const
{
	return this->_isSigned;
}

int		ShrubberyCreationForm::getGradeToSign() const
{
	return this->_gradeToSign;
}

int		ShrubberyCreationForm::getGradeToExecute() const
{
	return this->_gradeToExecute;
}

void		ShrubberyCreationForm::beSigned(const Bureaucrat &autor)
{
	if (autor.getGrade() > getGradeToSign())
		throw GradeTooLowException();
	_isSigned = true;
}*/
