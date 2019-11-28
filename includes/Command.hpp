/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashypilo <ashypilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 16:18:31 by ashypilo          #+#    #+#             */
/*   Updated: 2019/11/06 15:40:33 by ashypilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <vector>
#include "Exception.hpp"
#include "Factory.hpp"
#include <iostream>
#include <regex>

# define  INT_8 std::regex ("int8")
# define  INT_16 std::regex ("int16")
# define  INT_32 std::regex ("int32")
# define  FLOAT std::regex ("float")
# define  DOUBLE std::regex ("double")

class Command
{
    public:
        Command();
        Command(const Command&);
        Command& operator=(const Command&);
        ~Command();

        std::vector<std::vector<std::string> > pop(std::vector<std::vector<std::string> >);
        void dump(std::vector<std::string>);
        std::vector<std::vector<std::string> > add(std::vector<std::vector<std::string> >);
        std::vector<std::vector<std::string> > sub(std::vector<std::vector<std::string> >);
        std::vector<std::vector<std::string> > mul(std::vector<std::vector<std::string> >);
        std::vector<std::vector<std::string> > div(std::vector<std::vector<std::string> >);
        std::vector<std::vector<std::string> > mod(std::vector<std::vector<std::string> >);
        void print(std::vector<std::vector<std::string> >);
        void assert(std::vector<std::vector<std::string> >, std::string, std::string);
        void exit();
        void max(std::vector<std::vector<std::string> >);
        void min(std::vector<std::vector<std::string> >);
        void type(std::vector<std::vector<std::string> >);
        eOperandType definition_type(std::string line);
        std::vector<std::vector<std::string> > delete_elem_and_push(std::vector<std::vector<std::string> > line);
        void create_stack(std::vector<std::vector<std::string> > line);

    private:
        Factory first_add;
        Factory second_add;
        std::vector<IOperand const*> stack;
        IOperand const * first_operand;
	    IOperand const * second_operand;
};

#endif