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
// Parameterized Recursion (In parameterized recursion, you pass the accumulating result as a parameter. )
// Sum of first N numbers
void f(int i, int sum) {
    if (i < 1) {
        cout << sum;
        return;
    }
    f(i - 1, sum + i);
}
int main() {
    int n = 3;
    f(n, 0);  // Output: 6
    return 0;
}
//Recursion Tree- f(3, 0)-> f(2, 3)-> f(1, 5)->f(0, 6)->print 6
// Using Functional Recursion(The function returns a value, and the final result is built up by combining the results of recursive calls.)
int sum(int n) {
    if (n == 0) return 0;
    return n + sum(n - 1);
}
int main() {
    int n = 3;
    cout << sum(n);  // Output: 6
    return 0;
}
//Recursion Tree- 3 + f(2) -> where f(2)-> 2 + f(1) -> and f(1)-> 1+ f(0), where F(0) returns 0 
//To Find Factorial using functional recursion
int fact(int n) {
    if (n == 0) return 1;
    return n * fact(n - 1);
}

int main() {
    int n = 3;
    cout << fact(n);  // Output: 6
    return 0;
}
// Parameterized Recursion: Useful when you want to accumulate results during the recursion.
// Functional Recursion: Useful when you want to build the result through return values.