#ifndef RENT_H_INCLUDED
#define RENT_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

void invalid_entry();

string reg_and_login();

void registration();

string DidLogin();

void view_profile(string username);

short menu();

void rent_car(string username);

void return_car(string username);

#endif // RENT_H_INCLUDED
