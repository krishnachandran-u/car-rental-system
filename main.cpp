#include <iostream>
#include <string>
#include <conio.h>
#include "rent.h"

using namespace std;

int main()
{

    string username;

    cout << "ABC Car rental system\n\n\n";

    username = reg_and_login();

    char repeat;

    do{
        repeat = 'n';

        view_profile(username);

        short choice = menu();

        switch(choice){

            case 1: rent_car(username);
                    break;

            case 2: return_car(username);
                    break;

            case 3: cout << "Thank you\n";
                    exit(0);

            default: invalid_entry();

        }

        cout << "Do you want to continue ? (y/any other key to quit): "; repeat = getch();

    }while(repeat == 'y');

    return 1;
}
