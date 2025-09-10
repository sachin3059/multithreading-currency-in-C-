/*
    Basics of Concurrency
    Difference between illusion of Concurrency and Hardware Concurrency
    Basics of Process and Threads
    Concurrency using Processes
    Concurrency using Threads
*/



#include<bits/stdc++.h>
#include<thread>
using namespace std;

void printNumbers(){
    for(int i = 1; i <= 5; i++){
        cout << "Number: " << i << " " << "from thread Id: " << this_thread::get_id() << endl;
    }
}

void helloWorld(){
    cout << "Hello World!" << " " << this_thread::get_id() << endl;
}

int main(){

    cout << "main thread: " <<  this_thread::get_id() << endl;  // main thread
    thread t(helloWorld);  // this line create a new thread of execution.
    thread t1(printNumbers);        // create thread for printNumbers function


    t.join();  //  makes the main thread wait until the worker thread t finishes.
    t1.join();



    // now i have three active threads:
    // 1. main thread
    // 2. hello world thread
    // 3. printNumbers thread


    // the os schedule them to run in parallel
    // .join() ensures the main thread waits until t and t1 finish

    return 0;
}

