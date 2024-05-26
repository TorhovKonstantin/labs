
#include <iostream>
using namespace std;

void tSwitcher(void)
{
	setlocale(0, "");
	int a, b;
	cout << "Vvedite znachenie peremennoj <a>: ";
	cin >> a;
	cout << "Vvedite znachenie peremennoj <b>: ";
	cin >> b;
	cout << endl;

	void obmen1(int , int );
	void obmen2(int*, int*);
	void obmen3(int&, int&);

	cout << "do obmena:\ta=" << a << "\tb=" << b << endl;
	obmen1(a, b);
	cout << "posle obmena 1:\ta=" << a << "\tb=" << b << endl;
	int* pa = &a;
	int* pb = &b;
	obmen2(pa, pb);
	cout << "posle obmena 2:\ta=" << a << "\tb=" << b << endl;
	int& aRef = a;
	int& bRef = b;
	obmen3(aRef, bRef);
	cout << "posle obmena 3:\ta=" << a << "\tb=" << b << endl;

}

void obmen1(int x, int y) {
	int bufX = x;
	int bufY = y;

	x = bufY;
	y = bufX;

	cout << "Vyzov funkcii obmen1 ne prinesyot rezultata, t.k. on ne mozhet izmenit peremennye iz-za nedostupnosti oblasti vidimosti." << endl;
}

void obmen2(int* x, int* y) {
	int bufX = *x;
	int bufY = *y;

	*x = bufY;
	*y = bufX;

	cout << "Vyzov funkcii obmen2 pomenyaet mestami znacheniya obrashayas napryamuyu k adresu pamyati, podmenyaya znachenie v nem." << endl;
}

void obmen3(int& x, int& y) {
	int bufX = x;
	int bufY = y;

	x = bufY;
	y = bufX;

	cout << "Vyzov funkcii obmen3 pomenyaet mestami znacheniya obrashayas k peremennoj po ssylke kotoraya ukazyvaet na ego adres v pamyati." << endl;
}

main() {
	tSwitcher();
}