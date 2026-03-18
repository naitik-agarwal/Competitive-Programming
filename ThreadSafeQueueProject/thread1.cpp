#include<iostream>
#include<thread>
using namespace std;

// every thread needs a job to do, in c++, a thread takes a "callable" (a function, a lambda, or a functor) and runs it
void hello(){
   cout<<"Hello"<<"\n";
}

int main(){ // when the program starts the OS gives you one thread by default : the "main thread" running int main().
   thread t(hello); // this asks OS to create a brand new, secondary thread (say thread t) which immediately starts running the hello() function, but main thread doesnt stop it keeps running and moves to next line while this thread t runs in background
   t.join(); // Synchronization : so this tells main thread to stops right here and wait until thread t is completely finished, once t is done you can procees (this prevents early termination of program by main thread)
}