#include <iostream>
#include <string>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	string phrase;
	int step, size, choice;
	cout << "Введите вашу фразу на АНГЛИЙСКОМ языке: ";
	getline(cin, phrase);
	size = (int)phrase.length();
	cout << "Введите шаг шифрования (целое положительное число): ";
	cin >> step;
	cout << "Что вы хотите сделать? Чтобы зашифровать, нажмите 1. Чтобы расшифровать, нажмите 2: ";
	cin >> choice;
	cout << endl;

	// зашифровка
	if (choice == 1)
	{
		for (int i = 0; i < size; i++)
		{
			if (isalpha(phrase[i]))
			{
				for (int j = 0; j < step; j++)
				{
					if (phrase[i] == 'z')
					{
						phrase[i] = 'a';
					}
					else
					{
						phrase[i]++;
					}
				}
			}
		}
		cout << "Ваша зашифрованная фраза: " << endl;
		cout << phrase << endl;
		cout << endl;
	}

	// расшифровка
	else if (choice == 2)
	{
		for (int i = 0; i < size; i++)
		{
			if (isalpha(phrase[i]))
			{
				for (int j = 0; j < step; j++)
				{
					if (phrase[i] == 'a')
					{
						phrase[i] = 'z';
					}
					else
					{
						phrase[i]--;						
					}
				}
			}
		}
		cout << "Ваша расшифрованная фраза: " << endl;
		cout << phrase << endl;
		cout << endl;
	}
	system("pause");
	return 0;
}
