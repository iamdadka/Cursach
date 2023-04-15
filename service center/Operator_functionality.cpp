
#include "Header.h" 
using namespace std;
int add_order() {
	struct order order1;
	FILE* orders;
	
	cout << "Āāåäčņå ėīćčķ źėčåķņą";
	cin >> order1.login;
	cout << "Āāåäčņå ķąčģåķīāąķčå čēäåėč’";
	cin >> order1.name_of_product;
	cout << "Āāåäčņå ģąšźó čēäåėč’";
	cin >> order1.brand_of_product;
    cout << "Āāåäčņå ŌČĪ āėąäåėüöą";
	cin >> order1.name_of_owner;
	cout << "Āāåäčņå ńņąņóń ēąźąēą";
	cin >> order1.status;
	cout << "Āāåäčņå ńņīčģīńņü šåģīķņą";
	cin >> order1.repair_cost;
	cout << "Āāåäčņå äąņó ļščåģźč\n";
	cout << "Äåķü";
	cin >> order1.date_of_acceptance.day;
	cout << "Ģåń’ö";
	cin >> order1.date_of_acceptance.month;
	cout << "Ćīä";
	cin >> order1.date_of_acceptance.year;
	cout << "Āāåäčņå äąņó āūäą÷č";
	cout << "Äåķü";
	cin >> order1.date_of_issue.day;
	cout << "Ģåń’ö";
	cin >> order1.date_of_issue.month;
	cout << "Ćīä";
	cin >> order1.date_of_issue.year;
	fopen_s(&orders, "Orders.bin", "a+");
	if (!orders) {
		cout << "åššīš" << endl;
		return NULL;
	}
	fwrite(&order1, sizeof(order), 1, orders); 
	fclose(orders);
	
}

 


Date getCurrentDate()
{
	struct tm localtime;
	time_t now = time(NULL); localtime_s(&localtime, &now); Date currentDate;
	currentDate.day = localtime.tm_mday;
	currentDate.month = 1 + localtime.tm_mon;
	currentDate.year = 1900 + localtime.tm_year;
	return currentDate;
}

int show_table(order order1) {
	cout << "|" << setw(12) << order1.name_of_product << "|";
	cout << setw(13) << order1.brand_of_product << "|";
	cout << setw(9) << order1.name_of_owner << "|";
	cout << setw(9) << order1.login << "|";
	cout << setw(9) << order1.repair_cost << "|";
	cout << setw(3) << order1.date_of_acceptance.day << "." << setw(2) << order1.date_of_acceptance.month << "." << setw(5) << order1.date_of_acceptance.year << "|";
	cout << setw(2) << order1.date_of_issue.day << "." << setw(2) << order1.date_of_issue.month << "." << setw(5) << order1.date_of_issue.year << "|";
	cout << setw(9) << order1.status << "|" << endl;
	cout << "\n";
	return 0;
}


int sorting_orders() {

	struct order order1;
	FILE* orders;
	int i = 0;
	fopen_s(&orders, "Orders.bin", "a+");
	Date currentdate;
	currentdate = getCurrentDate();

	cout << "|                            Ļšīńšī÷åķķūå ēąźąēū                                            |\n";
	cout << "\n";
	if (!orders) {
		cout << "åššīš" << endl;
		return NULL;
	}
	while(!feof(orders)) {
		if (!orders) {
			cout << "åššīš" << endl;
			break;
		}
		fseek(orders, sizeof(order) * i, 0);
		if (!fread(&order1, sizeof(order), 1, orders))
			break;

		if (order1.date_of_issue.year < currentdate.year) {
			show_table(order1); i++; continue;
		}
		if (order1.date_of_issue.year = currentdate.year) {
			if (order1.date_of_issue.month < currentdate.month) {
				show_table(order1); i++; continue;
			}
			if (order1.date_of_issue.month = currentdate.month) {
				if (order1.date_of_issue.day < currentdate.day) {
					show_table(order1);
				}
			}
		}
		i++;
	}
	fclose(orders);
	fopen_s(&orders, "Orders.bin", "a+");
	i = 0;
	cout << "|              Ēąźąēū, īęčäąžłčå āūļīėķåķčå ā ļėąķīāīģ ļīš’äźå                              |\n";
	cout << "\n";
	if (!orders) {
		cout << "åššīš" << endl;
		return NULL;
	}
	while (!feof(orders)) {
		if (!orders) {
			cout << "åššīš" << endl;
			break;
		}
		fseek(orders, sizeof(order) * i, 0);
		if (!fread(&order1, sizeof(order), 1, orders))
			break;

		if (order1.date_of_issue.year > currentdate.year) {
			show_table(order1); i++; continue;
		}
		if (order1.date_of_issue.year = currentdate.year) {
			if (order1.date_of_issue.month > currentdate.month) {
				show_table(order1); i++; continue;
			}
			if (order1.date_of_issue.month = currentdate.month) {
				if (order1.date_of_issue.day > currentdate.day) {
					show_table(order1);
				}
			}
		}
		i++;
	}
	fclose(orders);
}


int show_table_header() {
	cout << "_____________________________________________________________________________________________\n";
	cout << "|Ķąčģåķīāąķčå|Ģąšźą čēäåėč’|   ŌČĪ   | Ņåėåōīķ |Ńņīčģīńņü|Äąņą ļščåģźč|Äąņą āūäą÷č|  Ńņąņóń |\n";
	cout << "|  čēäåėč’   |             |āėąäåėüöą|āėąäåėüöą| šåģīķņą |            |           |         |\n";
	cout << "\n";
	return 0;
}

int income_center(Date x, Date y) {
	struct order order1;
	FILE* orders;
	int i = 0, income = 0;
	fopen_s(&orders, "Orders.bin", "a+");
	Date currentdate;
	currentdate = getCurrentDate();

	if (!orders) {
		cout << "åššīš" << endl;
		return NULL;
	}
	while (!feof(orders)) {
		if (!orders) {
			cout << "åššīš" << endl;
			break;
		}
		fseek(orders, sizeof(order) * i, 0);
		if (!fread(&order1, sizeof(order), 1, orders))
			 break;

		if (order1.date_of_issue.year > x.year && order1.date_of_issue.year < y.year) {
			income+=order1.repair_cost; i++; continue;
		}
		if (order1.date_of_issue.year == x.year) {
			if (order1.date_of_issue.month < x.month ) {
				income += order1.repair_cost; i++; continue;
			}
			if (order1.date_of_issue.month == x.month) {
				if (order1.date_of_issue.day < x.day) {
					income += order1.repair_cost;
				}
			}
		}
		if (order1.date_of_issue.year == y.year) {
			if (order1.date_of_issue.month < y.month) {
				income += order1.repair_cost; i++; continue;
			}
			if (order1.date_of_issue.month == y.month) {
				if (order1.date_of_issue.day < y.day) {
					income += order1.repair_cost;
				}
			}
		}
		i++;
	}
	fclose(orders);
	return income;
}