#include <iostream>
#include "oval.h"
using namespace std;
oval::oval() {
	wi = 1, hei = 1;
}
oval::oval(int w, int h) {
	wi = w, hei = h;
}
oval::~oval() {
	cout << "oval ¼Ò¸ê : " <<"width = " << wi << ", height = " << hei << endl;
}
int oval::getw() {
	return wi;
}
int oval::geth() {
	return hei;
}
void oval::set(int wit, int he) {
	wi = wit;
	hei = he;
}
void oval::show() {
	cout << "width = " << wi << ", height = " << hei << endl;
}