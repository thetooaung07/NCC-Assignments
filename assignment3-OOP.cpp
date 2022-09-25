#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const int MAXROW = 10;

void performInsert();
void perfromDisplay();
void performSearchByUsername();

class Person
{

public:
    string name;
    string id;
    string pass;
    string location;
    string age;
    string amount;
};

int main()
{
    int selectedOperation;

    //    fstream fout;
    //    fout.open("profile.txt", ios::out);
    //    fout.close();

    do
    {
        cout << "Welcome to Registration Program" << endl;
        cout << "Press";
        cout << "\t 1) to Insert data" << endl;
        cout << "\t 2) to Show data" << endl;
        cout << "\t 3) to Find data" << endl;
        cout << "\t 4) to End Program" << endl;

        cout << "Choose Operation:  ";
        cin >> selectedOperation;

        switch (selectedOperation)
        {
        case 1:
            performInsert();
            system("CLS");
            break;
        case 2:
            system("CLS");
            perfromDisplay();
            break;
        case 3:
            system("CLS");
            performSearchByUsername();
            break;

        case 4:
            selectedOperation = 4;
            break;
        }

    }
    while (selectedOperation != 4);
}

void splitstr(string str, string deli = " ")
{

    int start = 0;
    int end = str.find(deli);
    while (end != -1)
    {
        cout << str.substr(start, end - start) << "\t";
        start = end + deli.size();
        end = str.find(deli, start);
    }
    cout << str.substr(start, end - start) << endl;
}

void performInsert()
{

    Person person;

    cin.ignore();
    cout << "\n";
    cout << "Enter Id: ";
    getline(cin, person.id);

    cout << "Enter Name: ";
    getline(cin, person.name);
    cout << "Enter Password: ";
    getline(cin, person.pass);
    cout << "Enter Age: ";
    getline(cin, person.age);
    cout << "Enter Amount: ";
    getline(cin, person.amount);

    cout << "Enter Location: ";
    getline(cin, person.location);
    cout << "Insert Successfully" << endl;

    cout << endl;
    cout << endl;

    fstream fout;
    fout.open("profile.txt", ios::app);

    fout << person.id << "-" << person.name << "-" << person.pass << "-" << person.age << "-" << person.amount << "-" << person.location << endl;
    fout.close();
};

void perfromDisplay()
{

    cout << "Current Data" << endl;
    cout << "=============================================================" << endl;
    cout << "id"
         << "\t"
         << "name"
         << "\t"
         << "pass"
         << "\t"
         << "age"
         << "\t"
         << "amount"
         << "\t"
         << "location"
         << "\t" << endl;

    fstream fin;
    fin.open("profile.txt", ios::in);
    string result[MAXROW] = {};
    for (int i = 0; i < MAXROW; i++)
    {

        fin >> result[i];
        splitstr(result[i], "-");

        if (fin.eof())
            break;
    }

    cout << "=============================================================" << endl;
};

void performSearchByUsername()
{

    string username;

    cout << "Enter Username to be searched: ";
    cin.ignore();
    getline(cin, username);

    fstream fin;
    fin.open("profile.txt", ios::in);
    string result[MAXROW] = {};
    for (int i = 0; i < MAXROW; i++)
    {

        fin >> result[i];
        if (result[i].find(username) != string::npos)
        {


            cout << "\nResults" << endl;
            cout << "=============================================================" << endl;
            cout << "id"
                 << "\t"
                 << "name"
                 << "\t"
                 << "pass"
                 << "\t"
                 << "age"
                 << "\t"
                 << "amount"
                 << "\t"
                 << "location"
                 << "\t" << endl;

            splitstr(result[i], "-");
        }
        if (fin.eof())
            break;
    }
    cout << endl;
};

