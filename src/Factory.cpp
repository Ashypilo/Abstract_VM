/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Factory.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashypilo <ashypilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 17:19:42 by ashypilo          #+#    #+#             */
/*   Updated: 2019/11/05 16:59:43 by ashypilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Factory.hpp"
#include "../includes/Operand.hpp"

Factory::Factory() {}

Factory::Factory(const Factory& copy)
{
    *this = copy;
}

Factory::~Factory() {}

Factory& Factory::operator=(const Factory& copy)
{
    (void)copy;
    return (*this);
}

IOperand const * Factory::createInt8( std::string const & value ) const
{
    return (new Operand<int_fast8_t>(static_cast<int_fast8_t>(stoi(value)), Int8));
}

IOperand const * Factory::createInt16( std::string const & value ) const
{
    return (new Operand<int_fast16_t>(static_cast<int_fast16_t>(stoi(value)), Int16));
}

IOperand const * Factory::createInt32( std::string const & value ) const
{
    return (new Operand<int_fast32_t>(static_cast<int_fast32_t>(stoi(value)), Int32));
}

IOperand const * Factory::createFloat( std::string const & value ) const
{
    return (new Operand<float>(static_cast<float>(stof(value)), Float));
}

IOperand const * Factory::createDouble( std::string const & value ) const
{
    return (new Operand<double>(static_cast<double>(stof(value)), Double));
}

IOperand const * Factory::createOperand(eOperandType type, std::string const & value ) const
{
   IOperand const *((Factory::*arr[]))(std::string const &value) const =
   {
        &Factory::createInt8,
        &Factory::createInt16,
        &Factory::createInt32,
        &Factory::createFloat,
        &Factory::createDouble
    };
    return (this->*arr[type])(value);

}
