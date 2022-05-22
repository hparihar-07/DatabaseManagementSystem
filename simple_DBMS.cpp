#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <conio.h>
#include<stdlib.h>
using namespace std;

struct id
{
    string name;
    string no;
    int gpa;

};
struct node
{
   id data;
   node*next;
   node*back;
};
class SDB
{
    private:
    node*first, *last, *new_node;
    long int type;
    int counter;int flag = 0;
    public:
    SDB(){
        first=last=NULL;int counter=1;
    }
    int Construct(long int i, string n, string x, long double y)
    {
        if (first == NULL)
        {
            type=i;
            new_node = new node;
            new_node -> data.no = x;
            new_node -> data.gpa +y;
            new_node -> next = NULL;
            new_node -> back = NULL;
            first = new_node;
            last = new_node;
            counter++;
            return 1;
        }
        else
        {
            cout<<"You used create option previously"<<endl;
            return 0;
        }
    }
    int insertelement(string n, string x, long double y)
    {
        new_node = new node;
        new_node -> data.name=n;
        new_node -> data.no=x;
        new_node -> data.gpa=y;

        if (first!=NULL)
        {
            switch (type)
            {
            case 1:
            if(first -> data.name[0]>=n[0])
            {
                first -> back = new_node;
                new_node -> next = first;
                new_node -> back = NULL;
                first = new_node;
                counter++;
                return 1;
            }
            else if (last -> data.name[0]<=n[0])
            {
               last->next=new_node;
               new_node -> next=NULL;
               new_node -> back=last;
               last = new_node;
               counter++;
               return 1;
            }
            else
            {
                node*current = first;
                node*cur_next=current->next;

                for (;cur_next->next!=NULL;)
                {
                    current=current->next;
                    cur_next= cur_next ->next;

                    if (cur_next->data.name[0]>=n[0])
                    break; 
                }
                cur_next->back = new_node;
                new_node -> next=cur_next;
                new_node -> back=current;
                current->next=new_node;
                counter++;
                return 1;
            }
            break;
            case 2:
            if (first->data.no>=x)
            {
                first->back=new_node;
                new_node->next=first;
                new_node->back=NULL;
                first=new_node;
                counter++;
                return 1;
            }
            else if (last ->data.no<=x)
            {
               last->next=new_node;
               new_node->next=NULL;
               new_node->back=last;
               last=new_node;
               counter++;
               return 1;
            } 
            else
            {
                node*current=first;
                node*cur_next=current->next;

                for (;cur_next->next!=NULL;)
                {
                    current = current->next;
                    cur_next=cur_next->next;

                    if (cur_next->data.no>=x)
                    break;
                }
                cur_next->back=new_node;
                new_node->next=cur_next;
                new_node->back=current;
                current->next=new_node;
                counter++;
                return 1;
            }
            break;
            }     
        }
else{
cout<<"Please use create option first"<<endl;
return 0;
    }
}
int deleteelement(string x)
{
    if (first!=NULL)
    {
        node*del_first = first;
        node*del_last = last;
        node*del_next=del_first->next;
        node*del_back=del_last->back;
        if (first->data.no == x)
        {
            first=del_next;
            delete(del_first);
            counter--;
            return 1;
        }
        else if (last->data.no==x)
        {
            last=del_back;
            last->next=NULL;
            delete(del_last);
            counter--;
            return 1;
        }
        else{
            for (;del_first->next!=NULL;)
            {
                del_first=del_first->next;
                del_back=del_back->back;
                del_next=del_next=del_first->next;

                if (x==del_first->data.no)
                {
                    del_next->back=del_first->back;
                    del_back->next=del_first->next;
                    delete(del_back);
                    flag=1;
                    counter--;
                    return 1;
                }
                
         }
        }
        if (flag==0){
            cout<<"Wrong ID"<<endl;
            return 3;
        }
    }
else{
    cout<<"Empty database"<<endl;
    return 0;
}
}
void print(void){
    cout<<"Name\t\tID\tGPA\n\n";
    node*pri_elie=first;
    for(;pri_elie!=NULL;){
        cout<<pri_elie->data.name<<"\t"<<pri_elie->data.no<<"\t"<<pri_elie->data.gpa<<endl;
        pri_elie=pri_elie->next;
    }
}    
int savefile(void){
    node*save=first;
    int fs=0;
    ofstream fout("save.txt");
    if (!fout.is_open()) //failed to open file
    {
       cout<<"Could not open the file"<<"save.txt"<<endl;
       return 0;
    }
    fout<<"Name\t\tID\tGPA\n\n";
    for (;save!=NULL;){
        fout<<save->data.name<<"\t"<<save->data.no<<"\t"<<save->data.gpa<<endl;
        save=save->next;
        fs = 1;
    }
    fout.close();
    if (fs==0)
    {
        cout<<"Empty database!!\n";
        return 0;
    }
    else{
        cout<<"Done\n";
        return 1;
    }  
}
int searchelement(string x){
    node*sch=first;
    int f=0;
    if (first==NULL)
    {
       cout<<"Empty Database\n";
       return 0;
    }
    else{
        while (sch!=NULL)
        {
        if (sch->data.no==x)
        {
            cout<<sch->data.name<<"\t"<<sch->data.no<<"\t"<<sch->data.gpa<<endl;
            f=1;
            return 1;
            break;
        }
        sch=sch->next;
        }
        if (f==0)
        {
            cout<<"Wrong\n";
            return 3;
        } 
    }
    
}
void help(void){
    system("CLS");
    cout<<"Students Database System"<<endl;
    cout<<"You can make it ordered by Name or by ID."<<endl;
    cout<<"Functions which will help you to create a database:\n "<<"Create Function:\n"<<"You must use this function at first to create database,in this function you must enter type of order i.e by Name or by ID,if you want to insert another data you can use insert function.\n"
    <<"Insert/Delete?Search Functions:\n"<<"Using this function you can insert/delete/search any data in the database,you must use this fuction after creating a database first or after using create function.\n "
    <<"Save Function:\n"<<"This function saves the data after your work is done, be attention the folder of the program must contain (save.txt)\n"
    <<"Thanks for Reading.\n";
}
};
void show(void);
int check_num(int x = 0);
int menu();


int main(){
    show();
    SDB obj;
    long int type, test, num_cases;
    long int num_insert, num_del, num_search, check_insert, check_del,check_search;
    long double gpa;
    string name, id;

    test = 1;
    cout<<"Enter your Choice\n";
    num_cases=check_num(3);

    while (test == 1)
    {
        switch (num_cases)
        {
        case 1:
        system("CLS");
        cout<<"You choose 1 to create a database, Please enter the Name,ID and GPA of the student\n";
        getline(cin,id);
        while (name[0]<65 or name[0]>122)
        {
            cout<<"Wrong Input!\n";
            getline(cin,name);
        }

        getline(cin,id);
        while (!(cin>>gpa)or gpa >4)
        {
            cin.clear();
            while (cin.get()!='\n')continue;
            cout<<"Wrong Input!\n";
        }
        while(cin.get()!='\n')continue;
        cout <<"What type of database arrangement you want?\n"<<"1-Name    2-ID\n";
        type=check_num(2);
        obj.Construct(type,name,id,gpa);
        num_cases=menu();
        break;
    case 2:
    system("CLS");
    cout<<"You choose 2 to insert data, Please enter number of students you want to save\n";
    check_insert=1;
    num_insert=check_num(0);
    for (int j = 0; j <= num_insert; j++)
    {
        if (check_insert==1)
        {
            cout<<"Please enter name of student, Please enter the Name,ID and GPA of the student\n";
            getline(cin,name);
            while (name[0]<65 or name[0]>122)
            {
               cout<<"Wrong Input!\n";
               getline(cin,name);
            }
            getline(cin,id);

            while (!(cin>>gpa) or gpa>4)
            {
               cin.clear();
               while(cin.get()!='\n')continue;
               cout<<"Wrong Input!\n";
            }
            while(cin.get()!='\n')continue;

            check_insert=obj.insertelement(name,id,gpa);
        }
    }
    num_cases=menu();
 break;
    case 3:
    system("CLS");
    cout<<"You choose 3 to delete data, Please enter number of students you want to delete \n";
    check_del=1;
    num_del=check_num(0);
    for (int k=1;k<=num_del;k++){
        if (check_del!=0)
        {
            cout<<"Please enter ID of student\n";
            getline(cin,id);
            check_del=obj.deleteelement(id);
            if(check_del==3)k--;
        } 
    }
    num_cases=menu();
    break;
    case 4:
    system("CLS");
    cout<<"You choose 4 to search on data, Please enter number of students you want to search on\n";
    check_search = 1;
    num_search=check_num();
    for (int I=1;I<=num_search;I++){
        if (check_search!=0)
        {
            cout<<"Please enter ID of student\n";
            getline(cin,id);
            check_search=obj.searchelement(id);
            if(check_search==3)I--;
        }
    }
    num_cases=menu();
    break;
    case 5:
    system("CLS");
    obj.print();
    num_cases=menu();
    break;
    case 6:
    system("CLS");
    int save_check;
    save_check=obj.savefile();
    num_cases=menu();
    break;
    case 7:
    obj.help();
    num_cases=menu();
    break;
    case 8:
    exit(EXIT_SUCCESS);
    break;
    default:
    cout<<"Wrong input!\n";
    cout<<"Enter your choice:\n";
    num_cases=menu();
    break;
        }
}
return 0;
}
int check_num(int x){
    int num;
    switch (x)
    {
    case 1:
    case 2:
    while (!(cin>>num)or num>2)
    {
       cin.clear();
       while (cin.get()!='\n')continue;
       cout<<"Wrong Input!";
    }
       while (cin.get()!='\n')continue;
       break;
    case 3:
    while(!(cin>>num)or num>8){
        cin.clear();
        while(cin.get()!='\n')continue;
        cout<<"Wrong Input!";
    }
    while (cin.get()!='\n')continue;
    break;
    default:
    while (!(cin>>num)){
        cin.clear();
        while(cin.get()!='\n')continue;
        cout<<"Wrong Input!";
    }
    while (cin.get()!='\n')continue;
    break;
    }
    return num;
}
int login();
void show(void){
    login();

    cout <<"\n\t      ------WELCOME TO DATABASE MANAGEMENT SYSTEM------                           \n\n";


  cout << "********************************************************************************\n"
       << "********************************************************************************\n"
       << "***  1- Create Database                                                      ***\n"
       << "***  2- Insert Data                                                          ***\n"
       << "***  3- Delete Data                                                          ***\n"
       << "***  4- Search on Data                                                       ***\n"
       << "***  5- Print Data                                                           ***\n"
       << "***  6- Save                                                                 ***\n"
       << "***  7- Help                                                                 ***\n"
       << "***  8- Exit                                                                 ***\n"
       << "********************************************************************************\n"
       << "********************************************************************************\n";
  }
int menu()
{
        int num_cases;
        cout << "  Do you want to do another operation?\n "
             << " 1- Yes   2-No \n";

         int t =  check_num(1);

         if ( t == 1)
            {
            system("cls");
            show();
            cout << "Enter your choice: \n";
            num_cases = check_num(3);
            return num_cases;
            }
         else
            return 8 ;
}

int login ()
{
    string pass ="";
   char ch;
   cout << "\n\n\n\n\t\t\t\t     Database Management System";
   cout << "\n\n\n\n\n\n\n\t\t\t\t\tEnter Password: ";
   ch = _getch();
   while(ch != 13){//character 13 is enter
      pass.push_back(ch);
      cout << '*';
      ch = _getch();
   }
   if(pass == "lord"){
      cout << "\n\n\t\t\t\t\tAccess Granted \n";
   }else{
      cout << "\n\n\t\t\t\t\tAccess Aborted...Press Any Key To Try Again\n";
      ch = _getch();
      system("CLS");
      login();
   }
   system("PAUSE");
   system("CLS");
}
