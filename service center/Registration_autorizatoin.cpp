
#include "Header.h"

using namespace std;




FILE* flogin;
char a;
void registration() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	printf("Регистрация:\n");
	char login[10], parol[10], tlogin[10], access[2];
	fopen_s(&flogin, "Login_parol.txt", "a+");
	int a = 0;
	printf("Введите логин\n");
	cin.getline(login, 10);
	if (flogin!=0){
	while (!feof(flogin)) {
		fgets(tlogin, strlen(login) + 1, flogin);
		if (strcmp(tlogin, login) == 0) { printf("Такой логин уже существует!\n"); a = 2; fclose(flogin); break; }

	}
	if (a == 0) {
		fputs(login, flogin);
		printf("Введите пароль\n");
		cin.getline(parol, 10);
		fputs(parol, flogin);
		printf("Введите уровень доступа:\n1.Администратор\n2.Работник сервисного центра\n");
		cin.getline(access, 2);
        fputs(access, flogin);
        fputs("\n", flogin);
	};
	fclose(flogin);
	}
};

int autorization() {
	int a = 0, aces;
	char login[30], parol[10], tloginparol[100], acces[100];
	printf("Авторизация:\n");
	printf("Введите логин\n");
	cin.getline(login, 10);
	printf("Введите пароль\n");
	cin.getline(parol, 10);
	strncat_s(login, parol, 10);
	fopen_s(&flogin, "Login_parol.txt", "a+");
	if(flogin!=0){
	while (!feof(flogin)) {
		fgets(tloginparol, strlen(login) + 1, flogin);
		if (strcmp(tloginparol, login) == 0) {
			printf("Вы успешно вошли в аккаунт!"); a = 10;
			cout << acces; fclose(flogin);  break;
			
		}
	}
	if (a == 0) { printf("Неверный логин или пароль"); return 0; }
	
	}
	
	
}