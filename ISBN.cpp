//Guang Hui Liew Rakuten Coding Challenge
#include <iostream>
using namespace std;

bool isValidproductID(string);

int main()
{
	string productID;
	do {
		string ISBN = "0000000000";
		do {
			cout << "Please enter a 12 digits product ID\n";
			cin >> productID;
		} while (!isValidproductID(productID));

		for (int i = 0; i < 9; i++)
		{
			ISBN[i] = productID[i + 3];
		}

		int sum = 0;
		for (int i = 0; i < 10; i++)
		{
			int digit = ISBN[i] - '0';
			sum += digit * (10 - i);
		}
		int errorCode = 11 - (sum % 11);
		if (errorCode == 10)
		{
			ISBN[9] = 'X';
		}
		else if (errorCode == 11)
		{
		}
		else
		{
			char error = '0' + errorCode;
			ISBN[9] = error;
		}
		cout << "The ISBN is " << ISBN << "\n\n";
	} while (true);
}

bool isValidproductID(string prodID)
{
	if (prodID.length() != 12)
		return false;
	for (int i = 0; i < 11; i++)
	{
		int digit = prodID[i] - '0';
		if (0 > digit || 9 < digit)
			return false;
	}
	return true;
}
