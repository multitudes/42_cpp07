/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 18:06:54 by lbrusa            #+#    #+#             */
/*   Updated: 2024/10/28 12:18:44 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

/**
 * @brief Swaps the values of two variables.
 * 
 * @tparam T The type of the variables.
 * @param a The first variable.
 * @param b The second variable.
 * @return void
 */
template <typename T>
void swap(T &a, T &b) {
	T tmp = a;
	a = b;
	b = tmp;
}

/**
 * @brief Returns the minimum of two values.
 * 
 * @tparam T The type of the values.
 * @param a The first value.
 * @param b The second value.
 * @return T The minimum value.
 * 
 * The compiler will check at compile time if the operator < is defined for the type T.
 */
template <typename T>
T min(T &a, T &b) {
	return (a < b) ? a : b;
}

/**
 * @brief Swaps overload to handle two const variables.
 * 
 * in cpp11 there is a check for const variables in static_assert
 * adding the include <type_traits> and using std::is_const<T>::value
 * but here in cpp98 we will just print an error message
 * if we try to swap two const variables
 * Otherwise we will have a compile time error which is just fine for this exercise
 * but since I handle the case later in ex02 with const values
 * I will add it here as well
 */
template <typename T>
void swap(const T &a, const T &b) {
    // Do nothing or provide a compile-time error
	(void)a;
	(void)b;
    std::cerr << "Cannot swap const values." << std::endl;
}

/**
 * @brief Returns the maximum of two values.
 * 
 * @tparam T The type of the values.
 * @param a The first value.
 * @param b The second value.
 * @return T The maximum value.
 * 
 * The compiler will check at compile time if the operator < is defined for the type T.
 */
template <typename T>
T max(T &a, T &b) {
	return (a < b) ? b : a;
}

#endif