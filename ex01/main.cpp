/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 14:13:22 by lbrusa            #+#    #+#             */
/*   Updated: 2024/08/20 14:11:13 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"


int main() {
    int intArray[] = {1, 2, 3, 4, 5};



    // Calls the first version of iter
    iter<int, void(*)(const int&)>(intArray, sizeof(intArray) / sizeof(intArray[0]), print);
    std::cout << std::endl;
	iter<int, int(*)(const int&)>(intArray, sizeof(intArray) / sizeof(intArray[0]), square);
	std::cout << std::endl;
	// Calls the second version of iter
	iter<int, void(*)(const int&)>(intArray, sizeof(intArray) / sizeof(intArray[0]), print);
	std::cout << std::endl;
	
	iter2<int, int(*)(const int&)>(intArray, sizeof(intArray) / sizeof(intArray[0]), square);
	std::cout << std::endl;
	// Calls the second version of iter
	iter<int, void(*)(const int&)>(intArray, sizeof(intArray) / sizeof(intArray[0]), print);
    return 0;
}