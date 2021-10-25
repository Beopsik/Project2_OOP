#include "inf_int.h"

// 
// to be filled by students
//
// example :
//
// bool operator==(const inf_int& a , const inf_int& b)
// {
//     // we assume 0 is always positive.
//     if ( (strcmp(a.digits , b.digits)==0) && a.thesign==b.thesign )
//         return true;
//     return false;
// }
//

inf_int::inf_int() {		// assign 0 as a default value
	this->digits = "0";
	this->length = 1;
	this->thesign = true;
}
inf_int::inf_int(int integer) {
	if (integer < 0) {
		this->thesign = false;
		integer = -integer;
	}
	else 
		this->thesign = true;

	this->digits = to_string(integer);
	this->length = to_string(integer).length();
}
inf_int::inf_int(const string integer) {
	if (integer.front() == '-') {
		this->thesign = false;
		this->digits=integer.substr(1);
	}
	else {
		this->thesign = true;
		this->digits = integer;
	}
	this->length = integer.length();
}
inf_int::inf_int(const inf_int& integer) {
	this->digits = integer.digits;
	this->length = integer.length;
	this->thesign = integer.thesign;
}
inf_int::~inf_int() {

}

inf_int operator+(const inf_int& integer1, const inf_int& integer2) {
	string resultDigits;
	unsigned int resultLength;
	bool resultTheSign;

	if (integer1.thesign == true && integer2.thesign == false) {

	}
	else if (integer1.thesign == false && integer2.thesign == true) {

	}
	else {

	}

	return integer1;
}
inf_int operator-(const inf_int& integer1, const inf_int& integer2) {
	return integer1;
}
inf_int operator*(const inf_int& integer1, const inf_int& integer2) {
	return integer1;
}

string inf_int::tenComplement(const string integer, const int integerLength) {
	string tenComp = "10";
	for(int i=integerLength; i>1; i--)
		tenComp.append("0");

	string resultReversed = "";
	int borrow = 0;
	for (int i = tenComp.length() - 1; i > 0; i--) {
		int tenCompNum = tenComp[i]-'0'+ borrow;
		int integerNum = integer[i - 1] - '0';

		if (tenCompNum < integerNum) {
			borrow = -1;
			tenCompNum += 10;
		}

		resultReversed.append(to_string(tenCompNum-integerNum));
	}

	string result = "";
	while (!resultReversed.empty()) {
		result.push_back(resultReversed.back());
		resultReversed.pop_back();
	}

	return result;
}