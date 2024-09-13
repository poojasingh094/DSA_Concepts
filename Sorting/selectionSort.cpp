// Get The Minimum and Swap it

arr[] = {13, 46, 24, 52, 20, 9}

Min = 9, swap with 13 and rest remains at same place
Step 1. arr[] = {9, 46, 24, 52, 20, 13}

index 0 is sorted , choose min from remaining unsorted array
Min = 13, swap with 46, rest remains at same place
Step 2. arr[]= {9, 13, 24, 52, 20, 46}

till index 1, arr is sorted, now again choose min from unsorted arr and swap
Step 3. arr[]  = {9, 13, 20, 52, 24, 46}

till index 2, arr is sorted, now select min from remaining unsorted array and swap 
Step 4. arr[] = {9, 13, 20, 24, 52, 46}

till index 3, arr is sorted,choose min from 52, and 46 and swap
Step 5. arr[] = {9, 13 20, 24, 46, 52}

last element is alrady sorted, so the entire array is sorted now.

//Code
void selection_sort(int arr[], int n){
    for(int i = 0; i<=n-2; i++) {
        int mini = i;
        for(int j=0; j<=n-1; j++) {
            if(arr[j] < arr[mini]) {
                mini = j;
            }
        }
        int temp = arr[mini];
        arr[mini] = arr[i];
        arr[i] = temp;
        //swap(arr[mini], arr[i]);
    }
}
int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i =0; i<n; i++) cin >> arr[i];
    selection_sort(arr, n);
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}

Time Complexity:- O(n^2) in all case



