#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <conio.h>
#include "rent.h"

using namespace std;

void invalid_entry(){

    cout << "\n---Invalid entry---\n" <<endl;
    exit(0);

}

string reg_and_login(){

    int choice;

    cout << "1 -> Registration\n2 -> Login"<<endl;
    cout << "Select choice: "; cin>>choice; cout<<"\n";

    //Calls registration(), hence performs the registration and calls the main function again so as to decide whether to register again or login.
    if(choice == 1){

        registration();

        reg_and_login();

    }

    //Calls DidLogin() which returns true or false based on the status of login.
    if(choice == 2){

        return DidLogin();

    }

    else invalid_entry();

}

void registration(){

    string username, password;

    cout << "Enter username: " ; cin >> username;
    cout << "Enter password: " ; cin >> password; cout<<"\n";

    //The username and password is written into a dedicated username.txt file in the consecutive lines.

    ofstream credfile, rentfile;

    credfile.open("credentials\\" + username + ".txt");
    credfile << username << endl << password;
    credfile.close();

    rentfile.open("rent_info\\" + username + ".txt");
    rentfile << "NIL";
    rentfile.close();

}

string DidLogin(){

    string username, password, usercheck, passcheck;

    //Asks the user for credentials

    cout << "Enter username: " ; cin >> username;
    cout << "Enter password: " ; cin >> password;

    //Reads the username.txt file, if present and checks whether the credentials entered by the user and the stored credentials are the same.

    ifstream credfile_1("credentials\\" + username + ".txt");

    //Each time getline() is called, it reads input from the next line in the text file.

    getline(credfile_1, usercheck);
    getline(credfile_1, passcheck);

    if(usercheck == username && passcheck == password) return username;
    else{

        cout<< "\nFalse Login!" <<endl;

        exit(0);

    }
}

void view_profile(string username){

    ifstream rentfile("rent_info\\" + username + ".txt");
    string rented_car;
    getline(rentfile, rented_car);

    cout << "\n\nPROFILE\n\nUsername: " << username << "\nRented car: " <<  rented_car << "\n\n";
    rentfile.close();

}

short menu(){

    short choice;

    cout << "1 -> Rent a car\n2 -> Return a car\n3 -> Quit\n\nSelect choice: "; cin>>choice; cout<<"\n\n";
    return choice;

}

void rent_car(string username){

    string current_rent;
    ifstream rentfile("rent_info\\" + username + ".txt");

    getline(rentfile, current_rent);

    if(current_rent != "NIL"){

        cout<<"Return the rented car to rent again\n"<<endl;
        system("pause");
        return;

    }

    rentfile.close();

    struct car_info{

        string name;
        int price;

    };

    car_info car[5]={{"Model A", 5000}, {"Model B", 7500}, {"Model C", 10000}, {"Model D", 15000}, {"Model E", 20000}};

    cout<<"Select the model\n\n"<<endl;

    for(int i=0; i<5; i++) cout << i+1 << " -> " << car[i].name << "    Price: Rs."<< car[i].price << " per day\n" <<endl;

    short choice, days;
    char payornot;

    cout << "\nEnter your choice (number): "; cin >> choice; if(choice <1 || choice >5) invalid_entry();

    cout << "CAR SELECTED: " << car[choice - 1].name <<endl;

    cout << "Enter the number of days: "; cin >> days; if(days < 1) invalid_entry();

    cout << "\nPay amount Rs."<<days*car[choice - 1].price<<" (y/any other key to abort): "; payornot = getche() ; if(payornot != 'y') exit(0);

    cout << "\nPayment processing...\n"; system("pause");  cout << "\nPayment successful!\n";

    ofstream rentfile_2;

    rentfile_2.open("rent_info\\" + username + ".txt");
    rentfile_2 << car[choice - 1].name <<endl;
    rentfile_2.close();


    cout << "\nCar rented\n" << endl;
    return;

}

void return_car(string username){

    string current_rent;
    char choice;

    ifstream rentfile_3("rent_info\\" + username + ".txt");

    getline(rentfile_3, current_rent);

    if(current_rent == "NIL"){

        cout << "Rent a car to return\n" << endl;
        system("pause");
        return;

    }

    cout << "Confirm (Press y): "; choice = getche(); cout << "\n"; if(choice != 'y') exit(0);

    ofstream rentfile_4;

    rentfile_4.open("rent_info\\" + username + ".txt");
    rentfile_4 << "NIL";
    rentfile_4.close();

    system("pause");
    cout << "\nCar returned successfully\n" << endl;

    return;

}
