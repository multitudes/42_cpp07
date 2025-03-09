/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 14:13:22 by lbrusa            #+#    #+#             */
/*   Updated: 2024/10/28 12:34:33 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"


int main() {
    int intArray[] = {1, 2, 3, 4, 5};

    // Calls the first version of iter
    ::iter<int, void(*)(const int&)>(intArray, sizeof(intArray) / sizeof(intArray[0]), ::print_func);
    std::cout << std::endl;

	// for testing - this will not do anything because the return value from square is not used
	::iter<int, int(*)(const int&)>(intArray, sizeof(intArray) / sizeof(intArray[0]), ::square);
	
	// Test with a vector of strings
	std::string str_array[3] = {"hello", "world", "C++"};
	::iter<std::string, void(*)(const std::string&)>(str_array, 3, ::print_func);
	std::cout << std::endl;

	// Test with an array of doubles
	double double_array[] = {1.1, 2.2, 3.3};
	::iter<double, void(*)(const double&)>(double_array, sizeof(double_array) / sizeof(double_array[0]), ::print_func);
	std::cout << std::endl;


	
    return 0;
}