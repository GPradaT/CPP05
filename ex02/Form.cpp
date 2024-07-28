/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gprada-t <gprada-t@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 08:46:00 by gprada-t          #+#    #+#             */
/*   Updated: 2024/07/28 12:09:47 by gprada-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Default"), _isSigned(false), _gradeToSign(150),
	_gradeToExecute(150)
{
    std::cout << "Form constructor" << std::endl;
}

Form::Form(const Form &src) : _name(src._name), _isSigned(src._isSigned),
	_gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute)
{
    std::cout << "Copy Form constructor called" << std::endl;
}

Form::Form(std::string name, const int gradeToSign, const int gradeToExec)
	: _name(name)
{
    if (gradeToSign < 1 || gradeToExec < 1)
        throw GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExec > 150)
        throw GradeTooLowException();
    _gradeToSign = gradeToSign;
    _gradeToExecute = gradeToExec;
    _isSigned = false;
}

Form::~Form()
{
    std::cout << "Form destructor" << std::endl;
}

Form	&Form::operator=(const Form &src)
{
    if (this != &src)
    {
        _isSigned = src._isSigned;
        _gradeToSign = src._gradeToSign;
        _gradeToExecute = src._gradeToExecute;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &out, const Form &src)
{
    out << "Form: " << src.getName() << ", Sign status: "
	    << (src.getIsSigned() ? "signed" : "not signed")
	    << ", Grade to sign: " << src.getGradeToSign()
	    << ", Grade to execute: " << src.getGradeToExecute()
	    << std::endl;
    return out;
}

const char	*Form::GradeTooHighException::what() const throw()
{
	return "You need lower grade.";
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return "You need higher grade.";
}

std::string	Form::getName() const
{
	return this->_name;
}

bool		Form::getIsSigned() const
{
	return this->_isSigned;
}

int		Form::getGradeToSign() const
{
	return this->_gradeToSign;
}

int		Form::getGradeToExecute() const
{
	return this->_gradeToExecute;
}

void		Form::beSigned(const Bureaucrat &autor)
{
	if (autor.getGrade() > getGradeToSign())
		throw GradeTooLowException();
	_isSigned = true;
}
