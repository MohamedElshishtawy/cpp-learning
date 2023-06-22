#include <iostream>
using namespace std;

// Program Methods
int choice_option();
void add_new_emplwee();
void show_all_emplyees();
void delete_by_age();
void update_salery();

// SET A DATABASE
const int db_max = 100;
string e_name  [db_max];
string e_gender[db_max];
int    e_age   [db_max] {0};
int    e_salary[db_max];

int main()
{
    while (true){
        switch (choice_option())
        {
            case  1: add_new_emplwee();   break;
            case  2: show_all_emplyees(); break;
            case  3: delete_by_age();     break;
            case  4: update_salery();     break;
            default:                      break;
        }
    }
    return 0;
}

int choice_option()
{
    int choice;
    cout << "Choice Option [1,2,3,4]"<<endl;
    cout << "1) Add New Emplyee"<<endl;
    cout << "2) Print All Emplyees"<<endl;
    cout << "3) Delete By Age"<<endl;
    cout << "4) Update Salary By Name"<<endl;
    cout << "5) Exit"<<endl;
    cout << "Choice: ";
    cin  >> choice;
    return choice;
}

void add_new_emplwee()
{
    // Collect Data
    string name, ginder;
    int age, salary, index;
    cout << "Name: ";   cin >> name;
    cout << "Ginder: "; cin >> ginder;
    cout << "Age: ";    cin >> age;
    cout << "Salary: "; cin >> salary;

    //Set An Empity Table;
    for(int i=0;i<db_max;i++)
    {
        if( e_age[i]==0 ) 
        {
        index = i;
        break;
        }
    }
    //Insert Data To The Table
    e_name  [index] = name,
    e_gender[index] = ginder,
    e_age   [index] = age,
    e_salary[index] = salary;

    cout << "Emplyee Added Succesfuly :) " << endl;
}

void show_all_emplyees()
{
    for (int i=0;i<db_max;i++)
    {
        if (e_age[i]>0)
        {
            cout << "Name: "   << e_name[i]   << endl; 
            cout << "Ginder: " << e_gender[i] << endl; 
            cout << "Age: "    << e_age[i]    << endl; 
            cout << "Salary: " << e_salary[i] << endl; 
            cout << "<------------->"         << endl;
        }
    }
}

void delete_by_age()
{
    int from,to;
    cout << "From: "; cin >> from;
    cout << "To: ";   cin >> to;
    int d_counter{0};
    for (int i=0;i<db_max;i++)
    {
        if (e_age[i] >= from && e_age[i] <= to )
        {
            e_name[i]  = '\0';
            e_gender[i]= '\0';
            e_age[i]   = 0;
            e_salary[i]= '\0';
            d_counter++;
        }
    }
    cout << d_counter << " Emplyee Has Been Deleted";
}

void update_salery()
{
    int new_salary;
    string name;
    cout << "Name To Update: "; cin >> name;
    for (int i=0;i<db_max;i++)
    {
        if (e_name[i] == name)
        {
            cout << "The Salary Is: "<< e_salary[i] << " The New One: "; cin >> new_salary;
            e_salary[i] = new_salary;
            cout << "SaLary Is Updated Succesfuly\n<----------------->\n";
            break;
        }
    }
}




