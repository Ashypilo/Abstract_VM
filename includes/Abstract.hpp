/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Abstract.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashypilo <ashypilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 18:07:45 by ashypilo          #+#    #+#             */
/*   Updated: 2019/11/04 20:40:57 by ashypilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUTBASE_HPP
#define INPUTBASE_HPP

#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>
#include <sstream>
#include <regex>
#include "Exception.hpp"
#include "Factory.hpp"
#include "Command.hpp"

# define  INT_8 std::regex ("int8")
# define  INT_16 std::regex ("int16")
# define  INT_32 std::regex ("int32")
# define  FLOAT std::regex ("float")
# define  DOUBLE std::regex ("double")

class Abstract
{
    public:
        Abstract();
        Abstract(const Abstract&);
        Abstract& operator=(const Abstract&);
        ~Abstract();

        void out();
        void getLine();
        void getFile(std::string);
        void CheckDescription(std::string);
        void checkNumber(std::string line);
        void checkIntNumber(std::string);
        void checkFloatNumber(std::string);
        void checkDoubleNumber(std::string);
        std::string createNumberString(std::string, int, int);
    
    private:
        std::vector<std::vector<std::string> > line;
        std::vector<std::string> number;
        std::string number_srting;
        Command command;
        int assert_type;
        std::string assert_number;
};

#endif