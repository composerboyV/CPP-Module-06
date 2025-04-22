/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <junkwak@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-22 01:48:07 by junkwak           #+#    #+#             */
/*   Updated: 2025-04-22 01:48:07 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int     main(int argc, char **argv)
{
	if (argc != 2) {
	std::cout<<"Check argc"<<std::endl;
		return (0);
	}
	ScalarConverter::convert(argv[1]);
	return (0);
}