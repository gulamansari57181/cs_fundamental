
#include<iostream>
#include<vector>
using namespace std;

// Creating a stack class
class Stack{
    vector<int> st;

    public :
        // To push an element , O(1)
        void push(int val){
            st.push_back(val);
        }

        // To top an element  . O(1)
        int top(){
            if(st.empty()){
                cout<<"No element in stack";
                return -1;
            }
            
            int ele = st[st.size()-1]; //this points to last element
            return ele;
        }

        // To implement pop method  , O(1)

        void pop(){
            if(st.empty()){
                cout<<"Underlflow";
            }

            st.pop_back();
        }

        // To implement size method
        int size(){
            return st.size();
        }

        bool empty(){
            return st.size()==0;
        }
};






int main(){

    Stack st;

    st.push(5);
    st.push(20);
    st.push(51);
    st.push(23);
    st.pop();
    cout<<"Stack size is  : "<<st.size()<<endl;

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }

    return 0;
}