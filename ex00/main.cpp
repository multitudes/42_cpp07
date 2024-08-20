/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 14:13:22 by lbrusa            #+#    #+#             */
/*   Updated: 2024/08/20 11:49:20 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>
#include <cassert>


int main() {
	std::cout << "Swapping two ints ====== " << std::endl;
	int a = 5, b = 10;
	std::cout << "before the swap a: " << a << " b: " << b << std::endl;
	::swap(a, b);
	// Assert that a is now 10 and b is 5
	assert(a == 10);
	assert(b == 5);
	std::cout << "after we have a: " << a << " b: " << b << std::endl;

	std::cout << "swapping the same value ==== " << std::endl;
	std::cout << "before the swap x = 5" << std::endl;
	int x = 5;
	swap(x, x);
	// Assert that x remains unchanged	
	assert(x == 5);
	std::cout << "after the swap x = " << x << std::endl;

//this will not work because the compiler will not be able to deduce the type of the template
	// double d = 3.14;
	// int i = 5;
	// swap(d, static_cast<double>(i));
	// Assert that the values are swapped correctly


	// but this 
	std::cout << "swapping doubles ==== " << std::endl;
	std::cout << "before the swap d = 3.14 d2 = 5" << std::endl;
	double d = 3.14;
	int i = 5;
	double d2 = static_cast<double>(i);
	::swap(d, d2);
	// Assert that the values are swapped correctly
	assert(d == 5);
	assert(d2 == 3.14);
	std::cout << "after the swap d = " << d << " d2 = " << d2 << std::endl;

	std::cout << "swapping two int references ==== " << std::endl;
	int& ref1 = a;
	int& ref2 = b;
	std::cout << "before the swap ref1: " << ref1 << " ref2 : " << ref2 << std::endl;
	::swap(ref1, ref2);
	// Assert that the original variables are swapped
	assert(ref1 == 5 && ref2 == 10);
	std::cout << "after the swap ref1 = " << ref1 << " ref2 = " << ref2 << std::endl;
	std::cout << "as per subject ===============================" << std::endl;
	{
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}
}	
