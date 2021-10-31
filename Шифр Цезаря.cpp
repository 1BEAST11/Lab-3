#include <iostream>
#include <string>

using namespace std;

bool validName(string phrase)
{
	// не может быть введена пустая строка
	if (phrase.length() == 0)
	{
		return false; 
	}
	else
	{
		for (int i = 0; i < phrase.length(); i++)
		{
			// не может быть введено число
			if (phrase[i] >= '0' && phrase[i] <= '9')
			{
				return false; 
			}

			else
			{
				return true;
			}
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	string phrase;
	int step, size, choice;

	// ввод фразы
	cout << "Введите вашу фразу на АНГЛИЙСКОМ языке: ";
	getline(cin, phrase);

	// проверка корректности ввода фразы
	while (!validName(phrase))
	{
		cin.clear();
		cout << endl;
		cout << "Некорректный ввод.\n" << "Повторите попытку." << endl;
		cout << endl;
		cout << "Введите вашу фразу на АНГЛИЙСКОМ языке: ";
		getline(cin, phrase);
	}

	// ввод шага шифрования
	while (true) 
	{
		cout << "Введите шаг шифрования (целое положительное число от 1 до 25): ";
		cin >> step;

		// обработка ввода неверного типа данных
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << endl;
			cout << "Неверный тип данных.\n" << "Повторите попытку." << endl;
			cout << endl;
		}

		// обработка ввода числа, выходящего за пределы диапазона
		else if (step < 1 || step > 25)
		{
			cout << endl;
			cout << "Введено число, которое не входит в заданный диапазон.\n" << "Повторите попытку." << endl;
			cout << endl;
		}

		else
		{
			break;
		}
	}

	// выбор действия
	while (true) 
	{
		cout << "Чтобы зашифровать, нажмите 1. Чтобы расшифровать, нажмите 2: ";
		cin >> choice;

		// обработка ввода неверного типа данных
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << endl;
			cout << "Неверный тип данных.\n" << "Повторите попытку." << endl;
			cout << endl;
		}

		// обработка ввода неверного числа
		else if (choice != 1 && choice != 2)
		{
			cout << endl;
			cout << "Некорректный ввод.\n" << "Для выбора операции необходимо нажать 1 или 2." << endl;
			cout << endl;
		}

		else
		{
			break;
		}
	}
	
	size = (int)phrase.length();
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
					// последняя буква алфавита заменяется на первую
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
					// первая буква алфавита заменяется на последнюю
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
