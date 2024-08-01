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
v.clear();           // erase entire vector
cout << v.empty();   // returns false

/* list
- Allows fast insertion and deletion at both the front and back of the list.
- Provides operations such as push_front, push_back, pop_front, pop_back, etc.
- Internal operations use a doubly linked list structure,
*/

list<int> ls;
ls.push_back(2);
ls.push_front(5); // Inserting at the beginning (or any position other than the end) using insert can be slower because it involves shifting all subsequent elements to make space for the new element.
ls.pop_front();
// rest fns are same as vector: begin, end, clear, size, insert, swap, etc.

// Deque

deque<int> dq;
dq.push_back(1);
dq.push_front(2);
dq.pop_back();
dq.pop_front();
// rest fns are same as vector and list

// stack(LIFO)

stack<int> st;
st.push(1);
st.push(3);
cout << st.top();   // 3
st.pop();           // Remove the top element (3)
cout << st.size();  // 1
cout << st.empty(); // 0

stack<int> st1, st2;
st1.swap(st2);
// All the operations are are O(1), meaning they take constant time.

// Queue- similar to stack, but follows FIFO

queue<int> q;
q.push(1);
q.push(2);
q.back() += 5;     // {1, 7}
cout << q.front(); // 1
q.pop();           //{7}
// rest fns like size, swap, empty are same as stack

// priority-queue- data is not stored in linear, a tree is maintained inside

priority_queue<int> pq; // max-Heap(default behavior)
pq.push(5);
pq.push(2);
pq.push(8);
pq.push(10); //{10,8,5,2}
pq.top();    // 10
// size, swap, and empty functions are the same as in queue

priority_queue<int, vector<int>, greater<int>> pq; // min-Heap
pq.push(5);
pq.push(2);
pq.push(8);
pq.push(10); //{2,5,8,10}
pq.top();    // 2
