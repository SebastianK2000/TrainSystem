#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct Ticket
        {
            int numberTicket;
            string firstName, lastName;
            string travelDate, travelTime;
        };

struct Train
        {
            int trainNumber;
            string endStation, startStation, endTime, startTime;
        };

    void reservationTicket(queue<Ticket>& ticketQueue)
    {

        Ticket newTicket;

        cout << "What's your name?";
        cin >> newTicket.firstName;
        cout << "What's your last name?";
        cin >> newTicket.lastName;
        cout << "Travel date: ";
        cin >> newTicket.travelDate;
        cout << "Travel time: ";
        cin >> newTicket.travelTime;

        ticketQueue.push(newTicket);

        cout << "Ticket reserved successfully." << endl;
    }

    void addTrain(queue<Train>& trainSchedule)
    {

        Train addTrain;

        cout << "What's number train?";
        cin >> addTrain.trainNumber;
        cout << "What's is departure station?";
        cin >> addTrain.endStation;
        cout << "What's is arrival station?";
        cin >> addTrain.startStation;
        cout << "What's is departure time?";
        cin >> addTrain.endTime;
        cout << "What's is arrival time?";
        cin >> addTrain.startTime;

        trainSchedule.push(addTrain);

        cout << "Train add successfully." << endl;
    }

    void displayConnections(queue<Train> trainSchedule)
    {
        if (trainSchedule.empty()) {
            cout << "No trains in the schedule." << endl;
        } else {
            cout << "Available connections:" << endl;
            int count = 1;

            while (!trainSchedule.empty()) {
                const Train& train = trainSchedule.front();
                cout << "Connection " << count << ":" << endl;
                cout << "Train number: " << train.trainNumber << endl;
                cout << "Departure station: " << train.startStation << endl;
                cout << "Arrival station: " << train.endStation << endl;
                cout << "Departure time: " << train.startTime << endl;
                cout << "Arrival time: " << train.endTime << endl << endl;

                trainSchedule.pop();
                count++;
            }
        }
    }


int main()
{
    queue<Ticket> ticketQueue;
    queue<Train> trainSchedule;

    int choice;
    bool exit = false;

    while (!exit)
    {
        cout << "========== Train/Ticket System ==========" << endl;
        cout << "1. Reserve a ticket" << endl;
        cout << "2. Add a train to the schedule" << endl;
        cout << "3. Display available connections" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                reservationTicket(ticketQueue);
                break;
            case 2:
                addTrain(trainSchedule);
                break;
            case 3:
                displayConnections(trainSchedule);
                break;
            case 4:
                exit = true;
                break;
            default:
                cout << "Invalid choice. Please try again" << endl;
        }
    }

    return 0;
}