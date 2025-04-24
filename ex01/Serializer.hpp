/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <junkwak@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-24 06:00:53 by junkwak           #+#    #+#             */
/*   Updated: 2025-04-24 06:00:53 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef     SERIALIZER_HPP
# define    SERIALIZER_HPP

#include <stdint.h>

struct Data;
class Serializer;

class Serializer
{
private:
      Serializer(void);
      ~Serializer();
      Serializer(const Serializer& other);
      Serializer& operator=(const Serializer& other);
public:
      static uintptr_t   serialize(Data* ptr);
      static Data*       deserialize(uintptr_t raw);
};


#endif