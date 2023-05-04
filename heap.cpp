#include <iostream>
using namespace std;

// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   // build heapify
   int leftChild = 2 * root + 1;
   int rightChild = 2 * root + 2;
   int maximum = INT_MIN;
   if (leftChild < n && arr[leftChild] > arr[root]){
        maximum = leftChild;
   }
   else{
        maximum = root;
   }
   if (rightChild < n && arr[rightChild] > arr[maximum]){
        maximum = rightChild;
   }
   if (maximum != root){
        int temp = arr[root];
        arr[root] = arr[maximum];
        arr[maximum] = temp;
        heapify(arr,n,maximum);
   }


}

// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
   for(int i = n/2; i >= 0; i--){
    heapify(arr,n,i);
   }

   // extracting elements from heap one by one
   for(int j = n-1; j >= 1; j--){
    int maximum = arr[0];
    arr[0] = arr[j];
    arr[j] = maximum;
    heapify(arr,j,0);
   }
}

/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}

// main program
int main()
{
   int heap_arr[] = {99,67,48,78,32,21,79};
   int n = sizeof(heap_arr)/sizeof(heap_arr[0]);
   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);

   heapSort(heap_arr, n);

   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}
