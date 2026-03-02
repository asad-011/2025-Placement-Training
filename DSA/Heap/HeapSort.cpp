#include<iostream>
using namespace std;

void heapify(int arr[], int index, int n){
    int largest=index;
    int left=2*index+1;
    int right=left+1;

    if(left<n && arr[left]>arr[largest]) largest=left;
    if(right<n && arr[right]>arr[largest]) largest=right;

    if(largest!=index){
        swap(arr[largest],arr[index]);
        heapify(arr,largest,n);
    }
}
void BuildMaxHeap(int arr[], int n){
    for(int i=(n-1)/2 ; i>=0 ; i--){
        heapify(arr,i,n);
    }
}
void heapSort(int arr[],int n){
    // int loop=n;
    // for(int i=0; i<loop; i++){
    //     swap(arr[0],arr[n-1]);
    //     n--;
    //     heapify(arr,0,n);
    // }
    for(int i=n-1; i>0; i--){
        swap(arr[0],arr[i]);
        heapify(arr,0,i);
    }
}

int main(){
    int arr[]={10,3,8,9,5,13,18,14,11,70};
    BuildMaxHeap(arr,10);
    for(int i=0; i<10; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    heapSort(arr,10);
    for(int i=0; i<10; i++){
        cout<<arr[i]<<" ";
    }
}
