/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <junkwak@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-23 07:21:59 by junkwak           #+#    #+#             */
/*   Updated: 2025-04-23 07:21:59 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

Serializer::Serializer(void)
{
}

Serializer::~Serializer()
{
}

Serializer::Serializer(const Serializer& other)
{
      *this = other;
}
Serializer& Serializer::operator=(const Serializer& other)
{
      if (this != &other)
      {
            *this = other;
      }
      return (*this);
}

uintptr_t   Serializer::serialize(Data* ptr)
{
      return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
      return (reinterpret_cast<Data*>(raw));
}