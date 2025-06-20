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



            //push method implementation : To insert elemnt into the maxHeap

            void push(int value){
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

                    cout << "Inserted :" << value<<endl;
                }
            }



        // To pop an element from the heap
        void Heapify(int index){
            int largest = index;
            int left = 2*index +1;
            int right = 2*index +2;

            // Now largest will hold, maximum among all three
            
            if(left<size && heapArr[left]> heapArr[largest])
                largest = left;
            
            if(right <size && heapArr[right]> heapArr[largest])
                largest = right;
            
            // if largest got update then continue for next else Heapify done
            if(largest !=index){
                // Swap the element
                swap(heapArr[index], heapArr[largest]);
                Heapify(index);
            } 

        } 
        void pop(){
            if(size==0)
                cout<<"Heap Underflow !!";

            // Put last elemnt to 0th index and reduce size, after that perform heapify
            cout<<"Deleted : "<<heapArr[0]<<endl;
            heapArr[0]= heapArr[size-1];
            size--;
           
            Heapify(0);
            
        }


            // To print element of the heap
            void printMaxHeap(){
                for(int i=0 ; i<size ; i++){
                    cout<<heapArr[i]<<" ";
                }
                cout<<endl;
            }

            // To return maximum element (top of the heap element)

            int top(){
                if(size==0){
                    cout<<"Underflow : Heap is empty.";
                    
                }
               
                return heapArr[0];
            }

    };

    int main(){

        // creating an object of MaxHeap
        MaxHeap h(6);

        h.push(10);
        h.push(13);
        h.push(12);
        h.push(23);
        h.push(1);
        h.push(123);
        // To print the element of maxHeap
        h.printMaxHeap();
        cout<< "Maximum elemnt is :"<<h.top()<<endl;
        h.pop();

        h.printMaxHeap();
    }