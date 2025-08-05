#include <iostream>
#include <thread>
using namespace std;

int shared_data = 0;

// Function A tries to add 10
void processA() {
    for(int i = 0; i < 100000; ++i) {
        shared_data += 10;  // Not atomic
    }
}

// Function B tries to subtract 5
void processB() {
    for(int i = 0; i < 100000; ++i) {
        shared_data -= 5;  // Not atomic
    }
}

int main() {
    thread t1(processA);
    thread t2(processB);

    t1.join();
    t2.join();

    cout << "Final value of shared_data: " << shared_data << endl;

    return 0;
}
