/* 
Given an array [1, 2, 1, 3, 2], we need to find how many times each element occurs. For example:

1 appears twice,
2 appears twice,
3 appears once,
4 appears 0 times.
Brute Force Approach:

A straightforward approach is to write a function that counts the occurrence of each element. 
The function could look like this:

int f(int num, int arr[], int n) {
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] == num) {
            cnt++;
        }
    }
    return cnt;
}
Time Complexity Analysis:

If we need to find the occurrence of Q numbers in an array of size N, the time complexity would be
O(Q * N). This approach may not be efficient for large values of Q and N.

For example, if Q = 10^5 and N = 10^5, the total number of operations would be O(10^10). 
Given that 10^8 operations typically take about 1 second, 10^10 operations would take around 100 seconds,
which is too long for practical purposes.

Optimized Approach using Hashing:

To improve the performance, we can use hashing. Hashing allows us to store the frequency of each element
in a hash map, reducing the time complexity significantly.

*/
Hashing -> prestoring / Fetching:- 

// We'll perform some precalculations by iterating through the given array to store the frequency of each element in the hash array.

//Number hashing
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];// Here the array size is allocated at runtime but allocated on the stack, not the heap
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Assuming the maximum possible value in the array is 12, declare a hash array of size 13 (0-12).
    int hash[13] = {0};

    // Precompute the frequency of each element in the hash array
    for(int i = 0; i < n; i++) {
        hash[arr[i]] += 1;
    }

    int q;
    cin >> q;
    while(q--) {
        int number;
        cin >> number;
        // Fetch and print the frequency of the queried number
        cout << hash[number] << endl;
    }

    return 0;
}

-----PTR------
The maximum size array you can declare is 10^6 of int typeinside main, 10^7 will show segmentation fault(not be able to allocate that much memory),
but if you declare globally, the array can go till 10^7.arr[10^7]

//character hashing

Using ASCII table -
'a' -> 97 and 'z' -> 122
'f'-> 'f'-'a' = 102-97 = 5
'a'-'a' =0, 'b'-'a'= 1, 'c'-'a'=2

Ch -'a'-> get the corresponsing index in the hash array

int main() {
    string s;
    cin >> s;

    //pre compute
    int hash[26] = {0};// we declare size to 26 bcoz we know there is only lowercase letters
    for(int i=0; i<s.size(); i++) {
        hash[s[i]-'a']++;
    }
    int q;
    cin >> q;
    while(q--) {
        char c;
        cin>> c;
        //fetch

        cout << hash[c-'a'] << endl;
    }
    return 0;
}
// This still going to run fine( if it doesn't state the exclusivity of characters)
 int hash[256] = {0};
    for(int i=0; i<s.size(); i++) {
        hash[s[i]]++;
    }
    int q;
    cin >> q;
    while(q--) {
        char c;
        cin>> c;
        //fetch

        cout << hash[c] << endl;
    }
/*
Thus in character hashing (unlike number hashing), there will never be any problem related to size of the hash array, at max there are 256 characters, for only 
lowercase letter, use ch-'a', for uppercase use ch - 'A', and if their are all charcters, use 256 and hash 

In number hashing, when we trying to hash it into the arrays, we saw that we can at max do it till 10^7, if we decare globally, That is where 
in C++, STL comes,
most of the concepts of map and unordered map also applied to hashmap(In C++, a map and a Java HashMap serve similar purposes)

Imagine if we're given an array arr = [1, 2, 3,1, 3, 2,12]

in map , numbers are the key, and the corresponding value is frequency
mpp[1] will return 0, as it doesn't exist in the map so the corresponding value will be 0
when we do mpp[1]++, (if it doesn't exist in the map), it will make value of key as 1 (befor it was 0), similarly it works for all elements

Here, We are just storing the elements that are required(1,2,3,4(total 4 elements)) while in array hashing we had to declare 13 size array if the max was 12 in order to get the 12th index.
This is why map is beneficial as it takes less memory.

*/

int main() {
    int n;
    cin>> n;
    int arr[n];
    for(int i = 0; i<n; i++) {
        cin >> arr[i];
    }
    // pre-compute
    map<int, int>mpp;
    for(int i = 0; i<n; i++){
        mpp[arr[i]]++;
    }

    int q;
    cin >> q;
    while(q--){
        int number;
        cin >> number;
        // fetch
        cout << mpp[number] << endl;
    }
    return 0;
}
/*
pre computation can be done while taking the input as well
Storing and fetching in map tak log(N) in all cases
While using unordrered map, average and best case will O(1), but takes O(N) in worst cases which is extremely rare
So first prefernce should be to use unordered map because the worst case for this is very rare, and if it does exceed then only use map,
and this worst case in unordrerd map happens due to internal collision(To understand what is collision, refere to Hashing lecture of Striver)
*/

----PTR----
In map, key can be int, double, string, char,  pair, any data structure
When it comes to unordered map, we can oly have individual data type, like pair cannot be key