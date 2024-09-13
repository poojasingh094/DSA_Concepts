// Push the maximum to the last by adjacent swipes

arr[] = {13, 46, 24, 52, 20, 9}
Step 1 => swap(46, 24) => {13, 24, 46, 52, 20, 9} => swap(52, 20) =>{13, 24, 46, 20, 52, 9} =>swap(52, 9)=>{13, 24, 46, 20, 9, 52}
After one complete round of adjacent swap, max 52 is at the last 

{13, 24, 46, 20, 9, 52}
Step 2 => swap(46, 20) => {13, 24, 20, 46, 9, 52}=> swap(46, 9) =>{13, 24, 20, 9, 46, 52}
After 2 step, last two are in sorted order

{13, 24, 20, 9, 46, 52}
Step 3 => swap(24, 20)=> {13, 20, 24, 9, 46, 52}=>swap(24, 9) => {13, 20, 9, 24, 46, 52}
After 3 step, last three are sorted 

{13, 20, 9, 24, 46, 52}
Step 4 => swap(20,9) =>{13, 9, 20, 24, 46, 52}
After step 4, last 4 elements are sorted 

{13, 9, 20, 24, 46, 52}
Step 5=> swap(13, 9) => {9, 13, 20, 24, 46, 52}
Now the entire array is sorted

//Implementation
1st iteration -> 0 to n-1
2nd -> 0 to n-2
3rd -> 0 to n-3
    -
    -
    - 
0 to 1
for(int i= n-1; i>=1; i--){
    for(int j=0; j<=i-1; j++){
        if(a[j]>a[j+1]) swap
    }
}
//Code
void bubble_sort(int arr[], int n) {
    for(int i= n-1; i>=1; i--){
        for(int j=0; j<=i-1; j++){
            if(arr[j] > arr[j+1]) {
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
Time Compplexity:- O(N^2) in worst and average case but O(N) in best case, when array is already sorted
After Optimization-

void bubble_sort(int arr[], int n) {
    for(int i= n-1; i>=1; i--){
    int didSwap=0;
        for(int j=0; j<=i-1; j++){
            if(arr[j] > arr[j+1]) {
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
                didSwap= 1;
            }
        }
        if(didSwap == 0) {
        break; 
        }
    }
}

