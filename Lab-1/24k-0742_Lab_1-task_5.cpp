#include<iostream>
using namespace std;

int main(){
    string event1[5]={"ab","cd","ef","gh","ij"};
    string event2[5]={"kl","mn","op","",""};
     

    cout << "For event 1:" ;
    for(int i=0;i<5;i++){
        if(event1[i] != ""){
            cout << "* ";
        }
    }

    cout << "\nFor event 2:" ;
    for(int i=0;i<5;i++){
        if(event2[i] != ""){
            cout << "* ";
        }
    }
}