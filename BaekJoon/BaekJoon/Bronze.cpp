// 10811 �ٱ��� ������
//#include<iostream>
//
//using namespace std;
//
//int n, m;
//int arr[102];
//
//void reverse(int arr[], int a, int b) {
//
//	int diff = (b - a)/2; //���� ó��... ����
//
//	for (int i = 0; i <= diff; i++) {
//		swap(arr[a + i], arr[b - i]);
//		if (a + i > b - i)
//			break;
//	}
//}
//
//int main() {
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++) {
//		arr[i] = i;
//	}
//
//	for (int i = 0; i < m; i++)
//	{
//		int a = 0, b = 0;
//		cin >> a >> b;
//		reverse(arr, a, b);
//	}
//
//	for (int i = 1; i <= n; i++)
//	{
//		cout << arr[i] << " ";
//	}
//}

// 1152 �ܾ��� ����
//#include<iostream>
//#include<string>
//
//using namespace std;
//
//int cnt;
//
//int main() {
//	string abc;
//	getline(cin, abc); // ���� ���� ���ڿ� �Է¹ޱ�
//
//	for (int i = 0; i < abc.size(); i++) {
//		if (i == 0) {
//			if (abc[i] == ' ')
//				cnt--;
//		}
//		if (abc[i] == ' ')
//		{
//			if (abc[i + 1] == NULL)
//				continue;
//			else
//				cnt++;
//		}
//	}
//
//	cout << cnt + 1;
//}

// 2577 ������ ����
//#include<iostream>
//#include<string>
//
//using namespace std;
//
//int a, b, c, sum;
//string num = "0123456789";
//
//
//int main() {
//	cin >> a >> b >> c;
//	sum = a * b * c;
//	string s = to_string(sum);
//
//	for (int i = 0; i < 10; i++) {
//		int cnt = 0;
//		for (int j = 0; j < s.size(); j++) {
//			if (num[i] == s[j]) {
//				cnt++;
//			}
//		}
//		cout << cnt << '\n';
//	}
//
//}

// 2846 ��������
//#include<iostream>
//
//using namespace std;
//
//int n;
//int arr[1002];
//int maxUp, up, total;
//
//int main() {
//
//	cin >> n;
//
//	for (int i = 0; i < n; i++)
//	{
//		cin >> arr[i];
//	}
//
//	for (int i = 0; i < n - 1; i++)
//	{
//		if (arr[i] < arr[i + 1]) {
//			up = arr[i + 1] - arr[i];
//			total += up; // total�� ��ĭ���� �ö󰡴� ���̸� �������ش�
//			if (total > maxUp) maxUp = total;
//
//		}
//		else // ���� ���������� �ƴ϶�� �������� ���� ��⸦ ������ �ϹǷ� total�� �ʱ�ȭ �����ش�.
//			total = 0;
//	}
//	cout << maxUp;
//}

// 2920 ����
//#include<iostream>
//
//using namespace std;
//
//int a[9];
//int as, ds;
//int main() {
//	for (int i = 0; i < 8; i++)
//	{
//		cin >> a[i];
//	}
//	for (int i = 0; i < 7; i++)
//	{
//		if (a[i] < a[i + 1])
//			as++;
//		if (a[i] > a[i + 1])
//			ds++;
//	}
//	if (as == 7)
//		cout << "ascending" << '\n';
//	else if (ds == 7)
//		cout << "descending" << '\n';
//	else
//		cout << "mixed" << '\n';
//
//}
// ����� ã������ ���� ���� ������.
// ��� �����ϴ� ���� Ư¡�� ����.

// 1547 ��
//#include<iostream>
//
//using namespace std;
//
//int m;
//int arr[4];
//
//int main() {
//	cin >> m;
//	arr[1] = 1;
//
//	for (int i = 0; i < m; i++) {
//		int a, b;
//		cin >> a >> b;
//		swap(arr[a], arr[b]);
//	}
//	for (int i = 1; i <= 3; i++)
//	{
//		//cout << arr[i] << " ";
//		if (arr[i] == 1) {
//			cout << i;
//			break;
//		}
//	}
//}