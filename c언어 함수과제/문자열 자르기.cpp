#include <iostream>
#include <string>
#include <cstring>
using namespace std;
/* class str {
	int w, st=0,n=0;
	int ar[3],i=0;
	string nex;
public:
	str(string a);
	void show();
};
str::str(string a) {
	while (w != -1) {
		w = a.find("/",st);
		nex = a.substr(st, w-n);
		st = w + 1;
		n = w + 1;
		ar[i++] = stoi(nex);
	}
}
void str::show() {
	cout << ar[0] << "�� " << ar[1] << "�� " << ar[2] << "�� ";
}
int main(void) {
	str a("2000/2/18");
	a.show();
} */
/*int main(void) {
	string a,f,r;
	int st = 0, ind = 0;
	cout << "�������� ���ڿ��� �Է��ϼ��� �� ���ڴ� &�Դϴ�." << endl;
	getline(cin, a,'&');
	cin.ignore();

	cout << "find : ";
	getline(cin, f);
	cout << "replace : ";
	getline(cin, r);

	while (1) {
		ind = a.find(f, st);
		if (ind == -1) {
			break;
		}
		a.replace(ind, f.length(), r);
		st = ind + r.length();
	}
	cout << a << endl;
}
*/
/*int main(void) {

	string a;
	string ne;
	int s = 0, in = 0;
	int sum = 0;
	cout << "7+23+5+100+25�� ���� ���ڿ��� �Է��Ͻÿ� " << endl;
	getline(cin, a);

	while (in != -1) {
		in = a.find('+', s);
		ne = a.substr(s, in - s);
		s = in + 1;

		sum += stoi(ne);
		cout << ne << endl;
	}
	cout << sum << endl;
}*/
int main(void) {
	char a[50];
	cout << "��й�ȣ�� �Է��ϼ���" << endl;
	while (1) {
		cin >> a;
		if (strcmp(a, "C++")==0) {
			cout << "���α׷� ��������" << endl;
			break;
		}
		else {
			cout << "��ȣ�� Ʋ����" << endl;
		}
	}
}