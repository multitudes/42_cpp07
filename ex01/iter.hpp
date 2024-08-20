/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 11:51:02 by lbrusa            #+#    #+#             */
/*   Updated: 2024/08/20 17:21:34 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ITER_HPP
# define ITER_HPP

/**
 * @brief Iterates over an array and applies a function to each element.
 * 
 * @tparam T The type of the array.
 * @tparam FUNC The type of the function. It is a function pointer.
 * @param arr The array to iterate over.
 * @param length The length of the array.
 * @param func The function to apply to each element.
 * @return void
 * 
 * @note The function must have the following signature:
 * void func(const T& element);
 * This will be enforced by the compiler. If the function has a different signature,
 * the compiler will throw an error.
 */
template <typename T, typename FUNC>
void iter(T* arr, int length, FUNC func) {
    for (int i = 0; i < length; ++i) {
        func(arr[i]);
    }
}

/**
 * @brief Iterates over an array and applies a function to each element.
 * 
 * Just for testing purposes.
 */
template <typename T, typename FUNC>
void iter2(T* arr, int length, FUNC func) {
    for (int i = 0; i < length; ++i) {
        arr[i] = func(arr[i]);
    }
}

/**
 * @brief Prints an element to the standard output.
 * 
 * @tparam T The type of the element.
 * @tparam FUNC The type of the function. It is a function pointer.
 * @param element The element to print.
 * @return void
 * 
 * If the element cannot be printed the error will be thrown at compile time.
 */
template <typename T>
void print(const T& element) {
	std::cout << element << " ";
}

/**
 * @brief Squares an element.
 * 
 * @tparam T The type of the element.
 * @tparam FUNC The type of the function. It is a function pointer.
 * @param element The element to square.
 * @return T The squared element.
 * 
 * This is an example of a function that doesnt match the signature of the iter function.
 * We will have a compile time error if we try
 */
template <typename T>
T square(const T& element) {
	return element * element;
}

#endif