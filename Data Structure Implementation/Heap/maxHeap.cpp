#include<iostream>

using namespace std;

// MaxHeap clas

    class MaxHeap{

        int *heapArr;
        int size ; //Number of elements currently in heap
        int capacity ; //Number of elements heap can store

        public : 

            // Heap initialization or Constructor

            MaxHeap(int n){
                heapArr = new int[n]; //create array of size n (memory allocated)
                size =0; //Initially no elements in the heap
                capacity = n; // at most heap can store n elements
            }



            // Insert element into the heap

            void insert(int value){
                if(size == capacity)
                    cout << "Heap is overflow, No elements can be inserted" << endl;
                else {
                    heapArr[size] = value;
                    int index = size;
                    size++;

                    int parent = (index - 1) / 2;

                    while (parent >= 0 && heapArr[parent] < heapArr[index]) {
                        swap(heapArr[parent], heapArr[index]);
                        index = parent;
                        parent = (index - 1) / 2;
                    }

                    cout << "Element " << value<< " is inserted into the heap" << endl;
                }
            }


            // To print element of the heap
            void printMaxHeap(){
                for(int i=0 ; i<size ; i++){
                    cout<<heapArr[i]<<" ";
                }
            }

    };

    int main(){

        // creating an object of MaxHeap
        MaxHeap h(6);

        h.insert(10);
        h.insert(13);
        h.insert(12);
        h.insert(23);
        h.insert(1);
        // To print the element of maxHeap
        h.printMaxHeap();
    }