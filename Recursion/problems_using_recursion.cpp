//Reverse an array using recursion

//Method 1(Using two pinters)
void f(int l, int r, vector<int>& arr) {
    if (l >= r) return;
    swap(arr[l], arr[r]);
    f(l + 1, r - 1, arr);
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);  
    for (int i = 0; i < n; i++) cin >> arr[i];
    f(0, n - 1, arr);
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}
//Method 2 (Single Pointer)
void f(int i, vector<int>& arr, int n) {
    if (i >= n / 2) return;
    swap(arr[i], arr[n - i - 1]);
    f(i + 1, arr, n);
}
int main() {
    int n;
    cin >> n;
    vector<int> arr(n);  
    for (int i = 0; i < n; i++) cin >> arr[i];
    f(0, arr, n);
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}
//check if a string is palindrome or not
bool f(int i, string &s) {
    if (i >= s.size() / 2) return true;
    if (s[i] != s[s.size() - i - 1]) return false;
    return f(i + 1, s);
}

int main() {
    string s = "madam";
    cout << (f(0, s) ? "true" : "false");
    return 0;
}
//Multiple Recursive Calls

//Fibonacci no
int f(int n) {
    if(n <= 1) return n;
    int last = f(n-1);
    int slast = f(n-2);
    return last + slast;
}
int main(){
    cout <<  f(4);
    retrun 0;
}
                     f(4)
                    /    \
                 f(3)    f(2)
                /   \     /   \
             f(2)  f(1) f(1) f(0)
            /   \
         f(1) f(0)
f(4) calls f(3) and f(2).
f(3) calls f(2) and f(1).
f(2) calls f(1) and f(0).

The number of nodes in the tree roughly doubles at each level, leading to an exponential growth pattern. Hence, The time complexity of the recursive Fibonacci function is O(2^n).

--------Recursion Of Subsequnces------
Subsequence-> it can be contiguous and non contguous sequence which follows the order(a sub array is just contiguous).
// If you're struggling to understand the concept or the recursion tree for this problem, refer to L6 "Recursion on Subsequences" in Striver's DSA playlist.

void printF(int ind, vector<int> &v), int arr[], int n){
    if(ind == n){
        for(auto it: v) {
            cout <<it << " ";
        }
        if(v.size() == 0){
            cout <<"{}";
        }
        cout << endl;
        return;
    }
    // take or pick the particular index into the subsequence
    v.push_back(arr[ind]);
    printF(ind+1, v, arr, n);
    v.pop_back();

    // not pick, or not take condition, this element is not added to your subsequence
    printF(ind+1, v, arr, n);
}
int main() {
    int arr[] = {3,1,2};
    int n = 3;
    vector<int> v;
    printF(0, v, arr, n);
}

/*
Time Complexity: O(2^n) due to the exponential number of subsequences.
Space Complexity: O(n) due to the maximum depth of the recursion stack.
The number of subsequences is equal to 2^n, where n is the number of elements in the array.

Each element of the array has two choices: to be included or not included in the subsequence. Therefore, for n elements, there are 2^n possible subsequences.
*/

------Examples based on recursion of subsequences-----(follows similar pattern)
1. Printing Subsequences whose sum is K:-

void printS(int ind, vector<int> &v, int s, int sum, int arr[], int n){
    if(ind == n){
        if(s == sum) {
            for(auto it : v) cout << it << " ";
            cout << endl;
        }
        return;
    }
    v.push_back(arr[ind]);
    s += arr[ind];
    printS(ind+1, v, s, sum, arr, n);

    s-= arr[ind];
    v.pop_pack();

    //not pick
    printS(ind+1, v, s, sum, arr, n); 
}

    int main(){

        int arr[] = {1, 2, 3};
        int n=3;
        int sum = 2;
        vector<int> v;
        printS(0, v, 0, sum,  arr, n);

        return 0;
    }

------To print one subsequence-------:

bool printS(int ind, vector<int> &v, int s, int sum, int arr[], int n){
    if(ind == n){
        //consition satisfied
        if(s == sum) {
            for(auto it : v) cout << it << " ";
            cout << endl;
            return true;
        }
       else return false;
    }
    v.push_back(arr[ind]);
    s += arr[ind];

    if(printS(ind+1, v, s, sum, arr, n) == true) {
        return true;
    }

    s-= arr[ind];
    v.pop_pack();

    //not pick
    if(printS(ind+1, v, s, sum, arr, n) == true) return true;
     return false;
}

    int main(){

        int arr[] = {1, 2, 3};
        int n=3;
        int sum = 2;
        vector<int> v;
        printS(0, v, 0, sum,  arr, n);

        return 0;
    }

------Count the subsequences with sum = k-------

int printS(int ind, int s, int sum, int arr[], int n){
    if(ind == n){
        if(s == sum) return 1;
        else return 0;
    }

    s += arr[ind];
    int l = printS(ind+1, v, s, sum, arr, n);

    s-= arr[ind];

    //not pick
    int r = printS(ind+1, v, s, sum, arr, n); 

    return l + r;
}

    int main(){

        int arr[] = {1, 2, 3};
        int n=3;
        int sum = 2;
        cout <<  printS(0, 0, sum,  arr, n);

        return 0;
    }

Time Complexity : O(2^n);
TC can be improved slightly by adding 
//strictly done if array contains positives only
if(s > sum) return 0; inside the function


/* 
PTR
Why Not Pass Arrays by Reference?
Arrays in C++: Unlike vector, arrays are already treated as pointers when passed to functions, meaning that the function receives a pointer to the first element of the array. 
Therefore, arrays do not need to be passed by reference to avoid copying; they inherently avoid this issue.
*/