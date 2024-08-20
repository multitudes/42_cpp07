/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 18:06:54 by lbrusa            #+#    #+#             */
/*   Updated: 2024/08/20 17:21:12 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WHATEVER_HPP
#define WHATEVER_HPP

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