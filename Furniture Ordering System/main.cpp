//C++ Program
//Furniture Ordering System - Furniture Village Company

#include <iostream>
#include<iomanip>
#include<string>
#include<fstream>

using namespace std;

struct Name
{
string name;
};

//Definition of the structure Furniture
struct Furniture
{
int FID;
Name FurnitureName;
float Price;

};

//------------------------------------------------------------------------

int main()
{
    string userType;
    string userName;
    string userPassword;
    int loginAttempt = 0;

    while (loginAttempt < 5)
    {
        cout << "Please enter your user type: ";
        cin>> userType;
        if (userType=="Administrator")
        {cout << "Please enter Adminuser name: ";
        cin >> userName;
        cout << "Please enter Admin password: ";
        cin >> userPassword;
        }
        else if (userType=="User")
        {cout << "Please enter your user name: ";
        cin >> userName;
        cout << "Please enter your user password: ";
        cin >> userPassword;
        }

        if (userName == "Admin" && userPassword == "Admin321")
        {
            break;
        }
        else if (userName == "Thomas" && userPassword == "456")
        {
            break;
        }
        else if (userName == "Adam" && userPassword == "789")
        {
            break;
        }
        else if (userName == "Anna" && userPassword == "654")
        {
            break;
        }
        else if (userName == "Olivia" && userPassword == "102")
        {
            break;
        }
        else if (userName == "James" && userPassword == "567")
        {
            break;
        }
        else
        {
            cout << "Access Denied. Please try again.\n" << '\n';
            loginAttempt++;
        }
    }
    if (loginAttempt == 5)
    {
            cout << "Too many login attempts! The program will terminate now.....";
            return 0;
    }


//Furniture type array declaration
Furniture availableRecord[20];
int Sel;
ifstream inf;
inf.open("data.txt");
int PrintMenu();
void Input(Furniture a[20],ifstream &);
void Print (Furniture a[20]);
void searchID(Furniture a[20]);
void Help(Furniture a[20]);
system("cls");
do{
Sel=PrintMenu();

switch(Sel)
{
case 1: Input(availableRecord,inf);
break;
case 2: Print (availableRecord);
break;
case 3: searchID(availableRecord);
break;
case 4: Help(availableRecord);
break;
case 5: cout<<"Thank you for visiting Furniture Village !......."<<endl;
break;
default:cout<<"Invalid selection"<<endl;
}
cout<<endl<<endl<<endl<<endl;

system("pause");
system("cls");

}while(Sel!=5);

system("pause");
return 0;
}

//-----------------------------------------------------------------------
//Display the Main Menu
int PrintMenu()
{
int x;

cout<<"==== Welcome to Furniture Village Company ! ===="<<endl<<endl;
cout<<"Furniture Ordering System"<<endl<<endl;
cout<<"1).\tUpdate the Furniture list"<<endl;
cout<<"2).\tAvailable Furniture"<<endl;
cout<<"3).\tSearch Furniture"<<endl;
cout<<"4).\tHelp"<<endl;
cout<<"5).\tExit"<<endl<<endl;

cout<<"Please enter your selection:";
cin>>x;
return x;

}

//-----------------------------------------------------------------------
//1.) Input furniture data from 'Data.txt' file
void Input(Furniture a[20],ifstream &in)
{
if(!in)
cout<<"File not found"<<endl;
else
{
int x=0;
while(in)
{
in>>a[x].FID;
in>>a[x].FurnitureName.name;
in>>a[x].Price;

x++;
}
cout<<".....Furniture List updated successfully....."<<endl;
}

}


//-----------------------------------------------------------------
//2.) Print the list of available furniture

void Print(Furniture a[20])
{
cout<<"Available Furniture List"<<endl;
cout<<"========================"<<endl<<endl;
cout<<"\t"<<left<<setw(8)<<"FID"<<setw(10)<<"Furniture"<<setw(5)<<"Price"<<endl<<endl;

for(int x=0;x<10;x++)
{
cout<<x+1<<".)\t"<<setw(8)<<a[x].FID<<setw(10)<<a[x].FurnitureName.name;
cout<<setw(10)<<a[x].Price<<endl;
}
}

//----------------------------------------------------------------------
//3.) Search furniture types by Furniture ID

void searchID(Furniture a[20])
{
int x,fid;
bool flag=false;

cout<<"\nEnter FID to search record:"<<endl;
cin>>fid;

 for(x=0;x<10;x++)
{
if(fid==a[x].FID)
{
cout<<"Searched Furniture item:";
cout<<a[x].FurnitureName.name<<endl;
cout<<"Price of the Furniture item in LKR:";
cout<<a[x].Price<<endl;


flag=true;
break;
}
}

if(flag==false)
cout<<"Furniture record not found within the system......"<<endl;

}

//--------------------------------------------------------------------------
//4.) Help Guide


void Help(Furniture a[20])
{
cout<<"\n* Please note that only administrators are allowed to add furniture into the system"<<endl<<endl;
cout<<"* Please make sure to update the Furniture List by first selecting option 1"<<endl<<endl;
cout<<"* Select option 2 from the main menu in order to view the list of available furniture and their prices"<<endl<<endl;
cout<<"* In case if the required output isn't visible please refresh the system by selecting option 1"<<endl<<endl;
cout<<"* Searching for furniture items can only be done by entering the relevant Furniture ID "<<endl<<endl;
cout<<"* Select option 5 from the main menu to exit from the system"<<endl;


}

//-------------------------------------------------------------------------
