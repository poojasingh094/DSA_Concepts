/*
Recursion- When a function calls itself until a specified condition is met.
Infinite recursion can lead to a segmentation fault or stack overflow. 
The condition that stops infinite function calls is called the base condition.
*/


#include <iostream>
using namespace std;

void print()
{
    cout << 1 << endl; // stack overflow, function call keeps waiting due to no specified/base condition
    print();
}

int main()
{
    print();
    return 0;
}

// When there is a base condition : all function calls completed, so no more stack overflow
int count = 0;
void print()
{
    if (count == 3)
    return;
    cout << count << endl;
    count++;
    print();
}
int main()
{
    print();
    return 0;
}

// Examples using recursion:-
// Print name N times
void print(i, N)
{
    if (i > N)
        return;
    cout << "Pooja" << endl;
    print(i + 1, N);
}
int main()
{
    print(1, N);
    return 0;
} // Time complexity: O(N), space complexity: O(N)(stack space used for function calls until the base case is reached)

// Print N-> 1 in reverse order
void print(i, N)
{
    if (i < 1)
        return;
    cout << i << endl;
    print(i - 1, N);
}
int main()
{
    print(N, N);
    return 0;
}

// Print linearly 1 to N but by backtracking
void print(i, N)
{
    if (i < 1)
        return;
    print(i - 1, N);
    cout << i << endl;
}
int main()
{
    print(N, N);
    return 0;
}

// similarly to print N to 1 by backtracking
void print(i, N)
{
    if (i > N)
        return;
    print(i + 1, N);
    cout << i << endl;
}
int main()
{
    print(1, N);
    return 0;
}