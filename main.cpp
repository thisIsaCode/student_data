#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
using namespace std;
int main()
{
    char data[15];
    int n = 0, option = 0, count_n = 0; // Initial marks alloted to a subject
    string empty = "00";
    string proctor = "";       // ifstream is used to open file in read format.
    ifstream f("example.txt"); // Name of the file iin which the database is stored
    string line;
    for (int i = 0; std::getline(f, line); i++) // for loop to count the total number of lines in the file.
    {
        count_n++;
    }
    while (option != 6)
    {
        cout << "\nAvailable operations : \n1. Add New Students \n2. Student Login \n3. Faculty Login \n4. Proctor Login \n5. Admin View \n6. Exit \nEnter Option : ";
        cin >> option;
    }
    if (option == 1)
    {
        cout << "Enter the number of the stduents : ";
        cin >> n;
        count_n = count_n + n;
        for (int i = 0; i < n; i++)
        {
            ofstream outfile;                      // ofstream is used to open file in write format.
            outfile.open("Example.txt", ios::app); // ios::app puts your cursor to the end of the file while ios::ate puts your cursor to the position where you last left.
            // The entire data of a single student is stored line-by-line.
            cout << "Enter your registration number : ";
            cin >> data;
            outfile << data << "\t";
            cout << "Enter your name : ";
            cin >> data;
            int len = strlen(data);
            while (len < 15)
            {
                data[len] = ' ';
                len = len + 1;
            }
            outfile << data << "\t";
            // Inserting empty data initially into the file.
            outfile << empty << "\t";
            outfile << empty << "\t";
            cout << "Enter your proctor ID : ";
            cin >> proctor;
            outfile << proctor << endl;
        }
    }
    else if (option == 2)
    {
        char regno[9];
        cout << "Enter your registration number : ";
        cin >> regno;
        ifstream infile;
        int check = 0;
        infile.open("Example.txt", ios::in);
        while (infile >> data) // this loop prints out the data according to the registartion number.
        {
            if (strcmp(data, regno) == 0)
            {
                cout << "\nRegistration Number : " << data << endl;
                infile >> data;
                cout << "Name : " << data << endl;
                infile >> data;
                cout << "CSE1001 marks : " << data << endl;
                infile >> data;
                cout << "CSE1002 marks : " << data << endl;
                infile >> data;
                cout << "Proctor ID : " << data << endl;
                infile.close();
                check = 1;
            }
        }
        if (check == 0)
        {
            cout << "No such registration number found!" << endl; // For incorrect registration number.
        }
    }
    else if (option == 3)
    {
        char subcode[7];
        cout << "Enter your subject code : ";
        cin >> subcode;
        string code1 = "CSE1001", code2 = "CSE1002", mark = "";
        ifstream infile;
        int check = 0;
        cout << "\nAvailable opertaions : \n1. Add data about marks \n2.Veiw data \nEnter options : ";
        cin >> option;
        if (option == 1)
        {
            cout << "Warning! You would need to add mark details for all the students! " << endl;
            for (int i = 0; i < count_n; i++)
            {
                fstream file("Example.txt");
                if (strcmp(subcode, code1.c_str()) == 0)
                {
                    file.seekp(26 + 37 * i, std::ios_base::beg);
                    cout << "Enter the marks of the students : " << (i + 1) << ":";
                    cin >> mark;
                    file.write(mark.c_str(), 2);
                }
                if (strcmp(subcode, code2.c_str()) == 0)
                {
                    file.seekp(29 + 37 * i,std::ios_base::beg);
                    cout << "Enter the marks of the students : " << (i + 1) << ":";
                    cin >> mark;
                    file.write(mark.c_str(), 2);
                }
            }
        }
        else if(option==2)
        {
            infile.open("Example.txt",ios::in);
            if(strcmp(subcode,code1.c_str())==0)
            {
                cout<<"Registration Number - Marks \n"<<endl;
                while(infile>>data)
                {
                    cout<<data;
                    infile>>data;
                    infile>>data;
                    cout<<" - "<<data<<endl;
                    infile>>data;
                    infile>>data;
                    check=1;
                }
            }
            infile.close();
            infile.open("Example.txt",ios::in);
            if(strcmp(subcode,code2.c_str())==0)
            {
                cout<<"Registration Number - Marks\n"<<endl;
                while(infile>>data)
                {
                    cout<<data;
                    infile>>data;
                    infile>>data;
                    infile>>data;
                    cout<<" - "<<data<<endl;
                    infile>>data;
                    check=1;
                }
            }
        }
        infile.close();
        if(check==0)
        {
            cout<<"No such subject code found!"<<endl;
        }
    }
    else if(option==4)
    {
        char procid[7];
        cout<<"Enter your proctor ID : ";
        cin>>procid;
        int check=0;
        char temp1[100],temp2[100],temp3[100];
        char temp4[100],id[100];
        ifstream infile;
        infile.open("Example.txt",ios::in);
        while(infile>>temp1)
        {
            infile>>temp2;
            infile>>temp3;
            infile>>temp4;
            infile>>id;
            if(strcmp(id,procid)==0)
            {
                cout<<"\nRegistration Number : "<<temp1<<endl;
                cout<<"Name : "<<temp2<<endl;
                cout<<"CSE1001 Mark : "<<temp3<<endl;
                cout<<"CSE1002 Mark : "<<temp4<<endl;
                check=1;
            }
        }
        if(check==0)
        {
            cout<<"No such proctor ID found!"<<endl;
        }
    }
    else if(option==5)
    {
        char password[25];
        cout<<"Enter the admin password : ";
        cin>>password;
        string admin_pass="admin";
        if(strcmp(password,admin_pass.c_str())==0)
        {
            cout<<"Reg No. \tName \tCSE1001 \tCSE1002 \tProctor ID"<<endl;
            ifstream infile;
            infile.open("Example.txt",ios::in);
            char data[20];
            while(infile>>data)
            {
                cout<<data<<"\t";
                infile>>data;
                cout<<data<<"\t";
                infile>>data;
                cout<<data<<"\t";
                infile>>data;
                cout<<data<<"\t";
                infile>>data;
                cout<<data<<endl;
            }
        }
    }
    return 0;
}