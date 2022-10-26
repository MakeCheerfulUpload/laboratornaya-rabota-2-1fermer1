#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[]) {
	
	while (1)
	{
		string code;
		cin >> code;
		setlocale(LC_ALL, "");
		if (code.size() != 7) {
			cout << "Должно быть 7-ми значное двоичное число\n\n";
			continue;
		}
		
		int size = 7;

		if (code == "stop" || code == "end") break;

		int* arr = new int[size];

		for (int i = 0; i < size; i++) {
			arr[i] = (code[i] - 48);
		}
		
		int erorrInd = arr[0] == ((arr[2] + arr[4] + arr[6]) % 2) ? 0 : 1;
		erorrInd += arr[1] == ((arr[2] + arr[5] + arr[6]) % 2) ? 0 : 2;
		erorrInd += arr[3] == ((arr[4] + arr[5] + arr[6]) % 2) ? 0 : 4;
		erorrInd--;
		if (erorrInd != 0) cout << "инвертируем " << (erorrInd + 1) << " символ\n";
		arr[erorrInd] = !arr[erorrInd];

		for (int i = 0; i < size; i++) cout << arr[i];

		cout << '\n' << arr[2] << arr[4] << arr[5] << arr[6] << "\n";
		cout << arr[2] * 8 + arr[4] * 4 + arr[5] * 2 + arr[6] << "\n\n";
	}

	cout << "Bye! Bye!\n";
	
	return 0;
}