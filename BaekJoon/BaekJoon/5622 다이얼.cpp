//#include<iostream>
//#include<vector>
//#include<string>
//
//using namespace std;
//
////string abc[12] = { "0", "0", "0", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ", };
////int num[12] = { 0,0,1,2,3,4,5,6,7,8,9,0 };
//int sum;
//
//int main() {
//	string input;
//	cin >> input;
//
//	for (int i = 0; i < input.size(); i++) {
//		if (input[i] == 'A' || input[i] == 'B' || input[i] == 'C')
//			sum += 3;
//		else if (input[i] == 'D' || input[i] == 'E' || input[i] == 'F')
//			sum += 4;
//		else if (input[i] == 'G' || input[i] == 'H' || input[i] == 'I')
//			sum += 5;
//		else if (input[i] == 'J' || input[i] == 'K' || input[i] == 'L')
//			sum += 6;
//		else if (input[i] == 'M' || input[i] == 'N' || input[i] == 'O')
//			sum += 7;
//		else if (input[i] == 'P' || input[i] == 'Q' || input[i] == 'R' || input[i] == 'S')
//			sum += 8;
//		else if (input[i] == 'T' || input[i] == 'U' || input[i] == 'V')
//			sum += 9;
//		else
//			sum += 10;
//	}
//	cout << sum;
//}

#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main() {
	int num[28] = { 3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,8,9,9,9,10,10,10,10 };
	string abc;
	int sum = 0;

	cin >> abc;
	for (int i = 0; i < abc.size(); i++) {
		sum += num[abc[i] - 65];
	}
	cout << sum;
}