# Stack_c-
The stack to be implemented uses an underlying dynamic array to store all values. The stack’s
capacity is provided as a constructor parameter or set to a default size specified (if no size is
provided). When a stack is created, there will be a dynamic array created based on this given size.
If the number of elements on a stack reaches its capacity, an exception is thrown if additional
push operation is requested.
The public interface of the stack class is specified in stack.h. Note that since the stack uses
dynamic memory, the Big-4 methods must also be implemented.
1.a default constructor that creates a stack of a specified size (with a default size of 8);
2.a copy constructor to ensure deep copy of objects;
3.a destructor to avoid memory leaks;
4.an assignment operator to ensure deep copy and avoid memory leak during assignment.
You are not allowed to use any STL containers in your implementation.
