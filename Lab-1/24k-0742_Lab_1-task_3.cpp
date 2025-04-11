#include<iostream>
using namespace std;

int main(){
    string event1[5]={"ab","cd","ef","gh","ij"};
    string event2[5]={"kl","mn","op","",""};
    int total1=0,total2=0;


    for(int i=0;i<5;i++){
        if(event1[i] != ""){
            total1 += 10;
        }
        if(event2[i] != ""){
            total2 += 10;
        }
    }
    
    cout << "Total amount of donation is " << total1+total2 ;

    return 0;

}