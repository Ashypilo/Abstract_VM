/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashypilo <ashypilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 17:45:31 by ashypilo          #+#    #+#             */
/*   Updated: 2019/11/18 14:49:36 by ashypilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Abstract.hpp" 

int main(int argc, char **argv)
{
    Abstract base;

    if (argc == 1)
        base.getLine();
    else
        base.getFile(argv[1]);
    return (0);
}
