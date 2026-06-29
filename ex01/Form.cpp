/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeskhai <maeskhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 18:07:24 by maeskhai          #+#    #+#             */
/*   Updated: 2026/06/29 16:31:40 by maeskhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form()
    : name("Default"), isSigned(false), gradeToSign(150), gradeToExecute(150) {}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
    : name(name), isSigned(false),
      gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

Form::Form(const Form& other)
    : name(other.name),
      isSigned(other.isSigned),
      gradeToSign(other.gradeToSign),
      gradeToExecute(other.gradeToExecute) {}

Form& Form::operator=(const Form& other)
{
    if (this != &other)
        this->isSigned = other.isSigned;
    return *this;
}

Form::~Form() {}

std::string Form::getName() const { return name; }
bool Form::getIsSigned() const { return isSigned; }
int Form::getGradeToSign() const { return gradeToSign; }
int Form::getGradeToExecute() const { return gradeToExecute; }

void Form::beSigned(const Bureaucrat& b)
{
    if (b.getGrade() > gradeToSign)
        throw GradeTooLowException();
    isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Form grade too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Form grade too low!";
}

std::ostream& operator<<(std::ostream& out, const Form& f)
{
    out << f.getName()
        << ", form sign grade " << f.getGradeToSign()
        << ", execute grade " << f.getGradeToExecute()
        << ", signed: " << (f.getIsSigned() ? "yes" : "no");
    return out;
}