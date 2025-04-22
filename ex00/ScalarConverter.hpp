/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <junkwak@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-22 01:15:10 by junkwak           #+#    #+#             */
/*   Updated: 2025-04-22 01:15:10 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define        SCALARCONVERTER_HPP
#include <iostream>

class ScalarConverter
{
private :
        ScalarConverter(void);
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter other);
public  :
        static void    convert(std::string& str);

};

bool  check_convert(std::string& str);
int check_literal(std::string &str);

#endif