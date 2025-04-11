#include<iostream>
using namespace std;

int main(){
    string event1[5]={"ab","cd","ef","gh","ij"};
    string event2[5]={"kl","mn","op","qr","st"};

    cout << "Participants in event 1 in reverse order"<< endl;
    for(int i=4;i>=0;i--){
    cout << event1[i] << endl;
    }

    cout << "Participants in event 2 in reverse order"<< endl;
    for(int i=4;i>=0;i--){
    cout << event2[i] << endl;
    }


}