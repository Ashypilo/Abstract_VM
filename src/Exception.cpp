/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exception.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashypilo <ashypilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 18:19:09 by ashypilo          #+#    #+#             */
/*   Updated: 2019/11/05 19:14:43 by ashypilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Exception.hpp"

Exception::Exception() {}

Exception::Exception(const Exception& copy)
{
    *this = copy;
}

Exception& Exception::operator=(const Exception& copy)
{
    (void)copy;
    return (*this);
}

Exception::~Exception() {}

Exception::InstructionUnknownException::InstructionUnknownException() {}

Exception::InstructionUnknownException::InstructionUnknownException(const InstructionUnknownException& over)
{
    *this = over;
}

Exception::InstructionUnknownException::~InstructionUnknownException() throw() {}

Exception::InstructionUnknownException& Exception::InstructionUnknownException::operator=(const Exception::InstructionUnknownException& over)
{
    exception::operator=(over);
    return (*this);
}

const char* Exception::InstructionUnknownException::what() const throw()
{
    return ("An instruction is unknown.");
}

Exception::OverflowException::OverflowException() {}

Exception::OverflowException::OverflowException(const OverflowException& over)
{
    *this = over;
}

Exception::OverflowException::~OverflowException() throw() {}

Exception::OverflowException& Exception::OverflowException::operator=(const Exception::OverflowException& over)
{
    exception::operator=(over);
    return (*this);
}

const char* Exception::OverflowException::what() const throw()
{
    return ("Overflow on a value.");
}

Exception::EmptyStackException::EmptyStackException() {}

Exception::EmptyStackException::EmptyStackException(const EmptyStackException& over)
{
    *this = over;
}

Exception::EmptyStackException::~EmptyStackException() throw() {}

Exception::EmptyStackException& Exception::EmptyStackException::operator=(const Exception::EmptyStackException& over)
{
    exception::operator=(over);
    return (*this);
}

const char* Exception::EmptyStackException::what() const throw()
{
    return ("An empty stack.");
}

Exception::LessTwoValuesException::LessTwoValuesException() {}

Exception::LessTwoValuesException::LessTwoValuesException(const LessTwoValuesException& over)
{
    *this = over;
}

Exception::LessTwoValuesException::~LessTwoValuesException() throw() {}

Exception::LessTwoValuesException& Exception::LessTwoValuesException::operator=(const Exception::LessTwoValuesException& over)
{
    exception::operator=(over);
    return (*this);
}

const char* Exception::LessTwoValuesException::what() const throw()
{
    return ("The stack is composed less that two values.");
}

Exception::AssertException::AssertException() {}

Exception::AssertException::AssertException(const AssertException& over)
{
    *this = over;
}

Exception::AssertException::~AssertException() throw() {}

Exception::AssertException& Exception::AssertException::operator=(const Exception::AssertException& over)
{
    exception::operator=(over);
    return (*this);
}

const char* Exception::AssertException::what() const throw()
{
    return ("An assert instruction is not true.");
}

Exception::ModulException::ModulException() {}

Exception::ModulException::ModulException(const ModulException& over)
{
    *this = over;
}

Exception::ModulException::~ModulException() throw() {}

Exception::ModulException& Exception::ModulException::operator=(const Exception::ModulException& over)
{
    exception::operator=(over);
    return (*this);
}

const char* Exception::ModulException::what() const throw()
{
    return ("The next operand is not an int type.");
}

Exception::DivisionNullException::DivisionNullException() {}

Exception::DivisionNullException::DivisionNullException(const DivisionNullException& over)
{
    *this = over;
}

Exception::DivisionNullException::~DivisionNullException() throw() {}

Exception::DivisionNullException& Exception::DivisionNullException::operator=(const Exception::DivisionNullException& over)
{
    exception::operator=(over);
    return (*this);
}

const char* Exception::DivisionNullException::what() const throw()
{
    return ("Division/module by 0.");
}