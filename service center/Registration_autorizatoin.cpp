
//����� �������������� ���� � login: 297293410
//                            parol: 2905


#include "Header.h"

using namespace std;

int registration() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int i = 0;
	char login[30];
	FILE* f_login_parol;
	printf("�����������:\n");
	struct user user1;
	fopen_s(&f_login_parol, "Login_parol.bin", "a+");
	cout << "������� ����� ��������:\n";
	cin >> login;
	while (true) {
		if (!f_login_parol) {
			cout << "�����" << endl;
			return NULL;
		}
		fseek(f_login_parol, sizeof(user) * i, 0);
		if (!fread(&user1, sizeof(user), 1, f_login_parol))
			break;
		if (strcmp(user1.login, login) == 0) {
			cout << "����� ����� �������� ��� ������������\n";
			fclose(f_login_parol);
			return NULL;
		}
		i++;
	}
	strcpy_s(user1.login, login);
	printf("������� ������\n");
	cin >> user1.parol;
	user1.acces = 1;
	fclose(f_login_parol);
	fopen_s(&f_login_parol, "Login_parol.bin", "a+");
	if (!f_login_parol) {
		cout << "�����" << endl;
		return NULL;
	}
	fwrite(&user1, sizeof(user), 1, f_login_parol);
	fclose(f_login_parol);
}

int autorization(char login[30])
{   FILE* f_login_parol;
    int i = 0;
	struct user user1;
	bool d = false;
	char parol[10];
	fopen_s(&f_login_parol, "Login_parol.bin", "a+");
	while (true) {
		if (!f_login_parol) {
			cout << "�����" << endl;
			return NULL;
		}
		fseek(f_login_parol, sizeof(user) * i, 0);
		if (!fread(&user1, sizeof(user), 1, f_login_parol))
			break;
		if (strcmp(user1.login, login) == 0) {
			d = true;
			break;
		}
		i++;
	}
	if (!d) {
		cout << "������ ����� �������� �� ���������������\n";
		return 0;
	}
	else {
		cout << "������� ������:\n";
		cin >> parol;
		if (strcmp(user1.parol, parol) == 0) {
			cout << "�� ������� ����� � �������!\n";
			return user1.acces;
		}
		else { cout << "�������� ������!\n"; return NULL; }
	}
	fclose(f_login_parol);
}
