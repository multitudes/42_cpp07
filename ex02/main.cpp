/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 14:13:22 by lbrusa            #+#    #+#             */
/*   Updated: 2024/08/20 17:22:18 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"


int main() {
	// what does new int() do?
	int * a = new int();
	std::cout << *a << std::endl; // prints 0

	/* testing arrays */
	Array<int> intArray(5);
	for (unsigned int i = 0; i < intArray.size(); i++) {
		intArray[i] = (int)i;
	}
	for (unsigned int i = 0; i < intArray.size(); i++) {
		std::cout << intArray[i] << " ";
	}
	std::cout << std::endl;
	
	// copy constructor
	Array<int> intArray2(intArray);
	std::cout << "copy constr Array<int> intArray2(intArray);"  << std::endl;
	for (unsigned int i = 0; i < intArray2.size(); i++) {
		std::cout << intArray2[i] << " ";
	}
	std::cout << std::endl;	

	// assignment operator
	Array<int> intArray3;
	intArray3 = intArray;
	std::cout << "assignment operator Array<int> intArray3 = intArray;"  << std::endl;
	for (unsigned int i = 0; i < intArray3.size(); i++) {
		std::cout << intArray3[i] << " ";
	}
	std::cout << std::endl;

	// print sizes
	Array<int> intArray4(10);
	std::cout << "Array<int> intArray4(10) size: " << intArray4.size() << std::endl;
	Array<int> intArray5(20);
	std::cout << "Array<int> intArray5(20) size: " << intArray5.size() << std::endl;
	Array<int> intArray6;
	std::cout << "Array<int> intArray6() size: " << intArray6.size() << std::endl;
	Array<int> intArray7;
	std::cout << "Array<int> intArray7 size: " << intArray7.size() << std::endl;

	// indexing
	std::cout << "intArray[0]: " << intArray[0] << std::endl;
	std::cout << "intArray[1]: " << intArray[1] << std::endl;
	std::cout << "intArray[2]: " << intArray[2] << std::endl;
	std::cout << "intArray[3]: " << intArray[3] << std::endl;
	std::cout << "intArray[4]: " << intArray[4] << std::endl;
	try {
		std::cout << "intArray[5]: " << intArray[5] << std::endl;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	intArray[0] = 42;
	std::cout << "intArray[0]: " << intArray[0] << std::endl;
	delete a;

	return 0;
};