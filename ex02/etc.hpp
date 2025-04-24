/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   etc.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <junkwak@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-24 07:55:28 by junkwak           #+#    #+#             */
/*   Updated: 2025-04-24 07:55:28 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef     ETC_HPP
# define    ETC_HPP

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>


Base *generate(void);
void  identify(Base* p);
void  idenitfy(Base& p);

#endif