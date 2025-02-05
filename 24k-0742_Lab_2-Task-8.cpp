#include <iostream>
using namespace std;

int* allocateMemory(int n){
    int *ptr = new int[n];
    return ptr;
}

void userInput(int *ptr,int n){
    for(int i=0;i<n;i++){
        cout << "Enter an integer:";
        cin >> ptr[i];
    }
}

void display(int *ptr,int n){
    for(int i=0;i<n;i++){
        cout << ptr[i] << endl;
    }
}

void deallocateMemory(int *ptr){
    delete[] ptr;
    cout << "Memory has been freed";
}

int main(){
    int n;
    cout << "Enter the size of the array:";
    cin >> n;

   int *ptr = allocateMemory(n);
    userInput(ptr,n);
    display(ptr,n);
    deallocateMemory(ptr);

    return 0;
}