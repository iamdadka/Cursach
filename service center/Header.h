#pragma once
#include <stdio.h>
#include <string>
#include <iostream>
#include <conio.h>
#include <vector>
#include <iomanip>
#include <locale.h>
#include <windows.h>
#include <time.h>
struct user {
	char login[10];
	char parol[10];
	int acces;
};
struct Date {
	int day;
	int month;
	int year;
};
struct order {
	char login[30];
	char name_of_product[30];
	char brand_of_product[30];
	char name_of_owner[30];
	int repair_cost;
	struct Date date_of_acceptance;
	struct Date date_of_issue;
	char status[30];
};

int registration();
int autorization(char[30]);
int add_order();
int sorting_orders();
int show_table_header();
int show_table(order);
int show_order(char[30]);
Date getCurrentDate(); 
int income_center(Date, Date);



