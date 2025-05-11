#include <iostream>
#include <thread>

using namespace std;


int lock = 0;  // Simulated lock: 0 = unlocked, 1 = locked

class thread_object {
public:
    void operator()(int& x) {
        for (int i = 0; i < 100000; ++i) {
            while (lock != 0); // Wait until lock becomes 0 (busy waiting)
            lock = 1;

            // Start of critical section
            //Here lock is required because x is shared variable
            x += 1;

            //End of critical section
            lock = 0;
        }
    }
};

int main() {
    int x = 0;
    thread_object obj;
    thread t1(obj, ref(x));  // Launch thread t1
    thread t2(obj, ref(x));  // Launch thread t2

    t1.join(); // Wait for t1 to finish
    t2.join(); // Wait for t2 to finish

    cout << "Final value of x: " << x << endl;
    return 0;
}
