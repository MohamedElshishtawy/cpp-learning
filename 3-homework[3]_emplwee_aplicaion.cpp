#include <iostream>
using namespace std;

int main()
{
    const int db_max = 100;
    string e_name  [db_max];
    string e_gender[db_max];
    int    e_age   [db_max] {0};
    int    e_salary[db_max];
    
    int choice;
    while (true){
        cout << "Choice Option [1,2,3,4]"<<endl;
        cout << "1) Add New Emplyee"<<endl;
        cout << "2) Print All Emplyees"<<endl;
        cout << "3) Delete By Age"<<endl;
        cout << "4) Update Salary By Name"<<endl;
        cout << "Choice: ";
        cin  >> choice;
         
        switch (choice)
        {
            case 1: // Add New Emplyee
            {
            string name, ginder;
            int age, salary;
            cout << "Name: ";   cin >> name;
            cout << "Ginder: "; cin >> ginder;
            cout << "Age: ";    cin >> age;
            cout << "Salary: "; cin >> salary;

            //Get Impty Table
            int index;
            for(int i=0;i<db_max;i++)
            {
                if( e_age[i]==0 )
                {
                    index = i;
                    break;
                }
                    
            }

            //Insert Data
            e_name  [index] = name,
            e_gender[index] = ginder,
            e_age   [index] = age,
            e_salary[index] = salary;

            cout << "Emplyee Added Succesfuly :) " << endl;
            }
            break;

            case 2: //Show all Emplyee
            for (int i=0;i<db_max;i++){
                if (e_age[i]>0){
                    cout << "Name: "   << e_name[i]   << endl; 
                    cout << "Ginder: " << e_gender[i] << endl; 
                    cout << "Age: "    << e_age[i]    << endl; 
                    cout << "Salary: " << e_salary[i] << endl; 
                    cout << "<------------->"         << endl;
                }
            }
            break;

            case 3: //Dlete by age
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
            break;

            case 4: // Update Salary
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
            break;

        }
    }
    return 0;
}
