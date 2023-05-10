// OS
#include<iostream>
#include <cmath>
#include <limits>

using namespace std;

typedef std::numeric_limits< double > dbl;

int main()
{

    int jobCount, arrTime[50], surTime[50], startTime[50], finTime[50], idleTimes[50], turnTime[50];

    double avgWT = 0;
    double avgTT = 0;

    cout << "Please insert the number of job: ";
    cin >> jobCount;

    cout << "\nPlease insert the Arrival Times";
    for(int i = 0; i < jobCount; i++)
    {
        cin >> arrTime[i];
    }

    cout << "\nPlease inset the Service Times: ";
    for(int i = 0; i< jobCount; i++)
    {
        cin >> surTime[i];
    }

    // Calculating the finish time
    for(int i= 0; i < jobCount; i++)
    {
        int idleTime = 0;

        if(i >1)
        {
            idleTime = arrTime[i] - finTime[i-1];
        }
        finTime[i] = arrTime[i] + surTime[i];

        if(idleTime < 1)
        {
            finTime[i] = finTime[i] + abs(idleTime);
        }
    }

    // Wait time
    for(int i= 0; i < jobCount; i++)
    {
        if(i > 0){
             idleTimes[i] =  finTime[i-1] - arrTime[i];
        }else{
             idleTimes[i] = 1 - arrTime[i];
        }

        if(idleTimes[i] < 1){
            idleTimes[i] = 0;
        }

    }


    // Calculating tern around times:
    for(int i= 0; i < jobCount; i++)
    {
       turnTime[i] =  finTime[i] -  arrTime[i];
    }

    // calculating avgWT

    cout << "Arrival time\t" << "Survice time\t" << "Finish time\t" << "Wating time\t" << "Turn around time\n";
    for(int i= 0; i < jobCount; i++)
    {
        cout << arrTime[i] << "\t\t\t" << surTime[i] << "\t\t\t" << finTime[i] << "\t\t\t" << idleTimes[i] << "\t\t\t" << turnTime[i] << "\n";
    } 

    int total =0;
    for(int i= 0; i < jobCount; i++){
       total = total +idleTimes[i];

    }
    cout.precision(3);
    avgWT = total / jobCount;

    cout << "\n Avg wait time = "  << avgWT;

     // calculating avgTT
    total =0;
    for(int i= 0; i < jobCount; i++){
       total = total + turnTime[i];

    }
    avgTT = total / jobCount;
    cout.precision(3);
    cout << "\n Avg tern around time = " << avgTT;

}
