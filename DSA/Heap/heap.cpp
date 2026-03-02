#include<iostream>
using namespace std;

class MaxHeap{
    int * arr;
    int size;   //actual element in heap
    int total_size;

    public:
        MaxHeap(int n){
            this->total_size = n;
            arr = new int[n];   //arr → [ memory block of n integers ]
            size = 0;
        }

        void insert(int x){
            if(size==total_size){
                cout<<"Heap is full"<<endl;
                return;
            }
            else {
                size++;
                int index= size-1;
                arr[index] = x;
                while(index>0){
                    int parent=(index-1)/2;
                    if(arr[parent]<arr[index]){
                        swap(arr[parent],arr[index]);
                        index=parent;
                    }
                    else{
                        break;
                    }
                }
                cout<<arr[index]<<" inserted in heap"<<endl;
            }
        }
        void print(){
            for(int i=0;i<size;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }

        void heapify(int index){

            int largest=index;
            int left=2*index+1;
            int right=2*index+2;

            if(left<size && arr[left]>arr[largest]){
                largest=left;
            }
            if(right<size && arr[right]>arr[largest]){
                largest=right;
            }

            if(largest!=index){
                swap(arr[index],arr[largest]);
                heapify(largest);
            }

        }

        void delete_top (){
            if(size==0){
                cout<<"UnderFlow";
                return ;
            }
            cout<<arr[0]<<" deleted from the heap \n";
            arr[0]=arr[size-1];
            size--; 
            
            if(size==0) return;

            heapify(0);


        }
};

class MinHeap{
    int size;
    int total_size;
    int *arr;

    public:
        MinHeap(int n){
            this->total_size=n;
            arr= new int [n];               //arr → [ memory block of n integers ]
            size=0;
        }

        void insert(int value){
            if(size==total_size){
                cout<<"heap overflow"<<endl;
                return;
            }
            size++;
            int index=size-1;
            arr[index]=value;
            while(index>0 && arr[(index-1)/2]>arr[index]){
                swap(arr[index],arr[(index-1)/2]);
                index=(index-1)/2;
            }
            cout<<arr[index]<<" Inserted"<<endl;
        }
        void print(){
            for(int i=0; i<size; i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
            return ;
        }

        void heapify(int index){
            int smallest=index;
            int left=(index*2)+1;
            int right=(index*2)+2;

            if(left<size && arr[index]>arr[left]){
                smallest=left;
            }
            if(right<size && arr[index]>arr[right]){
                if(arr[smallest]>arr[right]){
                    smallest=right;
                }
            }
            if(smallest!=index){
                swap(arr[index],arr[smallest]);
                heapify(smallest);
            }
        }
        void delete_top(){
            if(size==0){
                cout<<"Underflow"<<endl;
                return;
            }

            arr[0]=arr[size-1];
            size--;
            heapify(0);
        }
};

int main(){
    MinHeap h2(10);
    h2.insert(10);
    h2.insert(7);
    h2.insert(2);
    h2.insert(9);
    h2.insert(1);
    h2.print();
    h2.delete_top();
    h2.print();









    // MaxHeap h1(6);
    // h1.insert(3);
    // h1.insert(4);
    // h1.insert(10);
    // h1.insert(9);
    // h1.insert(5);
    // h1.insert(2);
    // h1.print();
    // h1.delete_top();
    // h1.print();
}
