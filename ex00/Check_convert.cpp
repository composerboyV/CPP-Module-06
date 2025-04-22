/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Check_convert.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <junkwak@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-22 03:06:30 by junkwak           #+#    #+#             */
/*   Updated: 2025-04-22 03:06:30 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <string.h>

bool  check_convert(std::string& str)
{
      int   flag = 0;
      int   flag1 = 0;
      bool check_string(std::string &str);

      flag = check_literal(str);
      if (check_string(str) == true) {
      bool casting_char(std::string &str, int *flag);
      bool casting_int(std::string &str, int *flag);
      bool casting_float(std::string &str, int *flag);
      bool casting_double(std::string &str, int *flag);
      }
      else 
            return (false);
}

int  check_literal(std::string &str)
{      
      int i = 0;
      if (str == "nan" || str == "nanf" || str == "+inf" || str == "+inff" || \
      str == "-inf" || str == "-inff") {
            std::cout<<"impossible"<<std::endl;
            return (1);
}
      if (str.length() == 3 && str[0] == '\'' && str[2] == '\'') {
            char c = str[1];
            std::cout<<"'"<<c<<"'"<<std::endl;
      return (2);
}
      return (0);
}
bool   check_string(std::string& str)
{
      int   i = 0;
      int   check = 0;
      if (str.empty()) {
            std::cout<<"Empty String"<<std::endl;
            return (false);
      }
      i = str.length();
      while (str[i]) {
            if (str[i]<= '0' && str[i] >= '9' || str[i] != '.' || str[i] <= 'a' || str[i] >= 'f') {
                  std::cout<<"check string"<<std::endl;
                  return (false);
            }
            else if (str[i] == '.')
            check += 1;
            if (check >=  2) {
                  std::cout<<". twotwotwo"<<std::endl;
                  return (false);
            }
            i++;
      }
      return (true);
}
bool  casting_char(std::string& str, int flag)
{
      std::cout<<"char : ";

      if (str == "nan" || str == "nanf" || str == "+inf" || str == "+inff" || \
            str == "-inf" || str == "-inff") {
                  std::cout<<"impossible"<<std::endl;
                  return (true);
      }
      if (str.length() == 3 && str[0] == '\'' && str[2] == '\'') {
            char c = str[1];
            std::cout<<"'"<<c<<"'"<<std::endl;
            return (true);
      }
      try {
            int value = std::atoi(str.c_str());

            if (value < 0 || value > 127) {
                  std::cout<<"Impossible"<<std::endl;
                  return (true);
            }
            else if(isprint(value)) {
                  std::cout<<"'"<<static_cast<char>(value)<<"'"<<std::endl;
            }
            else {
                  std::cout<<"Non displayalbe"<<std::endl;
            }
      }
      catch(...) {
            std::cout<<"imposibbl"<<std::endl;
      }
      return true;

}
bool  casting_int(std::string& str, int flag)
{}
bool  casting_float(std::string& str, int flag)
{}
bool  casting_double(std::string& str, int flag)
{}