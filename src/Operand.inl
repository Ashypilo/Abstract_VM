/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operand.inl                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashypilo <ashypilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 17:19:35 by ashypilo          #+#    #+#             */
/*   Updated: 2019/11/18 14:49:56 by ashypilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../includes/Operand.hpp"

template<class Type>
inline Operand<Type>::Operand(Type type_num, eOperandType type)
{
    this->type_num = type_num;
    this->type = type;
    this->out_string = std::to_string(type_num);
    this->factory = Factory();
}

template<class Type>
inline Operand<Type>::Operand(const Operand&) {}

template<class Type>
inline Operand<Type>& Operand<Type>::operator=(const Operand& copy)
{
    if (*this != copy)
    {
        this->type_num = copy.type_num;
        this->type = copy.type;
        this->out_string = std::to_string(copy.type_num);
    }
    return (*this);
}
template<class Type>
inline Operand<Type>::~Operand(){}

template<class Type>
inline eOperandType Operand<Type>::getType( void ) const
{
    return (this->type);
}

template<class Type>
inline std::string const & Operand<Type>::toString( void ) const
{
    return (out_string);
}

template<class Type>
inline int Operand<Type>::getPrecision( void ) const
{
    return (this->type_num);
}

template<class Type>
inline IOperand const *Operand<Type>::operator+( IOperand const & rhs ) const
{
    double i = stof(this->toString());
    double j = stof(rhs.toString());
    if (this->type > 2 || rhs.getType() > 2)
    {
        double out = i + j;
        if (this->type > rhs.getType())
            return (factory.createOperand(this->type, std::to_string(out)));
        else
            return (factory.createOperand(rhs.getType(), std::to_string(out)));
    }
    int out = i + j;
    if (this->type > rhs.getType())
        return (factory.createOperand(this->type, std::to_string(out)));
    else
        return (factory.createOperand(rhs.getType(), std::to_string(out)));
}

template<class Type>
inline IOperand const *Operand<Type>::operator-( IOperand const & rhs ) const
{
    double i = stof(this->toString());
    double j = stof(rhs.toString());
    if (this->type > 2 || rhs.getType() > 2)
    {
        double out = i - j;
        if (this->type > rhs.getType())
            return (factory.createOperand(this->type, std::to_string(out)));
        else
            return (factory.createOperand(rhs.getType(), std::to_string(out)));

    }
    int out = i - j;
    if (this->type > rhs.getType())
        return (factory.createOperand(this->type, std::to_string(out)));
    else
        return (factory.createOperand(rhs.getType(), std::to_string(out)));
}

template<class Type>
inline IOperand const *Operand<Type>::operator*( IOperand const & rhs ) const
{
    double i = stof(this->toString());
    double j = stof(rhs.toString());
    if (this->type > 2 || rhs.getType() > 2)
    {
        double out = i * j;
        if (this->type > rhs.getType())
            return (factory.createOperand(this->type, std::to_string(out)));
        else
            return (factory.createOperand(rhs.getType(), std::to_string(out)));
    }
    int out = i * j;
    if (this->type > rhs.getType())
        return (factory.createOperand(this->type, std::to_string(out)));
    else
        return (factory.createOperand(rhs.getType(), std::to_string(out)));
}

template<class Type>
inline IOperand const *Operand<Type>::operator/( IOperand const & rhs ) const
{
    double i = stof(this->toString());
    double j = stof(rhs.toString());
    if (j == 0)
        throw Exception::DivisionNullException();
    if (this->type > 2 || rhs.getType() > 2)
    {
        double out = i / j;
        if (this->type > rhs.getType())
            return (factory.createOperand(this->type, std::to_string(out)));
        else
            return (factory.createOperand(rhs.getType(), std::to_string(out)));
    }
    int out = i / j;
    if (this->type > rhs.getType())
        return (factory.createOperand(this->type, std::to_string(out)));
    else
        return (factory.createOperand(rhs.getType(), std::to_string(out)));
}

template<class Type>
inline IOperand const *Operand<Type>::operator%( IOperand const & rhs ) const
{
    if (rhs.getType() > 2 || this->type > 2)
        throw Exception::ModulException();
    int i = stof(this->toString());
    int j = stoi(rhs.toString());
    if (j == 0)
        throw Exception::DivisionNullException();
    int out = i % j;
    if (this->type > rhs.getType())
        return (factory.createOperand(this->type, std::to_string(out)));
    else
        return (factory.createOperand(rhs.getType(), std::to_string(out)));
}