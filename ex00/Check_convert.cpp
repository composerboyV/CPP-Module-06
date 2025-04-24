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
#include <stdio.h>
#include <stdlib.h>
#include <limits>
#include <string>
#include <iomanip>
#include <limits>
#include <cerrno>
#include <cstdlib>
#include <cmath>

bool  check_convert(std::string& str)
{
      int   flag = 0;
      int   flag1= 0;
      bool casting_char(std::string &str, int flag);
      bool check_string(std::string &str);
      bool casting_int(std::string &str, int flag);
      bool casting_float(std::string &str, int flag, int flag1);
      bool casting_double(std::string &str, int flag);


      for(int i = 0; str[i]; i++)
      {
            if (str[i] == '.')
                  flag1 += 1;
            if (flag1 == 2) {
                  std::cout<<"DOts twotwotwo"<<std::endl;
                  return (0);
            }
      }
      if (str == "+" || str == "-" || str == "-nan")
      return (false);
      flag = check_literal(str);
      if (flag == -1) {
            return (0);
      }
      if (flag != 2) {
      for(int i = 1; str[i]; i++) {
            if (str[i] <= '0' || str[i] >= '9')
                  return (false);
      }
      }
      casting_char(str, flag);
      casting_int(str, flag);
      casting_float(str, flag, flag1);
      casting_double(str, flag);
      return (true);
}


int is_special_literal(const std::string& str) {
      const char* special_literals[] = {
          "nan", "nanf", "inf", "+inf", "inff", "+inff", "-inf", "-inff" 
      };
      for (size_t i = 0; i < sizeof(special_literals)/sizeof(special_literals[0]); ++i) {
          if (str == special_literals[i]) {
            return (2);
          }
      }
      try {
            char *endptr;
            double value = std::strtod(str.c_str(), &endptr);
            if (endptr != str.c_str()) {
                  if (value > std::numeric_limits<double>::max() || 
                  value < -std::numeric_limits<double>::max())
                        return (-1);
            }
      }
      catch (...) {
            return (false);
      }
      return (false);
  }
  
int check_literal(std::string &str) {      
     int i = is_special_literal(str);
      if (i == -1)
            return -1;
      if (str.length() == 3 && str[0] == '\'' && str[2] == '\'') {
          return (3);
      }
      return (i);
}
  
bool  casting_char(std::string& str, int flag)
{
      
      std::cout<<"char : ";
      if (flag == 2) {
                  std::cout<<"impossible"<<std::endl;
                  return (0);
      }
      if (str.length() == 3 && str[0] == '\'' && str[2] == '\'') {
            char c = str[1];
            std::cout<<"'"<<c<<"'"<<std::endl;
            return (0);
      }
      try {
            int value = atoi(str.c_str());
            if (value < 0 || value > 127) {
                  std::cout<<"impossible"<<std::endl;
                  return (0);
            }
            else if(value >= -128 && value <= 127 && isprint(value)) {
                  std::cout<<"'"<<static_cast<char>(value)<<"'"<<std::endl;
                  return (0);
            }
            else {
                  std::cout<<"Non displayalbe"<<std::endl;
            }
      }
      catch(...) {
            std::cout<<"impossible"<<std::endl;
      }
      return (0);

}
bool  casting_int(std::string& str, int flag)
{

      std::cout<<"int : ";
      if (flag == 2) {
            std::cout<<"impossible"<<std::endl;
            return (false);
      }
      if (str.length() == 3 && str[0] == '\'' && str[2] == '\'') {
            int c = str[1];
            std::cout<<c<<std::endl;
            return (0);
      }
      try {
            char* endptr;
            long  value = std::strtol(str.c_str(), &endptr, 10);
            if (endptr == str.c_str() && *endptr != '\0') {
                  std::cout<<"impossible"<<std::endl;
                  return (false);
            }
            else if (value < std::numeric_limits<int>::min() || \
            value > std::numeric_limits<int>::max()) {
                  std::cout<<"impossible"<<std::endl;
                  return (false);
            }
      std::cout<<"'"<<static_cast<int>(value)<<"'"<<std::endl;
      }

      catch(...) {
      std::cout<<"exception"<<std::endl;
            return (false);
      }
      return (true);
}

bool  casting_float(std::string& str, int flag, int flag1)
{
      std::cout<<"Float :";
      if (flag == 2) {
            if (str == "nan" || str == "nanf") {
            std::cout<<"nanf"<<std::endl;
            return (true);
      }
      else if (str == "inf") {
            std::cout<<"inff"<<std::endl;
            return (true);
      }
      else if (str == "+inf" || str == "+inff") {
            std::cout<<"+inff"<<std::endl;
            return (true);
      }
      else if (str == "-inf" || str == "-inff") {
            std::cout<<"-inff"<<std::endl;
            return (true);
      }
      }
      int   flag2 = 0;
      double value = static_cast<float>(std::atof(str.c_str()));
      if (value < -std::numeric_limits<float>::max() || 
      value > std::numeric_limits<float>::max())
      {
            std::cout<<"over Flow!!"<<std::endl;
            return (false);
      }
      if (str.length() == 'f' && str[0] != 'f')
            flag2 = 1;
      if ((str.length() == 3 && str[0] == '\'' && str[2] == '\'')) {
            float c = str[1];
            std::cout<<c<<".0f"<<std::endl;
            return (0);
      }
      if (str.length() == 1 && str[0] == '0') {
            std::cout<<str[0]<<".0f"<<std::endl;
            return (0);
      }
      if (str.length() && flag2 > 1) {
            std::cout<<"not number"<<std::endl;
            return (false);
      }
      if (float float_value = static_cast<int>(value)) {
            if (flag1 += 1) {
                  std::cout<<value<<"0f"<<std::endl;
                  return (true);
            }
            std::cout<<value<<".0f"<<std::endl;
            return (true);
      }
      else {
            std::cout<<std::fixed;
            size_t decimal_pos = str.find('.');
            if (decimal_pos != std::string::npos) {
                  int   precision = str.length() - decimal_pos - 1;
                  std::cout<<std::setprecision(precision)<<value<<"f"<<std::endl;
            }
            if (flag2 == 1) {
                  std::cout<<"f"<<std::endl;
                  return (true);
            }
      }
      std::cout<<"check index"<<std::endl;
      return (true);
}
bool  casting_double(std::string& str, int flag)
{
      std::cout<<"double :";
      if (flag == 2) {
            if (str == "nan" || str == "nanf") {
            std::cout<<"nan"<<std::endl;
            return (true);
      }
      else if (str == "inf") {
            std::cout<<"inf"<<std::endl;
            return (true);
      }
      else if (str == "+inf" || str == "+inff") {
            std::cout<<"+inf"<<std::endl;
            return (true);
      }
      else if (str == "-inf" || str == "-inff") {
            std::cout<<"-inf"<<std::endl;
            return (true);
      }
      }
      std::string temp = str;
      if (temp.length() > 0 && temp[temp.length() - 1] == 'f') {
            temp = temp.substr(0, temp.length() - 1);
      }
      char *endptr;
      double value = (std::strtod(temp.c_str(), &endptr));
      if (value < -std::numeric_limits<double>::max() || 
      value > std::numeric_limits<double>::max())
      {
            std::cout<<"over Flow!!"<<std::endl;
            return (false);
      }
      if (temp.length() == 3 && str[0] == '\'' && str[2] == '\'') {
            double c = str[1];
            std::cout<<c<<".0"<<std::endl;
            return (true);
      }
      if ((endptr == temp.c_str() || *endptr != '\0') && flag != 0) {
            std::cout<<"not number"<<std::endl;
            return (false);
      }
      if (double double_value = static_cast<int>(value)) {
            std::cout<<value<<".0"<<std::endl;
            return (true);
      }
      if (str.length() == 1 && str[0] == '0') {
            std::cout<<str[0]<<".0"<<std::endl;
            return (true);
      }
      else {
            std::cout<<std::fixed;
            size_t decimal_pos = temp.find('.');
            if (decimal_pos != std::string::npos) {
                  int   precision = temp.length() - decimal_pos - 1;
                  std::cout<<std::setprecision(precision);
                  std::cout<<value<<std::endl;
                  return (true);
            }
      }
      std::cout<<"check index"<<std::endl;
      return (true);
}