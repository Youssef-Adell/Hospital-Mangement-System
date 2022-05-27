#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int MAX = 20;

struct patient_queue
{
    int spec;
    deque<pair<string, int>> patients;

    patient_queue()
    {
        spec = -1;
    }
    patient_queue(int _spec)
    {
        spec = _spec;
    }

    bool add_back(string name, int status)
    {
        if (patients.size() == 5)
            return false;

        patients.push_back({name, status});
        return true;
    }
    bool add_front(string name, int status)
    {
        if (patients.size() == 5)
            return false;

        patients.push_front({name, status});
        return true;
    }
    bool get_front()
    {
        if (patients.empty())
        {
            return false;
        }
        cout << patients.front().first << " go with Dr\n\n";
        patients.pop_front();
        return true;
    }
    void print()
    {
        if (patients.empty())
            return;

        cout << "There are " << patients.size() << " Patient in specialization NO: " << spec << "\n";
        for (pair<string, int> patient : patients)
        {
            cout << "Name: " << patient.first;
            if (patient.second == 1)
                cout << "\tStatus: urgent\n";
            else
                cout << "\tStatus: regular\n";
        }
        cout << "\n\n";
    }
};

struct hospital_system
{
    vector<patient_queue> specializations;

    hospital_system()
    {
        specializations = vector<patient_queue>(MAX);
        for (int i = 0; i < MAX; i++)
        {
            specializations[i] = patient_queue(i);
        }
    }

    void run()
    {
        while (true)
        {
            int choice = menu();

            switch (choice)
            {
            case 1:
                add_patient();
                break;
            case 2:
                print_patients();
                break;
            case 3:
                get_patient();
                break;
            case 4:
                return;
                break;
            }
        }
    }
    int menu()
    {
        int choice;
        while (true)
        {
            cout << "\n1) Add Patient\n";
            cout << "2) print patients\n";
            cout << "3) Get Next Patient\n";
            cout << "4) Exit\n\n";
            cout << "Enter Choice [1:4]: ";
            cin >> choice;
            cout << "\n";

            if (choice >= 1 && choice <= 4)
            {
                // system("CLS");
                return choice;
            }
            else
                cout << "InValid Input, Try again..\n";
        }
    }

    void add_patient()
    {
        int spec, status;
        string name;

        cout << "Enter Specialization NO, Patient Name, Status[1= Urgent, 0= Regular]: \n";
        cin >> spec >> name >> status;

        bool stat;
        if (status == 0)
            stat = specializations[spec].add_back(name, status);
        else
            stat = specializations[spec].add_front(name, status);

        if (stat == false)
            cout << "sorry we cant add more \n";
    }
    void print_patients()
    {
        cout << "-----------------------\n";
        for (int i = 0; i < MAX; i++)
        {
            specializations[i].print();
        }
    }
    void get_patient()
    {
        int spec;
        cout << "Enter Specialization Num: ";
        cin >> spec;

        bool stat;
        stat = specializations[spec].get_front();

        if (stat == false)
            cout << "No Patient in this specialization, take a rest dr..\n";
    }
};

int main()
{
    struct hospital_system hospital1;

    hospital1.run();

    return 0;
}
