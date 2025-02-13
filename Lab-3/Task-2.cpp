#include <iostream>
using namespace std;

class fitnessTracker
{
private:
    string userName;
    int dailyStepGoal;
    int stepsTaken;
    float caloriesBurned;

public:
    fitnessTracker(string name, int stepGoal)
    {
        userName = name;
        dailyStepGoal = stepGoal;
        stepsTaken = 0;
        caloriesBurned = 0.0;
    }

    void logSteps(int steps)
    {
        stepsTaken += steps;
        caloriesCalulator();
    }

    void caloriesCalulator()
    {
        caloriesBurned = stepsTaken * 0.04;
    }

    bool isGoalMet()
    {
        return (dailyStepGoal <= stepsTaken);
    }

    void displayProgress()
    {
        cout << "Steps Taken:" << stepsTaken << endl;
        cout << "Calories Burned:" << caloriesBurned << endl;
        if (isGoalMet())
        {
            cout << "Daily Step goal has been achieved" << endl;
        }
        else
        {
            cout << "Daily step goal has not been achieved" << endl;
            cout << "Steps remaining:" << dailyStepGoal - stepsTaken << endl;
        }
    }
};

int main()
{
    fitnessTracker tracker("Laiba", 15000);
    tracker.logSteps(10000);
    tracker.displayProgress();
}