#include<iostream>
using namespace std;

void weeklyAverage(int AQI[4][28]){
    int weekAvg[4][4]={0};
    for(int i=0;i<4;i++){
        cout << "For City "<< i+1 << endl;
        for(int j=0;j<4;j++){
            for(int k=0;k<7;k++){
                weekAvg[i][j] += AQI[i][(j*7)+k];
            }
            weekAvg[i][j]/=7;
            cout << "Week "<<j+1 << " Average is:"<<weekAvg[i][j] << endl;
        }
    }

    cout << "Following Cities had worst AQI average each week:\n";

    for(int i=0;i<4;i++){
        int worstAir=0;
        for(int j=0;j<4;j++){
            if(weekAvg[j][i] < weekAvg[worstAir][i]){
                worstAir = j;
            }
        }
        cout << "Week "<<i+1 << ": City " << worstAir+1 << endl;
    }

    int improvement = 0;
    int highestDrop = 0;
    int bestCity = 0;
    for(int i=0;i<4;i++){
        improvement = weekAvg[i][3]-weekAvg[i][0];

        if(improvement > highestDrop){
            highestDrop = improvement;
            bestCity = i; 
            }
    }

    cout << "City "<< bestCity+1 << " improved the most\n";
}

void criticalDays(int AQI[4][28]){
    cout << "\nCritical Pollution Days "<< endl;
    for(int i=0;i<4;i++){
        cout << "\nFor City " << i+1 << endl;
        for(int j=0;j<28;j++){
            if(AQI[i][j] > 150){
                cout << "Day " << j+1 << " had polution of " << AQI[i][j] << endl;
            }
        }
    }
}

void visualize(int AQI[4][28]){
    for(int i=0;i<4;i++){
        cout << "\nCity " << i+1 <<" :";
        for(int j=0;j<28;j++){
            int count = AQI[i][j]/50;
            cout << "\nDay " << j+1 << " :";
            for(int k=0;k<count;k++){
                cout << "* " ;
            }     
        }
        cout << endl;
    }
}

void MonthlyAverage(int AQI[4][28]){
    int monthlyAvg[4]={0};
    for(int i=0;i<4;i++){
        for(int j=0;j<28;j++){
            monthlyAvg[i] += AQI[i][j];
        }
        monthlyAvg[i] /= 28;
        cout << "\nMonthly average of City "<< i+1 <<" is:" << monthlyAvg[i];
    }
}

int main(){
    int AQI[4][28];


    for(int i=0;i<4;i++){
        cout << "City " << i+1 << endl;

        for(int j=0;j<28;j++){
           cout << "Enter AQI for Day " << j+1 << " :";
           cin >> AQI[i][j];
        }
    }

    weeklyAverage(AQI);
    MonthlyAverage(AQI);
    criticalDays(AQI);
    visualize(AQI);
} 







/*={
    {50, 55, 60, 58, 62, 65, 70, 75, 80, 85, 90, 95, 100, 105, 110, 115, 120, 125, 130, 135, 140, 145, 150, 155, 160, 165, 170, 175},
    {40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90, 95, 100, 105, 110, 115, 120, 125, 130, 135, 140, 145, 150, 155, 160, 165, 170, 175},
    {30, 35, 40, 45, 50, 55, 60, 65, 700, 75, 80, 85, 90, 95, 100, 105, 110, 115, 120, 125, 130, 135, 140, 145, 150, 155, 160, 165},
    {20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90, 95, 100, 105, 110, 115, 120, 125, 130, 135, 140, 145, 150, 155}
}*/