/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:55:29 by lbrusa            #+#    #+#             */
/*   Updated: 2024/08/20 16:37:18 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

/**
 * Default constructor
 */
template <typename T>
Array<T>::Array() : array(NULL), _size(0) {
	
}

/**
 * Constructor with size
 */
template <typename T>
Array<T>::Array(unsigned int n) : array(new T[n]() ), _size(n) {
	for (unsigned int i = 0; i < _size; i++) {
		array[i] = T();
	}
}

/**
 * Copy constructor
 */
template <typename T>
Array<T>::Array(const Array& copy) : array(new T[copy._size]), _size(copy._size) {
	for (unsigned int i = 0; i < _size; i++) {
		array[i] = copy.array[i];
	}
}

/**
 * Destructor
 */
template <typename T>
Array<T>::~Array() {
	delete[] array;
}

/**
 * Assignment operator
 */
template <typename T>
Array<T>& Array<T>::operator=(const Array& obj) {
	if (this != &obj) {
		delete[] array;
		_size = obj._size;
		array = new T[_size];
		for (unsigned int i = 0; i < _size; i++) {
			array[i] = obj.array[i];
		}
	}
	return *this;
}

/**
 * Operator[] overload
 */
template <typename T>
T& Array<T>::operator[](unsigned int index) {
	if (index >= _size) {
		throw std::out_of_range("Index out of range");
	}
	return array[index];
}

/**
 * Size getter
 */
template <typename T>
unsigned int Array<T>::size() const {
	return _size;
}



