/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exception.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashypilo <ashypilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 18:19:52 by ashypilo          #+#    #+#             */
/*   Updated: 2019/11/05 17:56:42 by ashypilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <exception>
#include <iostream>

class Exception
{
    public:
        Exception();
        Exception(const Exception&);
        Exception& operator=(const Exception&);
        ~Exception();

    public:
        class InstructionUnknownException: public std::exception
        {
            public:
            InstructionUnknownException();
            InstructionUnknownException(const InstructionUnknownException&);
            virtual ~InstructionUnknownException() throw();

            InstructionUnknownException& operator=(const InstructionUnknownException&);

            const char* what() const throw();
        };
        
        class OverflowException: public std::exception
        {
            public:
            OverflowException();
            OverflowException(const OverflowException&);
            virtual ~OverflowException() throw();

            OverflowException& operator=(const OverflowException&);

            const char* what() const throw();
        };

        class EmptyStackException: public std::exception
        {
            public:
            EmptyStackException();
            EmptyStackException(const EmptyStackException&);
            virtual ~EmptyStackException() throw();

            EmptyStackException& operator=(const EmptyStackException&);

            const char* what() const throw();
        };

        class LessTwoValuesException: public std::exception
        {
            public:
            LessTwoValuesException();
            LessTwoValuesException(const LessTwoValuesException&);
            virtual ~LessTwoValuesException() throw();

            LessTwoValuesException& operator=(const LessTwoValuesException&);

            const char* what() const throw();
        };

        class AssertException: public std::exception
        {
            public:
            AssertException();
            AssertException(const AssertException&);
            virtual ~AssertException() throw();

            AssertException& operator=(const AssertException&);

            const char* what() const throw();
        };

        class ModulException: public std::exception
        {
            public:
            ModulException();
            ModulException(const ModulException&);
            virtual ~ModulException() throw();

            ModulException& operator=(const ModulException&);

            const char* what() const throw();
        };

            class DivisionNullException: public std::exception
        {
            public:
            DivisionNullException();
            DivisionNullException(const DivisionNullException&);
            virtual ~DivisionNullException() throw();

            DivisionNullException& operator=(const DivisionNullException&);

            const char* what() const throw();
        };

};

#endif