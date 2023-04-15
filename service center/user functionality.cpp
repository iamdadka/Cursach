#include "Header.h"
using namespace std;
int show_order(char login[30]) {
	FILE* orders;
	order order1;
	int i = 0;
	fopen_s(&orders, "Orders.bin", "a+");

	if (!orders) {
		cout << "וננמנ" << endl;
		return NULL;
	}
	while (!feof(orders)) {
		if (!orders) {
			cout << "וננמנ" << endl;
			break;
		}
		fseek(orders, sizeof(order) * i, 0);
		if (!fread(&order1, sizeof(order), 1, orders))
			break;

		if(strcmp(order1.login,login)==0){
			show_table(order1);
		}
		i++;
	}
}