# 42_cpp07

## Introducing generic programming features in C++.
In the 98 C++ standard, we can use templates to create generic functions and classes.  

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
After having defined the template above, what is the difference between:

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


# ex00

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