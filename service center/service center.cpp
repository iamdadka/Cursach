
//В сервисном центре хранится информация обо всех заказах: наименование ремонтируемого изделия (телевизор и т. д.), 
//марка изделия, ФИО владельца, телефон владельца, стоимость ремонта, дата приемки, дата выдачи, статус 
//(выполнен или нет).
//Индивидуальное задание : вывести список заказов, невыполненных на текущий момент
//(сначала – просроченные, затем – ожидающие выполнения в плановом порядке).Вывести общий доход от даты x до даты y
//(x, y вводятся с клавиатуры).
//Общее для всех вариантов задание : реализовать авторизацию для входа в систему, 
//функционал администратора и функционал пользователя
//(см.более подробно в функциональных требованиях к курсовой работе, подраздел 1.2).



#include "Header.h"

int main()
{   
	using namespace std;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int answer_reg_aut, acces;
	char login[30];
    cout << "1.Регистрация\n2.Авторизация\n";
	cin >> answer_reg_aut;
	switch (answer_reg_aut){
	case 1: registration(); 
		    cout << "Авторизация: ";
		    cout << "Введите логин\n";
		    cin >> login; 
			acces = autorization(login);
			break;
	case 2: cout << "Введите логин\n";
		    cin >> login; 
			acces = autorization(login);
			break;
	default: break;
	}
	int answer;
	if (acces == 1) {
		do {
			cout << "1.Проверить статус ремонта изделий\n";
			cout << "2.Закончить работу\n";
			cin >> answer;
			switch (answer) {
			case 1: show_table_header();
				    show_order(login);
					break;
			case 2:  return 0; break;
			default: answer = 0; 
			}
		} while (answer != 2);
	}
	int income;
	Date x, y;
	if (acces == 2) {
		do {
			cout << "1.Добавить заказ\n";
			cout << "2.Сортировать заказы по дате их выдачи\n";
			cout << "3.Создать отчёт о доходе центра от даты x до y\n";
			cout << "4.Закончить работу\n";
			cin >> answer;
			switch (answer) {
			case 1:
				add_order();
			case 2: 
				show_table_header();
				sorting_orders();
				break;
			case 3: cout << "Введите дату x\n";
	                cout << "День\n";
	                cin >> x.day;
	                cout << "Месяц\n";
	                cin >> x.month;
	                cout << "Год\n";
	                cin >> x.year;
	                cout << "Введите дату y\n";
	                cout << "День\n";
	                cin >> y.day;
	                cout << "Месяц\n";
	                cin >> y.month;
	                cout << "Год\n";
	                cin >> y.year;
	                income = income_center(x, y);
	                cout << "Доход центра от даты x до y: \n" << income << endl;
					break;
			case 4: return 0; break;
			}
		} while (answer != 4);
	}
	
}




