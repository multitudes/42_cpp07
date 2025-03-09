/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:00:30 by lbrusa            #+#    #+#             */
/*   Updated: 2024/10/28 12:21:16 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

/**
 * @brief A class that represents an array.
 * 
 * @tparam T The type of the array.
 */
template <typename T>
class Array {
	public:
		// the canonical form
		Array();
		Array(unsigned int n);
		Array(const Array& copy);
		~Array();
		Array& operator=(const Array& obj);

		// subscript operator
		T& operator[](unsigned int index);
		const T& operator[](unsigned int index) const; 
		// ok the subject is tricking me into handling int as index too 
		// so I will handle this as well
		T& operator[](int index);
		const T& operator[](int index) const;
		
		unsigned int size() const;
		
	private:
		T* array;
		unsigned int _size;
};



// Include the template implementation file
#include "Array.tpp"

#endif