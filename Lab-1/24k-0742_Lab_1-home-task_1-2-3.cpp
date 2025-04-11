#include<iostream>
using namespace std;

void average(int AQI[4][7]){
    int sum[4]={0};
    int avg[4]={0};
    for(int i=0;i<4;i++){
        for(int j=0;j<7;j++){
            sum[i] += AQI[i][j];
        }
            avg[i] = sum[i]/7;
        cout << "\nAverage for City "<< i+1 << " is " << avg[i]  << endl;
    }

    int worstair = 0;
    for(int i=0;i<4;i++){
        if(avg[i] > avg[worstair]){
            worstair = i;
        }
    }
    cout << "\nWorst air is in City " << worstair+1 << endl;
}

void criticalDays(int AQI[4][7]){
    cout << "\nCritical Pollution Days "<< endl;
    for(int i=0;i<4;i++){
        cout << "For City " << i+1 << endl;
        for(int j=0;j<7;j++){
            if(AQI[i][j] > 150){
                cout << "Day " << j+1 << " had polution of " << AQI[i][j] << endl;
            }
        }
    }
}

void visualize(int AQI[4][7]){
    for(int i=0;i<4;i++){
        cout << "\nCity " << i+1 <<" :" ;
        for(int j=0;j<7;j++){
            int count = AQI[i][j]/50;
            cout << "\nDay " << j+1 << " :";
            for(int k=0;k<count;k++){
                cout << "* " ;
            }     
        }
        cout << endl;
    }
}

int main(){
    int AQI[4][7];

    for(int i=0;i<4;i++){
        cout << "City " << i+1 << endl;

        for(int j=0;j<7;j++){
           cout << "Enter AQI for Day " << j+1 << " :";
           cin >> AQI[i][j];
        }
    }

    average(AQI);
    criticalDays(AQI);
    visualize(AQI);
} 
