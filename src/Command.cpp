/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashypilo <ashypilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 16:18:22 by ashypilo          #+#    #+#             */
/*   Updated: 2019/11/13 16:04:03 by ashypilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Command.hpp"

Command::Command() {}

Command::Command(const Command& copy)
{
    *this = copy;
}

Command::~Command() {}

Command& Command::operator=(const Command& copy)
{
    (void)copy;
    return (*this);
}

eOperandType Command::definition_type(std::string line)
{
    if (regex_search(line, INT_8))
        return (Int8);
    else if (regex_search(line, INT_16))
        return (Int16);
    else if (regex_search(line, INT_32))
        return (Int32);
    else if (regex_search(line, FLOAT))
        return (Float);
    return (Double);
}

std::vector<std::vector<std::string> > Command::pop(std::vector<std::vector<std::string> > line)
{
    if (line[0].empty())
        throw Exception::EmptyStackException();
    line[0].pop_back();
    line[1].pop_back();
    return (line);
}

void Command::dump(std::vector<std::string> number)
{
    if (number.empty())
        throw Exception::EmptyStackException();
    int i = number.size() - 1;
    while(i >= 0)
    {
        std::cout << number[i] << std::endl;
        i--;
    }
}

std::vector<std::vector<std::string> > Command::delete_elem_and_push(std::vector<std::vector<std::string> > line)
{
    line[0].pop_back();
    line[0].pop_back();
    line[1].pop_back();
    line[1].pop_back();
    if (stack[2]->getType() == 0)
        line[0].push_back("int8");
    else if (stack[2]->getType() == 1)
        line[0].push_back("int16");
    else if (stack[2]->getType() == 2)
        line[0].push_back("int32");
    else if (stack[2]->getType() == 3)
        line[0].push_back("float");
    else if (stack[2]->getType() == 4)
        line[0].push_back("double");
    line[1].push_back(stack[2]->toString());
    for (int i =0; i < 3; i++)
        stack.pop_back();
    return (line);
}

void Command::create_stack(std::vector<std::vector<std::string> > line)
{
    if (line[0].empty())
        throw Exception::EmptyStackException();
    if (line[0].size() < 2)
        throw Exception::LessTwoValuesException();
    int i = line[0].size() - 1;
    eOperandType type_first = definition_type(line[0][i]);
    eOperandType type_second = definition_type(line[0][i - 1]);
    if (type_first > 2)
        stack.push_back(first_add.createOperand(type_first, std::to_string(stof(line[1][i]))));
    else 
        stack.push_back(first_add.createOperand(type_first, std::to_string(stoi(line[1][i]))));
    if (type_second > 2)
        stack.push_back(second_add.createOperand(type_second, std::to_string(stof(line[1][i - 1]))));
    else
        stack.push_back(second_add.createOperand(type_second, std::to_string(stoi(line[1][i - 1]))));
    first_operand = stack[1];
    second_operand = stack[0];
}

std::vector<std::vector<std::string> > Command::add(std::vector<std::vector<std::string> > line)
{
    create_stack(line);
    stack.push_back(*first_operand + *second_operand);
    return (delete_elem_and_push(line));
}

std::vector<std::vector<std::string> > Command::sub(std::vector<std::vector<std::string> > line)
{
    create_stack(line);
    stack.push_back(*first_operand - *second_operand);
    return (delete_elem_and_push(line));
}

std::vector<std::vector<std::string> > Command::mul(std::vector<std::vector<std::string> > line)
{
    create_stack(line);
    stack.push_back(*first_operand * *second_operand);
    return (delete_elem_and_push(line));
}

std::vector<std::vector<std::string> > Command::div(std::vector<std::vector<std::string> > line)
{
    create_stack(line);
    stack.push_back(*first_operand / *second_operand);
    return (delete_elem_and_push(line));
}

std::vector<std::vector<std::string> > Command::mod(std::vector<std::vector<std::string> > line)
{
    
    create_stack(line);
    stack.push_back(*first_operand % *second_operand);
    return (delete_elem_and_push(line));
}

void Command::print(std::vector<std::vector<std::string> > line)
{
     if (line[0].empty())
        throw Exception::EmptyStackException();
    int i = line[1].size() - 1;
    if (regex_search(line[0][i], INT_8))
    {
        int out = stoi(line[1][i]);
        char c = out;
        std::cout << c << std::endl;
    }
    else
        throw Exception::AssertException();       
}

void Command::assert(std::vector<std::vector<std::string> > line, std::string assert_number, std::string assert_line)
{
     if (line[0].empty())
        throw Exception::EmptyStackException();
    std::regex assert_reg(assert_number);
    if (definition_type(line[0][line[0].size() - 1]) == definition_type(assert_line) && regex_search(line[1][line[1].size() - 1], assert_reg))
        std::cout << "Assert is true" << std::endl;
    else
        throw Exception::AssertException();
}

void Command::max(std::vector<std::vector<std::string> > line)
{
    if (line[0].empty())
        throw Exception::EmptyStackException();
    std::vector<double> _max;
    int j = line[0].size();
    for (int i = 0; i < j; i++)
    {
        if (definition_type(line[0][i]) > 2)
            _max.push_back(stof(line[1][i]));
        else
            _max.push_back(stoi(line[1][i]));
    }
    sort(_max.begin(), _max.end());
    std::cout << _max[_max.size() - 1] << std::endl;
}

void Command::min(std::vector<std::vector<std::string> > line)
{
    if (line[0].empty())
        throw Exception::EmptyStackException();
            std::vector<double> _min;
    int j = line[0].size();
    for (int i = 0; i < j; i++)
    {
        if (definition_type(line[0][i]) > 2)
            _min.push_back(stof(line[1][i]));
        else
            _min.push_back(stoi(line[1][i]));
    }
    sort(_min.begin(), _min.end());
    std::cout << _min[0] << std::endl;
}

void Command::type(std::vector<std::vector<std::string> > line)
{
    if (line[0].empty())
        throw Exception::EmptyStackException();
    std::cout << "Type " + line[0][line[0].size() - 1] + " number " + line[1][line[1].size() - 1] << std::endl;
}