/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:00:30 by lbrusa            #+#    #+#             */
/*   Updated: 2024/08/20 17:22:08 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ARRAY_HPP
#define ARRAY_HPP

/**
 * @brief A class that represents an array.
 * 
 * @tparam T The type of the array.
 */
template <typename T>
class Array {
	public:
		Array();
		Array(unsigned int n);
		Array(const Array& copy);
		~Array();
		Array& operator=(const Array& obj);
		T& operator[](unsigned int index); 
		
		unsigned int size() const;
	private:
		T* array;
		unsigned int _size;
};



// Include the template implementation file
#include "Array.tpp"

#endif