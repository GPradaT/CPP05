/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gprada-t <gprada-t@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 08:46:00 by gprada-t          #+#    #+#             */
/*   Updated: 2024/07/29 10:27:08 by gprada-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : _name("Default"), _isSigned(false), _gradeToSign(150),
	_gradeToExecute(150)
{
    std::cout << "ShrubberyCreationForm constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : _name(src._name), _isSigned(src._isSigned),
	_gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute)
{
    std::cout << "Copy ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name)
	: _name(name)
{
	std::cout << name << "New Form Testing" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm destructor" << std::endl;
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
*/
void		ShrubberyCreationForm::beSigned(const Bureaucrat &autor)
{
	if (autor.getGrade() > getGradeToSign())
		throw GradeTooLowException();
	_isSigned = true;
}
