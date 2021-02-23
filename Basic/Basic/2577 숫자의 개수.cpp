//#include<iostream>
//#include<string>
//using namespace std;
//
//int rst[10];
//
//int main() {
//	int a, b, c;
//	int mul;
//	cin >> a >> b >> c;
//	mul = a * b * c;
//
//	string num = to_string(mul); // 숫자가 string배열에 idx에 맞게 입력됨 (123 -> (1,2,3))
//
//	for (int i = 0; i < num.size(); i++) {
//		if (num[i] == '0') // num 배열은 문자열이라서 문자열로 비교해주어야 한다.
//			rst[0]++;
//		else if (num[i] == '1')
//			rst[1]++;
//		else if (num[i] == '2')
//			rst[2]++;
//		else if (num[i] == '3')
//			rst[3]++;
//		else if (num[i] == '4')
//			rst[4]++;
//		else if (num[i] == '5')
//			rst[5]++;
//		else if (num[i] == '6')
//			rst[6]++;
//		else if (num[i] == '7')
//			rst[7]++;
//		else if (num[i] == '8')
//			rst[8]++;
//		else if(num[i] == '9')
//			rst[9]++;
//	}
//
//	for (int i = 0; i < 10; i++) // 0 ~ 9 : 10개
//	{
//		cout << rst[i] << '\n';
//	}
//	
//	
//}

#include<iostream>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	int mul = a * b * c;

	int arr[10]{ 0 };

	while (mul) {
		arr[mul % 10]++;
		mul /= 10;
	}
	
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << '\n';
	}

}