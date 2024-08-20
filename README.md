# 42_cpp07

## Introducing generic programming features in C++.
In the 98 C++ standard, we can use templates to create generic functions and classes.  

# ex00
### Class Templates 
These allow you to define classes that can be instantiated with different data types.  
An example somewhat simplified uses std::vector as the underlying data structure for the stack.
```cpp		
template <typename T>
class Stack {
public:
    void push(const T& element) {
        data.push_back(element);
    }

    T pop() {
            T top = data.back();
            data.pop_back();
            return top;
	}
    

private:
    std::vector<T> data;
};

int main() {
    Stack<int> stack;
    stack.push(1);
    stack.push(2);
    std::cout << stack.pop() << std::endl; // Outputs: 2
    std::cout << stack.pop() << std::endl; // Outputs: 1
    return 0;
}
```
I can use my Stack class with any data type I want.  

### template functions
We can also create generic functions using templates. I can pass any data type to the max function as long as the data type supports the greater than operator and a and b are of the same type.
```cpp
template <typename T>
T max(T a, T b) {
	return a > b ? a : b;
}
```

### Templates and namespaces
After having defined the template above, what is the difference between the two calls below?:

```cpp
max(1, 2);
::max(1.0, 2.0);
```

The first call is unqualified, while the second call is qualified with the `global namespace (::)`. This distinction has significant implications when dealing with templates and Argument-Dependent Lookup (ADL).

- Unqualified Call: The compiler searches for a suitable max function in the following namespaces:
        - The namespace where the function call is made (if applicable).
        - The namespaces of the arguments' types (if applicable).
        - The global namespace. If multiple matching functions are found, the compiler applies ADL to determine the most appropriate one based on the types of arguments.

- Qualified Call:
    - The compiler searches for a suitable max function only in the global namespace.
    This explicitly specifies that the max function should be found in the global namespace, overriding any other potential matches.

Key Differences are in: 
 -Namespace Scope: Unqualified calls allow the compiler to search for functions in multiple namespaces, while qualified calls restrict the search to the global namespace.
- ADL Applicability: ADL is applied to unqualified calls, allowing the compiler to find the most appropriate function based on argument types. Qualified calls bypass ADL and directly search for the function in the global namespace.
- Template Specialization: If there are multiple template specializations for max in different namespaces, an unqualified call might lead to unexpected behavior. Using a qualified call can help avoid ambiguity in such cases.


### Template in later C++ standards
In C++11, we can use variadic templates to create generic functions and classes that can take a variable number of arguments. In C++14, we can use generic lambdas to create generic functions. In C++17, we can use fold expressions to create generic functions that can take a variable number of arguments. In C++20, we can use concepts to create generic functions and classes that can take a variable number of arguments.

# ex01
As per subject:
> Implement a function template iter that takes 3 parameters and returns nothing.  
	• The first parameter is the address of an array.  
	• The second one is the length of the array.  
	• The third one is a function that will be call on every element of the array.  
Turn in a main.cpp file that contains your tests. Provide enough code to generate a
test executable.
Your iter function template must work with any type of array. The third parameter
can be an instantiated function template.

## What is an instantiated function template?
An instantiated function template is a specific version of a function template that has been created for a particular set of template arguments. In other words, when you provide concrete types for the template parameters of a function template, the compiler generates a specialized version of the function that works with those specific types. This process is called template instantiation.

```cpp
template <typename T>
void print(const T& element) {
    std::cout << element << " ";
}

int main() {
    int intArray[] = {1, 2, 3, 4, 5};
    double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};

    // Instantiating the print template with int
    print<int>(intArray[0]);

    // Instantiating the print template with double
    print<double>(doubleArray[1]);

    return 0;
}
```
So in cpp98 I will have to specify the type of T when calling the function. In cpp11 and later, you can use lambda expressions to create anonymous functions that can be passed as arguments to other functions.

If I have different function signatures, in cpp 98 I will have to specify the signature when calling my `iter` func. EX two different signatures:

```cpp
template <typename T>
void print(const T& element) {
	std::cout << element << " ";
}


template <typename T>
T square(const T& element) {
	return element * element;
}

// and in main when callint iter with the function print:
iter<int, void(*)(const int&)>(intArray, sizeof(intArray) / sizeof(intArray[0]), print);
// and with the functtion square:
iter2<int, int(*)(const int&)>(intArray, sizeof(intArray) / sizeof(intArray[0]), square);
```
But interesting enough passing the `square` function to the iter function will work:
```cpp
iter<int, int(*)(const int&)>(intArray, sizeof(intArray) / sizeof(intArray[0]), square);
but of course nothing will happen and the return value will be ignored.
This would be the implementation of `iter` and `iter2`:

```cpp
template <typename T, typename FUNC>
void iter(T* arr, int length, FUNC func) {
    for (int i = 0; i < length; ++i) {
        func(arr[i]);
    }
}

template <typename T, typename FUNC>
void iter2(T* arr, int length, FUNC func) {
    for (int i = 0; i < length; ++i) {
        arr[i] = func(arr[i]);
    }
}
```

# ex02
As per subject:
> Develop a class template Array that contains elements of type T and that implements
the following behavior and functions:
• Construction with no parameter: Creates an empty array.
• Construction with an unsigned int n as a parameter: Creates an array of n elements
initialized by default.
Tip: Try to compile int * a = new int(); then display *a.
• Construction by copy and assignment operator. In both cases, modifying either the
original array or its copy after copying musn’t affect the other array.
• You MUST use the operator new[] to allocate memory. Preventive allocation (al-
locating memory in advance) is forbidden. Your program must never access non-
allocated memory.
• Elements can be accessed through the subscript operator: [ ].
• When accessing an element with the [ ] operator, if its index is out of bounds, an
std::exception is thrown.
• A member function size() that returns the number of elements in the array. This
member function takes no parameter and musn’t modify the current instance.

So we can create in a file `array.hpp` a class template that contains elements of type T. The implementation of the class template Array will be in a separate file `Array.tpp`. 


### Where to include the template files `.tpp`?
The `.tpp` file is usually included at the end of the header file to ensure that the template definitions are available when the header file is included in other source files.  
The `.tpp` file is not otherwise included in the source files.  

```cpp
// Stack.h
#ifndef ARRAY_H
#define ARRAY_H


{some code...}

#include "Array.tpp"
#endif
```

