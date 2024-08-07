//Reverse an array using recursion

//Method 1(Using two pinters)
void f(int l, int r, int arr[]) {
    if (l >= r) return;
    swap(arr[l], arr[r]);
    f(l + 1, r - 1, arr);
}
int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    f(0, n - 1, arr);
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}
//Method 2 (Single Pointer)
void f(int i, int arr[], int n) {
    if (i >= n / 2) return;
    swap(arr[i], arr[n - i - 1]);
    f(i + 1, arr, n);
}
int main() {
    int n;
    cin >> n;
    int arr[n];
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
