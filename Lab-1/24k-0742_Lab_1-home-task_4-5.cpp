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

    cout << "\nFollowing Cities had worst AQI average each week:\n";

    for(int i=0;i<4;i++){
        int worstAir=0;
        for(int j=0;j<4;j++){
            if(weekAvg[j][i] > weekAvg[worstAir][i]){
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

    cout << "\nCity "<< bestCity+1 << " improved the most\n";
}

void criticalDays(int AQI[4][28]){
    cout << "\n\nCritical Pollution Days "<< endl;
    for(int i=0;i<4;i++){
        cout << "\nFor City " << i+1 << endl;
        for(int j=0;j<28;j++){
            if(AQI[i][j] > 150){
                cout << "Day " << j+1 << " had polution of " << AQI[i][j] << endl;
            }
        }
    }
}

void MonthlyAverage(int AQI[4][28]){
    int monthlyAvg[4]={0};
    for(int i=0;i<4;i++){
        int highest=AQI[i][0];
        int lowest=AQI[i][0];
        for(int j=0;j<28;j++){
            monthlyAvg[i] += AQI[i][j];

            if (AQI[i][j] > highest){
                highest = AQI[i][j];
                }

            if (AQI[i][j] < lowest){
                lowest = AQI[i][j];
                }
            }
        
        monthlyAvg[i] /= 28;
        cout << "\nMonthly average of City "<< i+1 <<" is:" << monthlyAvg[i];
        cout << "\nHighest recorded AQI is "<< highest;
        cout << "\nLowest recorded AQI is "<< lowest << endl;
        }
        cout << endl;
}


int main(){
    int AQI[4][28] = {
    {140, 125, 210, 85, 135, 145, 120, 105, 225, 195, 130, 100, 250, 220, 140, 170, 160, 95, 190, 120, 135, 200, 110, 230, 145, 195, 250, 130},
    {140, 95, 155, 120, 135, 225, 90, 145, 175, 240, 190, 130, 110, 125, 135, 195, 185, 250, 135, 105, 175, 225, 120, 170, 210, 250, 195, 150},
    {110, 100, 250, 195, 125, 175, 140, 140, 130, 225, 95, 145, 180, 160, 250, 135, 145, 90, 210, 100, 180, 195, 125, 240, 175, 135, 160, 250},
    {120, 135, 145, 250, 140, 110, 200, 125, 180, 195, 225, 105, 155, 240, 130, 185, 95, 250, 200, 135, 90, 160, 110, 195, 210, 225, 140, 150}
};

    weeklyAverage(AQI);
    MonthlyAverage(AQI);
    criticalDays(AQI);
} 
