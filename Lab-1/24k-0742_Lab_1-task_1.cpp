#include<iostream>
using namespace std;

int main(){
    string event1[5],event2[5];
    int count1=0,count2=0,option,num;
    char choice;
    
    do{
    cout << "Do you want to register for the event (y/n):";
    cin >> choice;

    if(choice == 'y'){
    cout << "Which event want to register for:";
    cin >> option;

    if(option == 1){
        cout << "How many participants want to register:";
        cin >> num;

        for(int i=0;i<num;i++){
            if(count1 >= 5){
                cout << "Maximum number of participants have registered\n";
                break;
            }
            cout << "Enter the name of the participant:";
            cin >> event1[count1];
            count1++;
        }
        }

    if(option == 2){
        cout << "How many participants want to register:";
        cin >> num;

        for(int i=0;i<num;i++){
            if(count2 >= 5){
                cout << "Maximum number of participants have registered:\n";
                break;
            }
            cout << "Enter the name of the participant:";
            cin >> event2[count2];
            count2++;
            }
    }
    }

    else{
        break;
    }
    }while(1);

    return 0;
}