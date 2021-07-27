// 10811 바구니 뒤집기
//#include<iostream>
//
//using namespace std;
//
//int n, m;
//int arr[102];
//
//void reverse(int arr[], int a, int b) {
//
//	int diff = (b - a)/2; //범위 처리... 왜지
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

// 1152 단어의 개수
//#include<iostream>
//#include<string>
//
//using namespace std;
//
//int cnt;
//
//int main() {
//	string abc;
//	getline(cin, abc); // 공백 포함 문자열 입력받기
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

// 2577 숫자의 개수
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

// 2846 오르막길
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
//			total += up; // total에 매칸마다 올라가는 높이를 덧셈해준다
//			if (total > maxUp) maxUp = total;
//
//		}
//		else // 만약 오르막길이 아니라면 오르막길 길이 재기를 끝내야 하므로 total을 초기화 시켜준다.
//			total = 0;
//	}
//	cout << maxUp;
//}

// 2920 음계
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
// 방법을 찾을려고만 하지 말고 만들어보자.
// 계속 증가하는 것의 특징이 뭔지.

// 1547 공
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