#include <iostream>
#include <iomanip>
#include <cstring>
#include <ctime>
#include <fstream>           // for output file
#include <cmath>
using namespace std;

struct Transaction {
    string type;
    int duration;
};

struct Customer {
    int arrivalTime;
    int serviceTime;
    int waitingTime;
    int waitingminutes;
    int waitinghours;
    int tellerAssigned;
    bool served;
    int leavingHours ;
    int leavingtime ;
    int leavingMinutes ;

};


void get_user_input(int& numTellers, int& tellerWorkingHours, int& bankOpenTime, int& bankCloseTime, int& break_start_time, int& break_end_time, int& numCustomersPerday, int& numservedCustomersPerYear, int& numTransactions,  Transaction transactions[])
{
    cout << "Enter the number of tellers : ";
    cin >> numTellers;
    cout << "Enter the working hours of the bank (open time and close time in hours past midnight) : ";
    cin >> bankOpenTime >> bankCloseTime;
     while (bankOpenTime < 0 && bankCloseTime > 24)
    {
        cout << "Enter a valid open time and close time in hours past midnight :";
        cin >> bankOpenTime >> bankCloseTime;
    }

    cout << "Enter break start time and break end time in hours : ";
    cin >> break_start_time >> break_end_time ;
     while (break_start_time< bankOpenTime  && bankCloseTime < break_end_time)
    {
        cout << "Enter a valid break start time and break end time in hours between bank open time and bank close time:";
        cin >> bankOpenTime >> bankCloseTime;
    }
    cout << "Enter the number of customers per day : ";
    cin >> numCustomersPerday;

    cout << "Enter the number of expected served customers per year (must be greater than 30,000) : ";
    cin >> numservedCustomersPerYear;
    while (numservedCustomersPerYear <= 30000)
    {
        cout << "Number of served customers per year must be greater than 30,000. Please enter a valid number :";
        cin >> numservedCustomersPerYear;
    }

    for (int i = 0; i < numTransactions; i++)
    {
        cout << "Enter transaction type " << i + 1 << " : ";
        cin >> transactions[i].type;
        cout << "Enter required duration in minutes: ";
        cin >> transactions[i].duration;
    }

    cout << endl << "Transaction types and required durations :" << endl;
    for (int i = 0; i < numTransactions; i++)
    {
        cout << transactions[i].type << " : " << transactions[i].duration << " minutes" << endl;
    }
}

void generate_customer_data(int numTellers, int bankOpenTime, int bankCloseTime,int break_start_time, int break_end_time, int numCustomersPerday,
int numTransactions,  Transaction transactions[] ,  int& numservedCustomersPerYear)
{
    const int NUM_DAYS = 1;
    const int NUM_CUSTOMERS = numCustomersPerday * NUM_DAYS;
    Customer customers[NUM_CUSTOMERS];

    int randomNumber = 0;
    int waitingTime ;
    int prevTellerAssigned = 0;
    int prevPrevTellerAssigned = 0;
    bool tellersBusy[numTellers] = {false};
    int tellerIdleTime[numTellers] = {0};
    int tellerWorkingTime[numTellers] = {0};
    int numServedCustomers = 0;

    for (int day = 1; day <= NUM_DAYS; day++)    // We can change it if we want to run the whole program in more than 1 day.
    {
        numServedCustomers = 0;

        for (int i = 0; i < numCustomersPerday; i++)
        {
            int arrivalTime = randomNumber + (rand() % ((bankCloseTime - bankOpenTime) * 60 / numCustomersPerday));
            int size = rand() % numTransactions;
            int serviceTime = transactions[size].duration;
            int arrivalHours = bankOpenTime + arrivalTime / 60;
            int arrivalMinutes = arrivalTime % 60;



			if (i == 0 || i < numTellers )
            {
                waitingTime = 0;
            }
        else
          {
          for (int j=i ; j>=numTellers ; j--)
          {

            if (customers[i].tellerAssigned == customers[j].tellerAssigned)
            {
                 customers[i].leavingtime = bankOpenTime + (customers[i].arrivalTime + customers[i].serviceTime + customers[i].waitingTime ) ;

             customers[i].waitingTime =customers[i].arrivalTime - customers[j].leavingtime ;


            }

          }

        }

      customers[i].waitinghours = bankOpenTime + customers[i].waitingTime / 60 ;
      customers[i].waitingminutes =customers[i].waitingTime % 60 ;
/*
            if (i == 0 || i < numTellers )
            {
                waitingTime = 0;
            }
            else
          {
                waitingTime = fabs(arrivalTime - customers[i - 1].arrivalTime - customers[i - 1].serviceTime); // customer that have the same teller // lw elrqm b-ve ==> waiting time b zero
             }
*/
            customers[i].arrivalTime = arrivalTime;
            customers[i].serviceTime = serviceTime;
            customers[i].waitingTime = waitingTime;
            customers[i].leavingHours = bankOpenTime + (customers[i].arrivalTime + customers[i].serviceTime+customers[i].waitingTime ) / 60;
            customers[i].leavingMinutes = (customers[i].arrivalTime + customers[i].serviceTime+ customers[i].waitingTime) % 60;


         if (  customers[i].leavingHours >= bankCloseTime)
                  customers[i].served = false;
             else
                customers[i].served = true;
         if( customers[i].leavingHours >=break_start_time &&  customers[i].leavingHours < break_end_time ){
                         customers[i].served = false;
         }
         if(customers[i].served == false){
            customers[i].waitingTime= 0;
            customers[i].serviceTime= 1; // one minutes to go to teller then teller reject transaction type due to not working hour
         }
            int assignedTeller;
            do
               {
                assignedTeller = rand() % numTellers + 1;
               }

            while (assignedTeller == prevTellerAssigned || assignedTeller == prevPrevTellerAssigned || tellersBusy[assignedTeller - 1]);

            tellersBusy[assignedTeller - 1] = true;

            customers[i].tellerAssigned = assignedTeller;

            tellerWorkingTime[assignedTeller - 1] += customers[i].serviceTime;
            tellersBusy[assignedTeller - 1] = false;

            prevPrevTellerAssigned = prevTellerAssigned;
            prevTellerAssigned = assignedTeller;


						cout << "Customer " << (i + 1) << " arrives at: " << setw(2) << setfill('0') << arrivalHours << ":" << setw(2) << setfill('0') << arrivalMinutes
                 << " and finishes at " << setw(2) << setfill('0') << customers[i].leavingHours << ":" << setw(2) <<customers[i].leavingMinutes<<endl
                 << "Using transaction " << transactions[size].type
                 << ", Teller " << customers[i].tellerAssigned << " assigned" << endl;

            if (customers[i].served)
            {
                numServedCustomers++;
            }

            randomNumber += ((bankCloseTime - bankOpenTime) * 60 / numCustomersPerday);
        }

        cout << " Today "  << ": " << numServedCustomers << " customers served." << endl;
        int z =  numServedCustomers*365 ;

         cout << "No. of served customers per year "  << ": " << z << " customers served." << endl;
         if ( numservedCustomersPerYear > z )
         cout << "The bank does not meet your expectations " << endl ;
         else
         cout << "The bank meets your expectations " << endl ;

    }

    ofstream outputFile("customer_data.txt");
    if (outputFile.is_open())
    {
        outputFile << "Customer ID    Arrival Time        Leaving Time        Waiting Time   Served?" << endl;
        for (int i = 0; i < NUM_CUSTOMERS; i++)
        {
            int arrivalHours = bankOpenTime + customers[i].arrivalTime / 60;
            int arrivalMinutes = customers[i].arrivalTime % 60;
            int leavingHours = bankOpenTime + (customers[i].arrivalTime + customers[i].serviceTime+customers[i].waitingTime ) / 60;
            int leavingMinutes = (customers[i].arrivalTime + customers[i].serviceTime+ customers[i].waitingTime) % 60;

            outputFile << setw(5) << i + 1 << setw(13) << arrivalHours << ":" << setw(2) << arrivalMinutes << "    "
                       << setw(15) << leavingHours << ":" << setw(2) << leavingMinutes << "    "
                       << setw(15) << customers[i].waitinghours << "    "
                       << setw(10) << customers[i].waitingminutes << "    "
                       << setw(9) << (customers[i].served ? "Yes" : "No") << endl;
        }
        outputFile.close();
        cout << "Customer data written to file: customer_data.txt" << endl;

        ofstream outputTellerFile("teller_data.txt");
        if (outputTellerFile.is_open())
        {
            outputTellerFile << "Teller ID    Idle Time        Working Time   Utility (%)" << endl;
            for (int i = 0; i < numTellers; i++)
            {// edit
                int idleTime = (bankCloseTime - bankOpenTime) * 60 - tellerWorkingTime[i] + (break_end_time -break_start_time)*60 ;
                double utility = tellerWorkingTime[i] * 100.0 / (bankCloseTime - bankOpenTime)  / 60.0 ;
                outputTellerFile << setw(5) << i + 1 << setw(13) << idleTime << "    "
                           << setw(15) << tellerWorkingTime[i] << "    "
                           << setw(9) << fixed << setprecision(2) << utility << endl;
            if (idleTime<0)
            outputTellerFile<< " This teller "<< i+1 << " has overload of " << fabs(idleTime) << " minutes " << "to complete his assigned customers "<< "Due to the completely randomized teller assignment "<<endl;
            }
            outputTellerFile.close();
            cout << "Teller data written to file: teller_data.txt" << endl;
        }
        else
        {
            cout << "Error opening file." << endl;
        }
    }
    else
    {
        cout << "Error opening file." << endl;
    }
}
int main()
{
    srand(time(0));
    int numTellers, tellerWorkingHours, bankOpenTime, bankCloseTime, numCustomersPerday, numservedCustomersPerYear, numTransactions, break_start_time, break_end_time;//break_time , wa

    cout << "How many transactions will you enter? ";
    cin >> numTransactions;
    Transaction transactions[numTransactions];
    get_user_input(numTellers, tellerWorkingHours, bankOpenTime, bankCloseTime, break_start_time, break_end_time, numCustomersPerday, numservedCustomersPerYear, numTransactions, transactions);
    generate_customer_data(numTellers, bankOpenTime, bankCloseTime, break_start_time, break_end_time,  numCustomersPerday,
    numTransactions,  transactions ,  numservedCustomersPerYear);
    return 0;
}
