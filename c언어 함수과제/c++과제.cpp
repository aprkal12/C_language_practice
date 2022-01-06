#include <iostream>
//#include <cstdlib>
//#include <ctime>
//#include <string>
//#include <ctime>
using namespace std;
//#include "oval.h"
// 2019. 12. 15 일요일 시험공부
// p.526 6번
template <class T1>
T1* rem(T1 sr[], T1 miu[], int srs, int mius, int& rs) {
	T1 *tem = new T1[srs + mius];
	for (int i = 0; i < srs; i++) {
		for (int j = 0; j < mius; j++) {
			if (sr[i] == miu[j]) {
				break;
			}
			else if(j == mius - 1) {
				tem[rs] = sr[i];
				rs++;
			}
		}
	}
	T1 *re = new T1[rs];
	for (int i = 0; i < rs; i++) {
		re[i] = tem[i];
	}
	if (rs == 0) {
		return 0;
	}
	else {
		return re;
	}
}
int main(void) {
	int x[] = { 1,2,3,4,5 };
	int y[] = { 1,2,3,7,8,9 };
	int rsi=0;
	cout << "뺄셈 결과 : ";
	int *re = rem(x, y, 5, 6, rsi); 
	for (int i = 0; i < rsi; i++) {
		cout << re[i] << ' ';
	}
	cout << endl;
}
// p.525 5번
/*template <class T1>
T1* ccat(T1 a[], T1 b[], int sa, int sb) {
	T1* re = new T1[sa + sb];
	for (int i = 0; i < sa; i++) {
		re[i] = a[i];
	}
	for (int i = 0; i < sb; i++) {
		re[sa + i] = b[i];
	}
	return re;
}
int main(void) {
	int a[] = { 1,2,3,4 };
	int b[] = { 5,6,7 };
	char ca[] = { 'h','e','l','l','o' };
	char cb[] = { 'w','o','r','l','d','!' };
	int *re = ccat(a, b, 4, 3);
	char* cre = ccat(ca, cb, 5, 6);
	cout << "합체 결과 : ";
	for (int i = 0; i < 7; i++) {
		cout << re[i] << ' ';
	}
	cout << endl;
	cout << "합체 결과 : ";
	for (int i = 0; i < 11; i++) {
		cout << cre[i] << ' ';
	}
	cout << endl;
}*/
// p.525 4번
/*template <class T1>
bool ser(T1 tar, T1 a[], int c) {
	for (int i = 0; i < c; i++) {
		if (a[i] == tar) {
			return true;
		}
	}
	return false;
}
int main(void) {
	int x[] = { 1,10,100,5,4 };
	if (ser(100, x, 5)) {
		cout << "100이 배열x에 포함되어있다.";
	}
	else {
		cout << "100이 배열x안에 없다";
	}
	cout << endl;
}*/
// p.525 3번
/*template <class T1>
void ra(T1 a[], int c) {
	T1 *tem = new int[c];
	for (int i = 0; i < c; i++) {
		tem[i] = a[c - i - 1];
	}
	for (int i = 0; i < c; i++) {
		a[i] = tem[i];
	}
}
int main(void) {
	int x[] = { 1,10,100,5,4 };
	ra(x, 5);
	for (int i = 0; i < 5; i++) {
		cout << x[i] << ' ';
	}
	cout << endl;
}*/
// p. 525 2번
/*template <class T1>
bool ea(T1 a[], T1 b[],int s) {
	for (int i = 0; i < s; i++) {
		if (a[i] != b[i]) {
			return false;
		}
	}
	return true;
}
int main(void) {
	int x[] = { 1, 10, 100, 5, 4 };
	int y[] = { 1,10,100,5,4 };
	if (ea(x, y, 5)) {
		cout << "같다." << endl;
	}
	else {
		cout << "다르다" << endl;
	}
}*/
// p.525 10장 1번
/*template <class T1>
T1 bigge(T1 a[],int c) {
	T1 tar=0;
	for (int i = 0; i < c; i++) {
		if (a[i] > tar) {
			tar = a[i];
		}
	}
	return tar;
}
int main(void) {
	int x[] = { 1, 10 , 100, 5, 4 };
	double y[] = { 1.0, 4.3, 12.3, 128.2, 65.4 };
	char z[] = { 'g','h','w','a','u' };
	cout << bigge(x, 5) << endl;
	cout << bigge(y, 5) << endl;
	cout << bigge(z, 5) << endl;
	
}*/
// p.372 12번 복습필요
/*class soa {
	int size;
	int* p;
	void sort();
public:
	soa() {
		p = NULL;
		size = 0;
	}
	soa(int p[], int size) {
		this->size = size;
		this->p = new int [size];
		for (int i = 0; i < size; i++) {
			this->p[i] = p[i];
		}
	}
	soa(soa& src) {
		this->size = src.size;
		this->p = new int[src.size];
		for (int i = 0; i < src.size; i++) {
			this->p[i] = src.p[i];
		}
	}
	~soa() {
		if (p) {
			delete[] this->p;
		}
		
	}
	soa operator +(soa& op2) {
		soa re;
		//int co = this->size + op2.size;
		//cout << co << endl;
		re.p = new int[this->size+op2.size];
		re.size = this->size + op2.size;
		for (int i = 0; i < this->size; i++) {
			re.p[i] = this->p[i];

		}
		for (int i = 0; i < op2.size; i++) {
			re.p[this->size+i] = op2.p[i];
		}
		
		return re;
	}
	soa& operator = (const soa& op2) {
		delete[] this->p;
		this->p = new int[op2.size];
		this->size = op2.size;
		for (int i = 0; i < op2.size; i++) {
			this->p[i] = op2.p[i];
		}
		
		return *this;
	}
	void show() {
		sort();
		cout << "배열 출력 : ";
		for (int i = 0; i < this->size; i++) {
			cout << this->p[i] << ' ';
		}
		cout << endl;
	}
};
void soa :: sort() {
	int tem;
	for (int i = 0; i < size; i++) {
		for (int j = 1; j < size - i; j++) {
			if (this->p[j-1] > this->p[j]) {
				tem = this->p[j-1];
				this->p[j-1] = this->p[j];
				this->p[j] = tem;
			}
		}
	}
}
int main(void) {
	int n[] = { 2, 20, 6 };
	int m[] = { 10, 7, 8, 30 };
	soa a(n, 3), b(m, 4), c;

	c = a + b;

	a.show();
	b.show();
	c.show();
}*/
// p.371 11번
/*class stack {
	int* d;
	int cur;
public:
	stack(){
		d = new int[100];
		cur = 0;
	}
	bool operator ! () {
		if (cur == 0) {
			return true;
		}
		else {
			return false;
		}
	}
	int operator >> (int& a) {
		cur--;
		a = this->d[cur];
		return a;
	}
	stack& operator << (int a) {
		this->d[cur] = a;
		cur++;
		return *this;
	}
};
int main(void) {
	stack st;
	st << 3 << 5 << 10;
	while (true) {
		if (!st) {
			cout << endl;
			break;
		}
		int x;
		st >> x;
		cout << x << ' ';
	}
}*/
// p.370 10번
/*class sta {
	int *stac;
	int cur;
public:
	sta() {
		stac = new int[100];
		cur = 0;
	}
	bool operator ! () {
		if (cur == 0) {
			return true;
		}
		else {
			return false;
		}
	}
	sta& operator << (int a) {
		this->stac[cur] = a;
		cur++;
		return *this;
	}
	void operator ~ () {
		for (int i = 0; i < cur; i++) {
			cout << this->stac[i] << ' ';
		}
		cout << endl;
	}
	int operator >> (int& re) {
		int sum = 0;
		for (int i = 0; i < cur; i++) {
			sum += this->stac[i];
		}
		re = sum / cur;
		return re;
	}
};
int main(void) {
	sta stat;
	if (!stat) {
		cout << "현재 통계 데이터가 없습니다." << endl;
	}
	int x[5];
	cout << "5개의 정수를 입력하세요 : ";
	for (int i = 0; i < 5; i++) {
		cin >> x[i];
	}

	for (int i = 0; i < 5; i++) {
		stat << x[i];
	}
	stat << 100 << 200;
	~stat;

	int avg = 0;
	stat >> avg;
	cout << "avg = " << avg << endl;
}*/
// p.370 9번
/*class cir {
	int r;
public:
	cir(int r = 0) {
		this->r = r;
	}
	void show() {
		cout << "radius = " << r << " 인 원" << endl;
	}
	cir& operator ++() {
		this->r += 1;
		return *this;
	}
	cir operator ++(int a) {
		cir tem;
		tem.r = this->r;
		this->r += 1;
		return tem;
	}
	friend cir operator +(int a, cir b);
};
cir operator + (int a, cir b) {
	cir tem;
	tem.r = a + b.r;
	return tem;
}
int main(void) {
	cir a(5), b(4);
	b = 1 + a;
	a.show();
	b.show();
}*/
// p.369 8번
/*class cir {
	int r;
public:
	cir(int r = 0) {
		this->r = r;
	}
	void show() {
		cout << "radius = " << r << " 인 원" << endl;
	}
	cir& operator ++() {
		this->r += 1;
		return *this;
	}
	cir operator ++(int a) {
		cir tem;
		tem.r = this->r;
		this->r += 1;
		return tem;
	}
};
int main(void) {
	cir a(5), b(4);
	++a;
	b = a++;
	a.show();
	b.show();
}
*/
// p.369 7번
/*class mat {
	int a, b, c, d;
public:
	mat(int a = 0, int b = 0, int c = 0, int d = 0) {
		this->a = a;
		this->b = b;
		this->c = c;
		this->d = d;
	}
	// friend int* operator >> (mat a, int x[]);
	int* operator >> (int x[]) {
		x[0] = this->a;
		x[1] = this->b;
		x[2] = this->c;
		x[3] = this->d;
		return x;
	}
	// friend mat& operator << (mat a, int y[]);
	mat& operator << (int y[]) {
		this->a = y[0];
		this->b = y[1];
		this -> c = y[2];
		this->d = y[3];
		return *this;
	}
	void show() {
		cout << "matrix = { " << a << ' ' << b << ' ' << c << ' ' << d << ' ' << "}" << endl;
	}
};
int main(void) {
	mat a(4,3,2,1), b;
	int x[4], y[4] = { 1,2,3,4 };
	a >> x;
	b << y;
	for (int i = 0; i < 4; i++) {
		cout << x[i] << ' ';
	}
	cout << endl;
	b.show();
}*/
// p.368 6번
/*class mat {
	int a, b, c, d;
public:
	mat(int a=0, int b=0, int c=0, int d=0) {
		this->a = a;
		this->b = b;
		this->c = c;
		this->d = d;
	}
	// friend mat operator + (mat a, mat b);
	mat operator + (mat b) {
		mat re;
		re.a = this->a + b.a;
		re.b = this->b + b.b;
		re.c = this->c + b.c;
		re.d = this->d + b.d;
		return re;
	}
	// friend mat& operator += (mat a, mat b);
	mat& operator +=(mat b) {
		this->a += b.a;
		this->b += b.b;
		this->c += b.c;
		this->d += b.d;
		return *this;
	}
	void show() {
		cout << "matrix = { " << a << ' ' << b << ' ' << c << ' ' << d << ' ' << "}" << endl;
	}
	// friend bool operator == (mat a, mat b);
	bool operator ==(mat b) {
		if (((this->a == b.a) && (this->b == b.b)) && ((this->c == b.c) && (this->d == b.d))) {
			return true;
		}
		else {
			return false;
		}
	}
};
int main(void) {
	mat a(1, 2, 3, 4), b(2, 3, 4, 5), c;
	c = a + b;
	a += b;
	a.show();
	b.show();
	c.show();
	if (a == c) {
		cout << "a and c are the same" << endl;
	}
}*/
// 2019.12.14 토 c++ 시험공부
// p.368 5번
/*class co {
	int r, g, b;
public:
	co(int r = 0, int g = 0, int b = 0) {
		this->r = r;
		this->g = g;
		this->b = b;
	}
	void show() {
		cout << r << ' ' << g << ' ' << b << endl;
	}
	//friend co operator +(co a, co b);
	co operator +(co b) {
		co re;
		re.r = this->r + b.r;
		re.g = this->g + b.g;
		re.b = this->b + b.b;
		if (re.r > 255) {
			re.r = 255;
		}
		if (re.g > 255) {
			re.g = 255;
		}
		if (re.b > 255) {
			re.b = 255;
		}
		return re;
	}
	// friend bool operator ==(co a,co t);
	bool operator ==(co t) {
		if (((this->r == t.r) && (this->g == t.g)) && (this->b == t.b)) {
			return true;
		}
		else {
			return false;
		}
	}
};
int main(void) {
	co red(255, 0, 0), blue(0, 0, 255), c;
	c = red + blue;
	c.show();

	co fu(255, 0, 255);
	if (c == fu) {
		cout << "보라색 맞음" << endl;
	}
	else {
		cout << "보라색 아님" << endl;
	}
}*/
// 7장 p.368 4번
/*class book {
	string ti;
	int pri, pa;
public:
	book(string ti = "", int pri = 0, int pa = 0) {
		this->ti = ti;
		this -> pri = pri;
		this->pa = pa;
	}
	void show() {
		cout << ti << ' ' << pri << "원 " << pa << " 페이지" << endl;
	}
	string gti() {
		return ti;
	}
	friend bool operator <(string n1, book n2);
};
bool operator < (string n1,book n2) {
	int i = 0;
	if (n1 < n2.ti) {
		return true;
	}
	else {
		return false;
	}
}
int main(void) {
	book a("청춘", 20000, 300);
	string b;
	cout << "책 이름 입력 : ";
	getline(cin, b);
	if (b < a) {
		cout << a.gti() << "이 " << b << " 보다 뒤에 있구나 !" << endl;
	}
}*/
// p.317 9번
/*class bor {
	static int co;
	static string* noti;
public:
	static void add(string word) {
		noti[co++] = word;
	}
	static void print() {
		cout << "********** 게시판 입니다. **********" << endl;
		for (int i = 0; i < co; i++) {
			cout << i << ':' << noti[i] << endl;
		}
		cout << endl;
	}
};
int bor::co = 0;
string* bor::noti = new string[100];
int main(void) {
	bor::add("중간고사는 감독 없는 자율 시험입니다.");
	bor::add("코딩 라운지 많이 이용해 주세요");
	bor::print();
	bor::add("진소린 학생이 경진대회 입상하였습니다. 축하해주세요.");
	bor::print();
}*/
// p.316 8번
/*class trace {
	static string *t, *san;
	static int num;
public:
	static void put(string a, string b) {
		t[num] = a;
		san[num] = b;
		num++;
	}
	static void print(string a="all") {
		if (a == "all") {
			cout << "--------- 모든 trace 정보를 출력합니다. ---------" << endl;
			for (int i = 0; i < num; i++) {
				cout << t[i] << ":" << san[i] << endl;
			}
		}
		else {
			cout << "--------- " << a << "태그의 trace 정보를 출력합니다. ---------" << endl;
			for (int i = 0; i < num; i++) {
				if (t[i] == a) {
					cout << t[i] << ":" << san[i] << endl;
				}
			}
		}
	}
};
int trace::num = 0;
string* trace::t = new string[100];
string * trace::san = new string[100];
void f() {
	int a, b, c;
	cout << "두개의 정수를 입력하세요 : ";
	cin >> a >> b;
	trace::put("f()", "정수를 입력받았음");
	c = a + b;
	trace::put("f()", "합 계산");
	cout << "합은 " << c << endl;
}
int main(void) {
	trace::put("main()", "프로그램 시작합니다.");
	f();
	trace::put("main()", "종료");

	trace::print("f()");
	trace::print();
}*/
// p.316 7번
/*class ran {
public:
	static void seed() { srand((unsigned)time(NULL)); }
	static int nint(int m = 0, int M = 32767) { return (rand() % M) + m; }
	static char nal() {
		int j = rand() % 2;
		if (j == 0) {
			return rand() % (90-65) + 65;;
		}
		else {
			return rand() % (122-97) + 97;
		}
	}
	static double ndo() {
		double re = rand() / double(RAND_MAX+1);
		return re;
	}
};
int main(void) {
	ran::seed();
	cout << "1에서 100까지의 랜덤한 정수 10개를 출력합니다." << endl;
	for (int i = 0; i < 10; i++) {
		cout << ran::nint(1, 100) << ' ';
	}
	cout << "\n알파벳 랜덤 10개를 출력합니다." << endl;
	for (int i = 0; i < 10; i++) {
		cout << ran::nal() << ' ';
	}
	cout << "\n10개 실수를  출력합니다." << endl;
	for (int i = 0; i < 10; i++) {
		cout << ran::ndo() << ' ';
	}

}*/
// 2019.12.11 수 C++ 시험공부
// ppt 6장

// 책 153 실습 9번
/*int main(void) {
	oval a, b(3, 4);
	a.set(10, 20);
	a.show();
	cout << b.getw() << "," << b.geth() << endl;
}*/
// 책 153 실습 8번
/*class integer {
	int tar;
public:
	string star;
	integer(int a);
	integer(string b);
	int get();
	void set(int c);
	bool iseven();
};
inline integer::integer(int a) {
	tar = a;
}
inline integer::integer(string b) {
	star = b;
	tar = stoi(star);
}
inline void integer::set(int c) {
	tar = c;
}
inline int integer :: get() {
	return tar;
}
inline bool integer::iseven() {
	if (tar % 2 == 0) {
		return true;
	}
	else {
		return false;
	}
}
int main(void) {
	integer n(30);
	cout << n.get() << ' ';
	n.set(50);
	cout << n.get() << ' ';

	integer m("300");
	cout << m.get() << ' ';
	cout << m.iseven();
}*/
// 책 152 실습 7번
/*class selrandom {
	int evc = 0;
	int select;
public:
	selrandom(int sel);
	int next();
	int nextin(int a, int b);
};
selrandom::selrandom(int sel) {
	select = sel;
}
int selrandom::next() {
	int c = 0;
	if (select == 0) {
		while (c < 10) {
			int evc = rand();
			if (evc % 2 == 0) {
				c++;
				return evc;
			}
		}
	}
	else if (select == 1) {
		while (c < 10) {
			int evc = rand();
			if (evc % 2 != 0) {
				c++;
				return evc;
			}
		}
	}
}
int selrandom::nextin(int a, int b) {
	int c = 0;
	if (select == 0) {
		while (c < 10) {
			int evc = rand() % (b - a + 1) + a;
			if (evc % 2 == 0) {
				c++;
				return evc;
			}
		}
	}
	else if (select == 1) {
		while (c < 10) {
			int evc = rand() % (b - a + 1) + a;
			if (evc % 2 != 0) {
				c++;
				return evc;
			}
		}
	}
}
int main(void) {
	srand((unsigned)time(NULL));
	selrandom r(0);
	selrandom ra(1);
	cout << "--- 0에서 " << RAND_MAX << "까지의 랜덤 정수 10개 ---" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.next();
		cout << n << " ";
	}
	cout << endl << endl << "--- 2에서 " << "10 까지의 랜덤 정수 10개 ---" << endl;
	for (int i = 0; i < 10; i++) {
		int n = ra.nextin(2, 10);
		cout << n << " ";
	}
	cout << endl;
}*/
// 책 152 실습 6번
/*class evrandom {
	int evc = 0;
public:
	evrandom();
	int next();
	int nextin(int a, int b);
};
evrandom::evrandom() {

}
int evrandom::next() {
	int c = 0;
	while (c < 10) {
		int evc = rand();
		if (evc % 2 == 0) {
			c++;
			return evc;
		}
	}
}
int evrandom::nextin(int a, int b) {
	int c = 0;
	while (c < 10) {
		int evc = rand() % (b - a + 1) + a;
		if (evc % 2 == 0) {
			c++;
			return evc;
		}
	}
}
int main(void) {
	srand((unsigned)time(NULL));
	evrandom r;
	cout << "--- 0에서 " << RAND_MAX << "까지의 랜덤 정수 10개 ---" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.next();
		cout << n << " ";
	}
	cout << endl << endl << "--- 2에서 " << "10 까지의 랜덤 정수 10개 ---" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.nextin(2, 10);
		cout << n << " ";
	}
	cout << endl;
} */
// 책 151 실습 5번
/*class random{
public:
	random();
	int next();
	int nextin(int a, int b);
};
random::random() {

}
int random::next() {
	return rand();
}
int random::nextin(int a, int b) {
	return rand() % (b - a + 1) + a;
}

int main(void) {
	srand((unsigned)time(NULL));
	random r;
	cout << "--- 0에서 " << RAND_MAX << "까지의 랜덤 정수 10개 ---" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.next();
		cout << n << " ";
	}
	cout << endl << endl << "--- 2에서 " << "4 까지의 랜덤 정수 10개 ---" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.nextin(2, 4);
		cout << n << " ";
	}
	cout << endl;
}*/
// 책 151 실습 4번
/*class CM {
	int coffee,water,suger;
public:
	CM(int a, int b, int c);
	void des();
	void dam();
	void dsu();
	void show();
	void fill();
};
CM::CM(int a, int b, int c) {
	coffee = a;
	water = b;
	suger = c;
}
void CM::des() {
	coffee -= 1;
	water -= 1;
}
void CM::dam() {
	coffee -= 1;
	water -= 2;
}
void CM::dsu() {
	coffee -= 1;
	water -= 2;
	suger -= 1;
}
void CM::show() {
	cout << "커피 머신 상태, 커피:" << coffee << "    물:" << water << "   설탕:" << suger << endl;
}
void CM::fill() {
	coffee = 10;
	water = 10;
	suger = 10;
}
int main(void) {
	CM java(5, 10, 3);
	java.des();
	java.show();
	java.dam();
	java.show();
	java.dsu();
	java.show();
	java.fill();
	java.show();
}*/
// 책 150 실습 3번
/*class Account {
private:
	string name;
	int id;
	int money;
public:
	Account(string n, int i, int m);
	int deposit(int add);
	int withdraw(int sub);
	string geta();
	int inquiry();
};
Account::Account(string n, int i, int m) {
	name = n;
	id = i;
	money = m;
}
int Account :: deposit(int add) {
	return money += add;
}
int Account::withdraw(int sub) {
	return money -= sub;
}
string Account::geta() {
	return name;
}
int Account::inquiry() {
	return money;
}
int main(void) {
	Account a("Kitae", 1, 5000);
	a.deposit(50000);
	cout << a.geta() << "의 잔액은 " << a.inquiry() << endl;
	int money = a.withdraw(20000);
	cout << a.geta() << "의 잔액은 " << a.inquiry() << endl;
}*/
// 책 150 실습 2번
/*class Date {
private:
	int iny, inm, ind;
	int by, bm, bd;
	int del,nex;
	string tar;
public:
	Date(int a, int b, int c);
	Date(string a);
	void show();
	int gety(), getm(), getd();
};
Date::Date(int a,int b,int c) {
	by = a;
	bm = b;
	bd = c;
}
Date::Date(string a) {
	// "1945/8/15" 입력됨
	del = a.find("/");
	tar = a.substr(0, del);
	iny = stoi(tar);

	nex = a.find("/", del + 1);
	tar = a.substr(del+1, nex - del+1);
	inm = stoi(tar);

	del = a.find("/", nex + 1);
	tar = a.substr(nex + 1, del - nex+1);
	ind = stoi(tar);
}
void Date::show() {
	cout << iny << "년 " << inm << "월 " << ind << "일" << endl;
}
int Date::gety() {
	return by;
}
int Date::getm() {
	return bm;
}
int Date::getd() {
	return bd;
}
int main(void) {
	Date birth(2000, 2, 18);
	Date indi("1945/8/15");
	indi.show();
	cout << birth.gety() << ", " << birth.getm() << ", " << birth.getd() << endl;
}*/
// 책 149 실습 1번
/*class Tower {
private:
	int h;
public:
	Tower();
	Tower(int a);
	int geth();
};
Tower::Tower() : Tower(1) {}
Tower::Tower(int a) {
	h = a;
}
int Tower::geth() {
	return h;
}
int main(void) {
	Tower myTower;
	Tower seoulTower(100);
	cout << "높이는 " << myTower.geth() << "미터" << endl;
	cout << "높이는 " << seoulTower.geth() << "미터" << endl;
}*/
// 2장 실습 15번
/*int main(void) {
	char a[100];
	int i, sum = 0, j = 0;
	char op[100];
	int n1, n2;

	while (1) {
	cout << "? ";
	cin.getline(a, 100);
	for (i = 0; i < strlen(a); i++) {
		if (atoi(&a[i]) == 0) {
			op[j] = a[i];
		}
	}
	char* wow;
	n1 = atoi(strtok(a, " "));
	wow = strtok(NULL, " ");
	n2 = atoi(strtok(NULL, " "));
		if (op[j] == '+') {
			sum = n1 + n2;
		}
		else if (op[j] == '-') {
			sum = n1 - n2;
		}
		else if (op[j] == '*') {
			sum = n1 * n2;
		}
		else if (op[j] == '/') {
			sum = n1 / n2;
		}
		else if (op[j] == '%') {
			sum = n1 % n2;
		}
		else {
			cout << "올바르지 않은 수식 입력";
		}
		cout << n1 << " " << op[0] << " " << n2 << " = " << sum << endl;
	}
} */
