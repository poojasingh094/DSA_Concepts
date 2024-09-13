// Takes an element and places it in its correct order
[14, 9, 15, 12, 6, 8, 13]

compare 14 with 9-> swap->
[9, 14, 15, 12, 6, 8, 13]

15 is on correct position ->no change

12 is not on correct position ->swap till it gets at right position
[9, 14, 12, 15] -> [9 12, 14, 15]

6 is not on correct position ->->swap till it gets at right position
[9, 12, 14, 6, 15] -> [9, 12, 6, 14, 15] -> [9, 6, 12, 14, 15] -> [6, 9, 12, 14, 15]
 
for 8-> not at right index-> swap till it gets at right position-> 
[6, 9, 12, 14, 8, 15] -> [6, 9, 12, 8, 14, 15], [6, 9, 8, 12, 14, 15], [6, 8, 9, 12, 14, 15] 

for 13-> swap till it gets at right position-> 
[6, 8, 9, 12, 14, 13, 15] -> [6, 8, 9, 12, 13, 14, 15] -> sorted

//code

void insertion_sort(int arr[], int n) {
for(int i=1; i<=n-1; i++){
    int j=i;
    while( j>0 && arr[j-1]> arr [j]){
        int temp = arr[j-1];
        arr[j-1] = arr[j];
        arr[j] = temp;
        j--;
    }
}
}

Worst Case && Average Case:- O(N^2);
Best Case:- O(N), when no swap happens-> already sorted
