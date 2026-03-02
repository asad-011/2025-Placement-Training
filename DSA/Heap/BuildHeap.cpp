#include<iostream>
using namespace std;

void heapify(int arr[],int index,int n){
    int largest=index;
    int left=2*index+1;
    int right=2*index+2;

    if(left<n && arr[largest]<arr[left]) largest=left;
    if(right<n && arr[largest]<arr[right]) largest=right;
    

    if(largest!=index){
        swap(arr[largest],arr[index]);
        heapify(arr,largest,n);
    }
}
void BuildMaxHeap(int arr[],int n){
    for(int i=n/2-1 ; i>=0 ; i--){
        heapify(arr,i,n);
    }
}
void printHeap(int arr[],int n){
    for(int i=0 ;i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void heapify_min(int arr[], int index, int n){
    int smallest=index;
    int left=2*index+1;
    int right=2*index+2;

    if(left<n && arr[smallest]>arr[left]) smallest=left;
    if(right<n && arr[smallest]>arr[right]) smallest=right;

    if(smallest!=index){
        swap(arr[smallest],arr[index]);
        heapify_min(arr,smallest,n);
    }
}
void BuildMinHeap(int arr[], int n){
    for(int i=n/2-1; i>=0; i--){
        heapify_min(arr,i,n);
    }
}
int main(){
    int arr[]={10,3,8,9,5,13,18,14,11,70};
    // BuildMaxHeap(arr,10);
    // printHeap(arr,10);

    BuildMinHeap(arr,10);
    printHeap(arr,10);
}
