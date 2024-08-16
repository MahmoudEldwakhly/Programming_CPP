#include <iostream>
#include <iomanip>
#include <cstring>
#include <ctime>
using namespace std;

void user_input ()
{
    int numTellers;
    int tellerWorkingHours;
    int bankOpenTime, bankCloseTime;
    int numCustomersPerWeek;
    int numCustomersPerday;
    int numCustomersPerYear;
    int numTransactionTypes;
    int WORKING_MINUTES_PER_DAY;
    int day;
    int i;

    cout << "Enter the number of tellers: ";
    cin >> numTellers;
    cout << "Enter the working hours for each teller (in hours): ";
    cin >> tellerWorkingHours;
    cout << "Enter the working hours of the bank (open time and close time in hours past midnight): ";
    cin >> bankOpenTime >> bankCloseTime;
    WORKING_MINUTES_PER_DAY = (bankCloseTime - bankOpenTime) * 60;
    cout << "Enter the number of customers per day: ";
    cin >> numCustomersPerday;
    cout << "Enter the number of served customers per year (must be greater than 30,000): ";
    cin >> numCustomersPerYear;
    while (numCustomersPerYear <= 30000)
    {
        cout << "Number of served customers per year must be greater than 30,000. Please enter a valid number: ";
        cin >> numCustomersPerYear;
    }

    cout << "Enter the number of transaction types you need from the following : 1- deposit , 2- Withdrawal , 3- Transfere " ;
    cin >> numTransactionTypes;

    while ( numTransactionTypes != 1 && numTransactionTypes != 2 && numTransactionTypes != 3 )
    {
        cout << " Please Choose from the following types only " ;
        cin >> numTransactionTypes;
    }
    cout << "Enter the duration (in minutes) for each transaction type: ";
    int duration[numTransactionTypes] = {0};
    for (int i = 0; i < numTransactionTypes; i++)
    {
        cin >> duration[i];
    }

    // Initialize current customer for each teller to -1, indicating no customer
    int currentCustomer[numTellers];
    memset(currentCustomer, -1, sizeof(currentCustomer));

    for (int day = 1; day <= 1; day++)
    {
        for (int i = 0; i < numCustomersPerday; i++)
        {
            // Generate a random customer arrival time during working hours
            int arrivalTime = (rand() % WORKING_MINUTES_PER_DAY); // make the arrival time smaller than WORKING_MINUTES_PER_DAY

            // Find the next available teller
            int nextTeller = -1;
            for (int j = 0; j < numTellers; j++)
            {
                if (currentCustomer[j] < 0)
                {
                    nextTeller = j;
                    break;
                }
            }

            // If all tellers are busy, skip this customer
            if (nextTeller < 0) {
                cout << "Customer " << (i + 1) << " arrived at " << arrivalTime << " but all tellers are busy." << endl;
                continue;
            }

            // Update current customer for next available teller
            currentCustomer[nextTeller] = i;

            // Serve the customer
            cout << "Customer " << (i + 1) << " arrived at " << arrivalTime << " and is being served by teller " << (nextTeller + 1) << endl;

            // Update current customer for teller when customer is done
            int serviceTime = duration[rand() % numTransactionTypes];
            int completionTime = arrivalTime + serviceTime;
            if (completionTime < WORKING_MINUTES_PER_DAY)
            {
                currentCustomer[nextTeller] = -1;
            }
        }
    }
}

int main()
{
    srand(time(0));
    user_input();
    return 0;
}
