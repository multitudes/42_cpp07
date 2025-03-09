/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 14:13:22 by lbrusa            #+#    #+#             */
/*   Updated: 2024/10/28 12:31:33 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"
#include <ctime>
#include <cstdlib>

#define MAX_VAL 750

int main() {
	// what does new int() do?
	int * a = new int();
	std::cout << *a << std::endl; // prints 0

	Array<const int> *emptyArray = new Array<const int>();
	try {
		std::cout << (*emptyArray)[0] << std::endl; // prints ?
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	/* testing arrays */
	Array<int> intArray(5);
	std::cout << "creating an empty array of 5 ints " << std::endl;
	for (unsigned int i = 0; i < intArray.size(); i++) {
		std::cout << intArray[i] << " ";
	}
	std::cout << "filling in the empty array of 5 ints ...  " << std::endl;
	for (unsigned int i = 0; i < intArray.size(); i++) {
		intArray[i] = (int)i;
	}
	std::cout << "check again " << std::endl;
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
	Array<int> *intArray7 = new Array<int>() ;
	std::cout << "Array<int> intArray7 size: " << intArray7->size() << std::endl;

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
	delete emptyArray;
	delete intArray7;

	 Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(static_cast<unsigned int>(time(NULL)));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//

	return 0;
};