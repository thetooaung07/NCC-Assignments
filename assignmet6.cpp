// Thet Oo Aung

#include<iostream>
#include<string>
#include<fstream>

using namespace std;

const int MAXROW = 10;
string USERNAME[MAXROW] = {};
string USERID[MAXROW] = {};
string USERPASSWORD[MAXROW] = {};
int AGE[MAXROW] = {};
int AMOUNT[MAXROW] = {};
string LOCATION[MAXROW] = {};

void performInsert();
void perfromDisplay();
void performSearchByUsername();
void performUpdate();
void performSaveAndExit();


int main()
{
    int selectedOperation;



    do
    {
        cout << "Welcome to Registration Program" << endl;
        cout << "Press";
        cout << "\t 1) to Insert data" << endl;
        cout << "\t 2) to Show data" << endl;
        cout << "\t 3) to Find data" << endl;
        cout << "\t 4) to Update data" << endl;
        cout << "\t 5) to Save and Exit from Program" << endl;

        cout << "Choose Operation:  ";
        cin >> selectedOperation;

        switch(selectedOperation)
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
            performUpdate();
            break;

        case 5:
            performSaveAndExit();
            cout<< "Save Successful and Exiting..." << endl;
            selectedOperation = 6;

            break;
        }

    }
    while(selectedOperation != 6);

}



void performInsert()
{
    char name[50];
    char id[20];
    char pass[20];
    char location[100];
    int age;
    int amount;

    cin.ignore();
    cout << "\n";
    cout << "Enter Id: " ;
    cin.getline(id,20);

    cout << "Enter Name: " ;
    cin.getline(name,50);
    cout << "Enter Password: " ;
    cin.getline(pass,20);
    cout << "Enter Age: " ;
    cin >> age ;
    cout << "Enter Amount: " ;
    cin >> amount ;
    cin.ignore();
    cout << "Enter Location: " ;
    cin.getline(location,100);

    for(int x = 0; x < MAXROW; x++)
    {
        if(USERID[x] == "\0")
        {
            USERID[x] = id;
            USERNAME[x] = name;
            USERPASSWORD[x] = pass;
            AGE[x] = age;
            AMOUNT[x] = amount;
            LOCATION[x] = location;
            cout << "Insert Successfully" << endl;


            cout << endl;
            cout << endl;
            break;
        }
        else
        {
            cout << "Operation Error"<< endl;
        }
    }
}

void perfromDisplay()
{

    cout << "Current Data" << endl;
    cout << "=============================================================" << endl;
    cout << "id" << "\t" <<  "name" << "\t" << "pass" << "\t" << "age" << "\t" << "amount" << "\t" << "location" << "\t" << endl;

    for (int x = 0;  x < MAXROW; x++)
    {
        if(USERID[x] != "\0")
        {

            cout << USERID[x] << "\t" << USERNAME[x]  << "\t"  << USERPASSWORD[x] << "\t" << AGE[x]  << "\t" << AMOUNT[x] << "\t" << LOCATION[x]  << "\t"  << endl;
        }

    }


    cout << "=============================================================" << endl;


}

void performSearchByUsername()
{


    string queryUsername;
    cout << "Search by Username: " ;
    cin.ignore();
    getline(cin, queryUsername);

    cout << "\nSearch Result" << endl;
    cout << "=============================================================" << endl;
    cout << "id" << "\t" <<  "name" << "\t" << "pass" << "\t" << "age" << "\t" << "amount" << "\t" << "location" << "\t" << endl;


    for (int x = 0;  x < MAXROW; x++)
    {
        if(USERNAME[x] == queryUsername)
        {

            cout << USERID[x] << "\t" << USERNAME[x]  << "\t"  << USERPASSWORD[x] << "\t" << AGE[x]  << "\t" << AMOUNT[x] << "\t" << LOCATION[x]  << "\t"  << endl;
        }

    }


}
void performUpdate()
{

    system("CLS");
    char name[50];
    cin.ignore();
    string queryUsername;
    cout << "Enter Username: ";
    getline(cin, queryUsername);

    for (int x = 0;  x < MAXROW; x++)
    {
        if(USERNAME[x] == queryUsername)


        {

            cout << "Enter Name to Update:  ";

            cin.getline(name,50);

            USERNAME[x] = name;



            cout << "Update Successful" << endl;

            perfromDisplay();
            break;
        }

    }
}


void performSaveAndExit()
{


    ofstream fout;
    fout.open("Profile.txt",  ios::out);

    for(int x = 0; x< MAXROW; x++)
    {
        if(USERID[x] != "\0")
        {
            fout << USERID[x] << "\t" << USERNAME[x]  << "\t"  << USERPASSWORD[x] << "\t" << AGE[x]  << "\t" << AMOUNT[x] << "\t" << LOCATION[x]  << "\t"  << endl;
        }
        else break;
    }

}
