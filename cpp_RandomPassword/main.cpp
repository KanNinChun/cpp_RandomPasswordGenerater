#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>
#include <windows.h>
using namespace std;


static const char junk[] =
"ABCDEFGHIJKLMNOPQRSTVWXYZ"
"abcdefghijklmnopqrstvwxyz"
"0123456789"
"!@#$%^&*(+-/)";


int junkSize = sizeof(junk) - 1;

char GetRandomChar()
{
	return junk[rand() % junkSize];
}

int main(int arge, char* argv[])
{

	SetConsoleTitle(L"Password Generater");
	ofstream writer("Password.txt");


	while (true)
	{

		int passLength;
		int numberOfPassword;
		srand(time(NULL));//random seed
		string pass;

		cout << "Enter The Length Of Password" << endl;
		cin >> passLength;
		cout << "" << endl;
		cout << "How many password do you want" << endl;
		cin >> numberOfPassword;
		cout << "" << endl;


		for (int j = 0; j < numberOfPassword; j++)
		{
			for (int i = 0; i <= passLength - 1; i++)
			{
				pass += GetRandomChar();
			}
			writer << pass << endl;
			pass = "";
		}
	}
	writer.close();

	std::cin.get();
	return EXIT_SUCCESS;
}