// C++ Register program using file IO and Function
// Thet Oo Aung

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

void performInsert();
void performSearchByUsername();
void performUpdate();

int id, amount, age;
char username[50], password[50], location[100];
int willContinue;
int selectedOperation;

int main()
{
    do
    {

        cout << "Welcome to Registration Program" << endl;
        cout << "Press";
        cout << "\t 1) to insert data" << endl;
        cout << "\t 2) to find data" << endl;
        cout << "\t 3) to update data" << endl;

        cout << "Choose One of the numbers to perform Operation:  ";
        cin >> selectedOperation;



        switch(selectedOperation)
        {
        case 1:
            performInsert();
            break;

        case 2:
            performSearchByUsername();
            break;

        case 3:
            performUpdate();
            break;

        case 4:
            willContinue = 4;
            break;
        }

    }
    while(willContinue != 4);


}


void performInsert()
{

    cout << "\nRegistering New User\n" << endl;

    cout << "Enter Your ID: ";
    cin>> id;
    cout << "Enter Your Name: ";
    cin >> username;
    cout << "Enter Your Password: ";
    cin >> password;
    cout << "Enter Your Age: ";
    cin >> age;
    cout << "Enter Your Amount: ";
    cin >> amount;
    cout << "Enter Your Location: ";
    cin >> location;

    ofstream fout;
    fout.open("profile.txt", ios::out);


//    fout << "ID       : " << id << endl;
//    fout << "Name     : " << username << endl;
//    fout << "Password : " << password << endl;
//    fout << "age      : " << age << endl;
//    fout << "amount   : " << amount << endl;
//    fout << "location : " << location << endl;
//    fout << endl;


    fout << id << "\t" << username << "\t" << password << "\t"<< age << "\t"<< amount << "\t" << location << "\t" << endl;
    fout.close();

    cout << endl;
    cout << "Insert Data Successfully~"<< endl;
    cout << endl;

}
void performSearchByUsername()
{

    cout << "\nSearch User By Name\n" << endl;

    ifstream fin;
    fin.open("Profile.txt");
    string temp;
    string line;
    string inputUsername;

    cout << "Search by Username: ";
    cin >> inputUsername;


    if(fin.is_open())
    {
        while(getline(fin, temp))
        {
            line.append(temp);
            if(line.find(inputUsername) != string::npos)
            {
                cout << temp << endl;
                break;
            }
            else
            {
                cout<< "\nUser not found!" << endl;
            }
        }
        fin.close();
    }

}
void performUpdate()
{


  cout << "\Update User\n" << endl;

    ifstream fin;
    fin.open("Profile.txt");
    string temp;
    string line;
    string inputUsername;

    cout << "Type username to update: ";
    cin >> inputUsername;


    if(fin.is_open())
    {
        while(getline(fin, temp))
        {
            line.append(temp);
            if(line.find(inputUsername) != string::npos)
            {
                cout << temp << endl;
                break;
            }
            else
            {
                cout<< "\nUser not found!" << endl;
            }
        }
        fin.close();
    }




}
