// C++ Calculator program using pointer and reference 
// Thet Oo Aung

#include <iostream>

using namespace std;

void add (float &a, float *b);
void subtract (float &a, float *b);
void multiply (float &a, float *b);
void divide (float &a, float *b);


int main()
{
    int choice;
    char again = 'y';
    float *num1 = new float;
    float num2 =0;

    do
    {
        cout << "Welcome to my simple calculator!" << endl;
        cout << "********************************" << endl;
        cout << "1) (x+y) Operation" << endl;
        cout << "2) (x-y) Operation" << endl;
        cout << "3) (x*y) Operation" << endl;
        cout << "4) (x/y) Operation" << endl;
        cout << "5) Exit the Calculator" << endl;
        cout << "*********************************" << endl;
        cout << "Choose Your Operation : ";
        cin >> choice;
        cout << endl;

        switch(choice)
        {
        case 1:
            cout << "Enter value for x :";
            cin >> *num1;
            cout << "Enter value for y :";
            cin >> num2;
            cout << endl;
            add(*num1,&num2);
            break;
        case 2:
            cout << "Enter value for x :";
            cin >> *num1;
            cout << "Enter value for y :";
            cin >> num2;
            cout << endl;
            subtract(*num1,&num2);
            break;
        case 3:
            cout << "Enter value for x :";
            cin >> *num1;
            cout << "Enter value for y :";
            cin >> num2;
            cout << endl;
            multiply(*num1,&num2);
            break;
        case 4:
            cout << "Enter value for x :";
            cin >> *num1;
            cout << "Enter value for y :";
            cin >> num2;
            cout << endl;
            divide(*num1,&num2);
            break;
        case 5:
            again = 'n';
            break;
        default:
            cout << "Invalid Input for Operation" << endl;
            cout << endl;
            break;
        }

    }
    while(again == 'y');

}




void add (float &a, float *b)
{
    cout << a << " + " << *b << " = "<< a+ *b << endl;
    cout << endl;
}


void subtract (float &a, float *b)
{
    cout <<  a << " - " << *b << " = " << a- *b <<endl;

    cout << endl;
}



void multiply (float &a, float *b)
{
    cout << a << " * " << *b << " = "  << a * (*b) <<endl;

    cout << endl;
}


void divide (float &a, float *b)
{
    if(*b==0)
    {
        cout << "Invalid y input. Cannot Divide by 0";
        cout << endl;
    }
    else
        cout << a << " / " << *b << " = " << a/ *b <<endl;
    cout << endl;

}
