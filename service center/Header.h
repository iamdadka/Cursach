#pragma once
#include <stdio.h>
#include <string>
#include <iostream>
#include <conio.h>
#include <vector>
#include <iomanip>
#include <locale.h>
#include <windows.h>
struct user {
	char login[10];
	char parol[10];
	int acces;
};
struct order {
	char name_of_product;
	char brand_of_product;
	char phone_number;
	char repair_cost;
	char date_of_acceptance;
	char date_of_issue;
	char status;
};
void registration();
int autorization();
