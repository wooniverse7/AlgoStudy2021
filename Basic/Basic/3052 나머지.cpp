//#include<iostream>
//using namespace std;
//
//int arr[10];
//
//int main() {
//	int cnt = 10;
//	for (int i = 0; i < 10; i++)
//	{
//		cin >> arr[i];
//		arr[i] = arr[i] % 42;
//	}
//	for (int i = 0; i < 10; i++) {
//		if (arr[i] == -1)
//			continue;
//		for (int j = i+1; j < 10; j++) {
//			if (arr[i] == arr[j]) {
//				cnt--;
//				arr[j] = -1;
//			}
//		}
//	}
//	cout << cnt;
//}

// ������ 42���� �� �� �ִ� �迭�� ����� 0���� �ʱ�ȭ �� ó�� �Է� �� count 1�� �߰�
// �� �������� ���� �������� pass, �ٸ��� ī��Ʈ �߰�

#include<iostream>
using namespace std;
int main() {
	int l[42]{ 0 };
	int ans = 0;
	for (int i = 0; i < 10; i++) {
		int a;
		cin >> a;
		if (l[a % 42] == 0) {
			ans++;
			l[a % 42] = 1;
		}
	}
	cout << ans;
}