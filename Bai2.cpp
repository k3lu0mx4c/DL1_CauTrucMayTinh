#include "Bai2.h"

Qfloat::Qfloat() {

}

Qfloat::~Qfloat() {
}

Qfloat Qfloat::operator=(Qfloat) {

}

string BinToDec(bool * bit)
{
	string str;// lưu số thực hệ số 10
	int phanNguyen = 0;
	bool dau = bit[0];
	for (int i = 15; i > 0; i--) {
		if(bit[i]  == 1)
			phanNguyen += pow(2, 15 - i) ;
	}
	int multi2[120] = { 0 };
	int decimal[120] = { 0 };
	multi2[119] = 1;
	int memo;
	for (int i = 16; i < 128; i++)
	{
		memo = 0;
		for (int j = 119; j >= 0; j--)
		{
			int temp = multi2[j];
			multi2[j] = (multi2[j] * 5 + memo) % 10;
			memo= (temp * 5 + memo) / 10;
		}
		if (bit[i] != 0) {
			memo = 0;
			int count = 119;
			for (int j = i-16; j >= 0; j--)
			{
				int d = decimal[j];
				decimal[j] = (decimal[j] + multi2[count] + memo) % 10;
				memo = (d + multi2[count] + memo) / 10;
				count--;
			}
		}
	}
	int index;
	for (index = 119; index >= 0; index--) {
		if (decimal[index] != 0)
			break;
	}
	while (phanNguyen != 0)
	{
		str = char(phanNguyen % 10 + 48) + str;
		phanNguyen /= 10;
	}
	str += ".";
	for (int i = 0; i <= index; i++)
	{
		str += char(decimal[i] + 48);
	}
	if (bit[0] == 1)
		str = "-" + str;
	else
		str = "+" + str;
	return str;
}

