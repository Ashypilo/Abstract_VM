/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operand.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashypilo <ashypilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 16:43:38 by ashypilo          #+#    #+#             */
/*   Updated: 2019/11/18 14:53:45 by ashypilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERAND_HPP
#define OPERAND_HPP

#include <iostream>
#include "IOperand.hpp"
#include "Factory.hpp"
#include "Exception.hpp"
#include <string>

template<class Type>
class Operand: public IOperand
{
    public:
        Operand(Type, eOperandType);
        Operand(const Operand&);
        Operand& operator=(const Operand& copy);
        virtual ~Operand();

        eOperandType getType( void ) const;
        std::string const & toString( void ) const;
        int getPrecision( void ) const;
        IOperand const * operator+( IOperand const & rhs ) const;
        IOperand const * operator-( IOperand const & rhs ) const;
        IOperand const * operator*( IOperand const & rhs ) const;
        IOperand const * operator/( IOperand const & rhs ) const;
        IOperand const * operator%( IOperand const & rhs ) const;

    private:
        Type type_num;
        eOperandType type;
        std::string out_string;
        Factory factory;
};

#include "../src/Operand.inl"

#endif