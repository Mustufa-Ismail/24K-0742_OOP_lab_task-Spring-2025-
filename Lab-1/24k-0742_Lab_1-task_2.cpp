#include<iostream>
#include<string>
using namespace std;

int attendenceChecker(string event1[],string event2[]){
    int flag = 0;
    string check;
    cout << "Enter the name of the participant you want to check for:";
    cin >> check;
    for(int i=0;i<5;i++){
        if(event1[i] == check){
            flag = 1;
            break;
        }
        else if(event2[i] == check){
            flag = 2;
            break;
        }
    }
    return flag;
}

int main(){
string event1[5]={"ab","cd","ef","gh","ij"};
string event2[5]={"kl","mn","op","qr","st"};

int flag=attendenceChecker(event1,event2);

if(flag == 0){
    cout << "participant not found";
}
else{
cout << "The participant is present in Event " << flag << endl;
}

return 0;
}
