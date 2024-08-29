/* 
#include <iostream>
#include <algorithm>
#include <vector>
*/

// a[4] = {1,2,5,3};
sort(a, a+n);

To sort in descending order:
sort(a, a+n, greater<int>);

//in case of vector
vector<int>v= {1, 2, 3, 4, 5, 6, 7};

sort(v.begin(), v.end());
binary_search(v.begin(),v.end(),5);//output 1

int a =3;
int b= 5;
cout<< "maximum:"<<max(a,b);
cout<< "minimum:"<<min(a,b);

swap(a,b);

string s = "abcd";
reverse(s.begin(), s.end());

rotate(v.begin(), v.begin()+3, v.end()); //output 4 5 6 7 1 2 3
//------PTR-------

// In C++, you can dynamically allocate an array using the new keyword:-
int* array = new int[size];
delete[] array; // Deallocate or Frees the allocated memory once it is no longer needed, preventing memory leaks.
// Always remember to free the allocated memory using delete[] when you no longer need the array.
// Using new allocates memory on the heap, while local arrays (e.g., int arr[10];) are allocated on the stack.




