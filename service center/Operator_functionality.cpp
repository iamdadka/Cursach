
#include "Header.h" 
using namespace std;
int add_order() {
	struct order order1;
	FILE* orders;
	
	cout << "Ââåäèòå ëîãèí êëèåíòà";
	cin >> order1.login;
	cout << "Ââåäèòå íàèìåíîâàíèå èçäåëèÿ";
	cin >> order1.name_of_product;
	cout << "Ââåäèòå ìàðêó èçäåëèÿ";
	cin >> order1.brand_of_product;
    cout << "Ââåäèòå ÔÈÎ âëàäåëüöà";
	cin >> order1.name_of_owner;
	cout << "Ââåäèòå ñòàòóñ çàêàçà";
	cin >> order1.status;
	cout << "Ââåäèòå ñòîèìîñòü ðåìîíòà";
	cin >> order1.repair_cost;
	cout << "Ââåäèòå äàòó ïðèåìêè\n";
	cout << "Äåíü";
	cin >> order1.date_of_acceptance.day;
	cout << "Ìåñÿö";
	cin >> order1.date_of_acceptance.month;
	cout << "Ãîä";
	cin >> order1.date_of_acceptance.year;
	cout << "Ââåäèòå äàòó âûäà÷è";
	cout << "Äåíü";
	cin >> order1.date_of_issue.day;
	cout << "Ìåñÿö";
	cin >> order1.date_of_issue.month;
	cout << "Ãîä";
	cin >> order1.date_of_issue.year;
	fopen_s(&orders, "Orders.bin", "a+");
	if (!orders) {
		cout << "åððîð" << endl;
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
	cout << "—————————————————————————————————————————————————————————————————————————————————————————————\n";
	return 0;
}


int sorting_orders() {

	struct order order1;
	FILE* orders;
	int i = 0;
	fopen_s(&orders, "Orders.bin", "a+");
	Date currentdate;
	currentdate = getCurrentDate();

	cout << "|                            Ïðîñðî÷åííûå çàêàçû                                            |\n";
	cout << "—————————————————————————————————————————————————————————————————————————————————————————————\n";
	if (!orders) {
		cout << "åððîð" << endl;
		return NULL;
	}
	while(!feof(orders)) {
		if (!orders) {
			cout << "åððîð" << endl;
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
	cout << "|              Çàêàçû, îæèäàþùèå âûïîëíåíèå â ïëàíîâîì ïîðÿäêå                              |\n";
	cout << "—————————————————————————————————————————————————————————————————————————————————————————————\n";
	if (!orders) {
		cout << "åððîð" << endl;
		return NULL;
	}
	while (!feof(orders)) {
		if (!orders) {
			cout << "åððîð" << endl;
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
	cout << "|Íàèìåíîâàíèå|Ìàðêà èçäåëèÿ|   ÔÈÎ   | Òåëåôîí |Ñòîèìîñòü|Äàòà ïðèåìêè|Äàòà âûäà÷è|  Ñòàòóñ |\n";
	cout << "|  èçäåëèÿ   |             |âëàäåëüöà|âëàäåëüöà| ðåìîíòà |            |           |         |\n";
	cout << "—————————————————————————————————————————————————————————————————————————————————————————————\n";
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
		cout << "åððîð" << endl;
		return NULL;
	}
	while (!feof(orders)) {
		if (!orders) {
			cout << "åððîð" << endl;
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