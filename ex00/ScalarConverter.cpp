/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <junkwak@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-22 01:15:06 by junkwak           #+#    #+#             */
/*   Updated: 2025-04-22 01:15:06 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter& other) 
{
      *this = other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter other) 
{
      if (this != &other) {
            *this = other;
      }
      return (*this);
}

void    ScalarConverter::convert(std::string& str)
{
      if (check_convert(str) == false)
            std::cout<<"Errorrrrr"<<std::endl;
}
