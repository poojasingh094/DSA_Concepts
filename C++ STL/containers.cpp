/*
C++ STL divided into 4 types:
Containers
Algorithm
Functions
Iterators
We will cover containers and iterators here..

*/

// Before moving to container, let's learn about pairs which is a part of utility library/header

pair<int, int> p = {1, 2};
cout << p.first << " " << p.second; // 1 2

pair<pair<int, int>, int> p = {{1, 2}, 4};
cout << p.first.second; // 2

pair<int, int> arr[] = {{1, 2}, {2, 4}, {3, 5}};
cout << arr[1].second; // 4

// vectors

vector<int> v;
v.push_back(1);

vector<pair<int, int>> v;
v.push_back({1, 2}); //{{1,2}}

vector<int> v(4, 100); // {100,100,100,100}
vector<int> v1(v);     // v1 will be copy of v

// let v={1,2,3,5,9}
vector<int>::iterator it = v.begin();
it++;
cout << *(it); // 2

cout << v[0] << " " << v.at(1); // 1 2
cout << v.back();               // 9

// Using a standard iterator
for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
{
    cout << *(it) << " ";
}
// Using `auto` with an iterator
for (auto it = v.begin(); it != v.end(); it++)
{
    cout << *(it) << " ";
}

// using for each loop
for (auto it : v)
{
    cout << it; // it will print elements
}

v.erase(v.begin() + 1);                //{1,3,5,9}
v.erase(v.begin() + 2, v.begin() + 4); //{1,3}

v.insert(v.begin(), 300);       //{300,1,3}
v.insert(v.begin() + 1, 2, 10); //{300,10,10,1,3}

cout << v.size()     // 5
v.pop_back() //{300,10,10,1}

v1.swap(v2); // will swap two vector
v.clear(); // erase entire vector
cout << v.empty(); // returns false