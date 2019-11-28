/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Abstract.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashypilo <ashypilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 18:23:39 by ashypilo          #+#    #+#             */
/*   Updated: 2019/11/13 16:03:05 by ashypilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Abstract.hpp"

Abstract::Abstract()
{
    line = std::vector<std::vector<std::string> >(2);
    command = Command();
}

Abstract::Abstract(const Abstract& copy)
{
    *this = copy;
}

Abstract::~Abstract() {}

Abstract& Abstract::operator=(const Abstract& copy)
{
    (void)copy;
    return (*this);
}

void Abstract::checkIntNumber(std::string line)
{
    int_fast32_t num32;
    int_fast16_t num16;
    int_fast8_t num8;
    if (regex_search(line, INT_8))
    {
        std::string s(line.begin() + 10, line.end());
        try
        {
            num8 = stoi(s);
        }
        catch (std::out_of_range& e)
        {
            throw Exception::OverflowException();
        }
        if (num8 > CHAR_MAX || num8 < CHAR_MIN)
            throw Exception::OverflowException();
        this->number_srting = std::to_string(num8);
    }
    else if (regex_search(line, INT_16))
    {
        std::string s(line.begin() + 11, line.end());
        try
        {
            num16 = stoi(s);
        }
        catch (std::out_of_range& e)
        {
            throw Exception::OverflowException();
        }
        if (num16 > SHRT_MAX || num16 < SHRT_MIN)
            throw Exception::OverflowException();
        this->number_srting = std::to_string(num16);
    }
    else if (regex_search(line, INT_32))
    {
        std::string s(line.begin() + 11, line.end());
        try
        {
            num32 = stoi(s);
        }
        catch (std::out_of_range& e)
        {
            throw Exception::OverflowException();
        }
        this->number_srting = std::to_string(num32);
    }
}

void Abstract::checkFloatNumber(std::string line)
{
    try
    {
        float num;
        std::string s(line.begin() + 11, line.end());
        num = stof(s);
        this->number_srting = std::to_string(num);
    }
    catch(std::out_of_range& e)
    {
        throw Exception::OverflowException();
    }
}

void Abstract::checkDoubleNumber(std::string line)
{
    try
    {
        double num;
        std::string s(line.begin() + 12, line.end());
        num = stof(s);
        this->number_srting = std::to_string(num);
    }
    catch(std::out_of_range& e)
    {
        throw Exception::OverflowException();
    }
}

void Abstract::checkNumber(std::string line)
{
    std::regex int_number("int");

    if (regex_search(line, int_number))
        this->checkIntNumber(line);
    else if (regex_search(line, FLOAT))
        this->checkFloatNumber(line);
    else if (regex_search(line, DOUBLE))
        this->checkDoubleNumber(line);
}

void Abstract::CheckDescription(std::string line_origin)
{ 
    std::regex push("(^push int(8|16|32)\\([-]?\\d+\\)$|(^push int(8|16|32)\\([-]?\\d+\\) ;.+$))|(^push (float|double)\\([-]?\\d*[.]*?\\d+\\)$|(^push (float|double)\\([-]?\\d*[.]*?\\d+\\) ;.+$))");
    std::regex assert("(^assert int(8|16|32)\\([-]?\\d+\\)$|(^assert int(8|16|32)\\([-]?\\d+\\) ;.+$))|(^assert (float|double)\\([-]?\\d*[.]*?\\d+\\)$|(^assert (float|double)\\([-]?\\d*[.]*?\\d+\\) ;.+$))");
    std::regex pop("(^pop$|(^pop ;.+$))");
    std::regex dump("(^dump$|(^dump ;.+$))");
    std::regex add("(^add$|(^add ;.+$))");
    std::regex sub("(^sub$|(^sub ;.+$))");
    std::regex mul("(^mul$|(^mul ;.+$))");
    std::regex div("(^div$|(^div ;.+$))");
    std::regex mod("(^mod$|(^mod ;.+$))");
    std::regex print("(^print$|(^print ;.+$))");
    std::regex _max("(^max$|(^max ;.+$))");
    std::regex _min("(^min$|(^min ;.+$))");
    std::regex type("(^type$|(^type ;.+$))");
    
    if (regex_match(line_origin, pop))
        this->line = this->command.pop(this->line);
    else if (regex_match(line_origin, dump))
        this->command.dump(this->line[1]);
    else if (regex_match(line_origin, add))
        this->line = this->command.add(this->line);
    else if (regex_match(line_origin, sub))
        this->line = this->command.sub(this->line);
    else if (regex_match(line_origin, mul))
        this->line = this->command.mul(this->line);
    else if (regex_match(line_origin, div))
        this->line = this->command.div(this->line);
    else if (regex_match(line_origin, mod))
        this->line = this->command.mod(this->line);
    else if (regex_match(line_origin, print))
        this->command.print(this->line);
    else if (regex_match(line_origin, _max))
        this->command.max(this->line);
    else if (regex_match(line_origin, _min))
        this->command.min(this->line);
    else if (regex_match(line_origin, type))
        this->command.type(this->line);
    else if (regex_match(line_origin, push))
    {
        this->checkNumber(line_origin);
        this->line[0].push_back(&line_origin[5]);
        this->line[1].push_back(this->number_srting);  
    }
    else if (regex_match(line_origin, assert))
    {
        this->checkNumber(&line_origin[2]);
        this->command.assert(line, this->number_srting, line_origin);
    }
    else if (line_origin == "\0" || line_origin == "\n" || line_origin[0] == ';')
    {
    }
    else
        throw Exception::InstructionUnknownException();
}

void Abstract::getLine()
{
    int stop = 0; 
    std::string line_origin;
    std::regex exit("(^;;$|(^;; ;.+$))");
    std::regex exit_out("(^exit$|(^exit ;.+$))");
    try
    {
        while (std::getline(std::cin, line_origin))
        {
            if (regex_match(line_origin, exit_out))
            {
                stop = 1;
                std::cout << "Please enter ;;" << std::endl;
            }
            else if (regex_match(line_origin, exit) && stop == 1)
                break ;
            else if (regex_match(line_origin, exit) && stop == 0)
            {
                throw Exception::InstructionUnknownException();
            }
            else
                this->CheckDescription(line_origin);
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }  
}

void Abstract::getFile(std::string fileName)
{
    std::ifstream file(fileName);
    std::string line_origin;
    std::regex exit("(^exit$|(^exit ;.+$))");
    try
    {
        while(getline(file, line_origin))
        {
            if (regex_match(line_origin, exit))
                break ;
            this->CheckDescription(line_origin);
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}
