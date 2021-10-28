#include "inf_int.h"
#include <algorithm>
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
  if(integer.at(0) == '-') {
	  this->digits = integer.substr(1, integer.size() - 1);
    this->length = integer.size() - 1;
    this->thesign = false;
  }
  else {
	  this->digits = integer;
    this->length = integer.size();
    this->thesign = true;
  }
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
	bool resultTheSign;

	unsigned int maxLength = max(integer1.length, integer2.length);

	string digitsInteger1 = "";
	string digitsInteger2 = "";
	inf_int forComp;

	for (int i = 0; i < maxLength - integer1.length; i++)
		digitsInteger1.append("0");
	for (int i = 0; i < maxLength - integer2.length; i++)
		digitsInteger2.append("0");

	if (integer1.thesign == true && integer2.thesign == false || integer1.thesign == false && integer2.thesign == true) {

		if (integer1.thesign == true && integer2.thesign == false) {
			digitsInteger1.append(integer1.digits);
			digitsInteger2.append(integer2.digits);
			digitsInteger2 = forComp.tenComplement(digitsInteger2, maxLength);
		}
		else {
			digitsInteger2.append(integer2.digits);
			digitsInteger1.append(integer1.digits);
			digitsInteger1 = forComp.tenComplement(digitsInteger1, maxLength);
		}
		
		string opResultReversed = "";
		int carry = 0;
		for (int i = maxLength - 1; i >= 0; i--) {
			int aNum = digitsInteger1[i] - '0' + carry;
			int bNum = digitsInteger2[i] - '0';
			int sum = aNum + bNum;

			opResultReversed.append(to_string(sum % 10));
			carry = sum / 10;
		}

		string opResult="";
		if (carry == 1)
			opResult.append("1");
		while (!opResultReversed.empty()) {
			opResult.push_back(opResultReversed.back());
			opResultReversed.pop_back();
		}

		if (opResult.length() > maxLength) {
			resultDigits = opResult.substr(1);
			resultTheSign = true;
		}
		else {
			resultDigits = forComp.tenComplement(opResult, maxLength);
			resultTheSign = false;
		}
	}
	else if (integer1.thesign == false && integer2.thesign == false) {
	
		digitsInteger1.append(integer1.digits);
		digitsInteger1 = forComp.tenComplement(digitsInteger1, maxLength);
		digitsInteger2.append(integer2.digits);
		digitsInteger2 = forComp.tenComplement(digitsInteger2, maxLength);
			

		string opResultReversed = "";
		int carry = 0;
		for (int i = maxLength - 1; i >= 0; i--) {
			int aNum = digitsInteger1[i] - '0' + carry;
			int bNum = digitsInteger2[i] - '0';
			int sum = aNum + bNum;

			opResultReversed.append(to_string(sum % 10));
			carry = sum / 10;
		}

		string opResult = "";
		if (carry == 1)
			opResult.append("1");
		while (!opResultReversed.empty()) {
			opResult.push_back(opResultReversed.back());
			opResultReversed.pop_back();
		}

		if (opResult.length() > maxLength) {
			resultDigits = opResult.substr(1);
			resultDigits = forComp.tenComplement(resultDigits, maxLength);
		}
		else {
			resultDigits = "1";
			resultDigits += forComp.tenComplement(opResult, maxLength);
		}
		resultTheSign = false;
	}
	else {
		digitsInteger1.append(integer1.digits);
		digitsInteger2.append(integer2.digits);


		string opResultReversed = "";
		int carry = 0;
		for (int i = maxLength - 1; i >= 0; i--) {
			int aNum = digitsInteger1[i] - '0' + carry;
			int bNum = digitsInteger2[i] - '0';
			int sum = aNum + bNum;

			opResultReversed.append(to_string(sum % 10));
			carry = sum / 10;
		}

		string opResult = "";
		if (carry == 1)
			opResult.append("1");
		while (!opResultReversed.empty()) {
			opResult.push_back(opResultReversed.back());
			opResultReversed.pop_back();
		}
		resultDigits = opResult;
		resultTheSign = true;
	}

	int zeroIdx=0;
	for (int i = 0; i < resultDigits.length(); i++) {
		if (resultDigits[i] == '0')
			zeroIdx++;
		else
			break;
	}
	if (zeroIdx == resultDigits.length()) {
		resultDigits = "0";
	}
	else {
		resultDigits = resultDigits.substr(zeroIdx);
	}

	if (!resultTheSign)
		resultDigits = "-" + resultDigits;

	inf_int result(resultDigits);
	return result;
}
inf_int operator-(const inf_int& integer1, const inf_int& integer2) {
	if ((integer1.thesign == true && integer2.thesign == true
		|| integer1.thesign == false && integer2.thesign == true)&& integer2.digits != "0") {
		inf_int changeTheSignInteger2("-"+integer2.digits);
		return operator+(integer1, changeTheSignInteger2);
	}
	else {
		inf_int changeTheSignInteger2(integer2.digits);
		return operator+(integer1, changeTheSignInteger2);
	}
}
inf_int operator*(const inf_int& integer1, const inf_int& integer2) {
	string resultDigits;
	bool resultTheSign;

	if (integer1.thesign == true && integer2.thesign == true ||
		integer1.thesign == false && integer2.thesign == false) {
		resultTheSign = true;
	}
	else {
		resultTheSign = false;
	}

	
	string digitsInteger1 = integer1.digits;
	string digitsInteger2 = integer2.digits;

	string opResultReversed = "";
	inf_int mul(0);
	for (int i = digitsInteger1.length() - 1; i >= 0; i--) {
		int aNum = digitsInteger1[i] - '0';
		int carry = 0;
		for (int j = digitsInteger2.length() - 1; j >= 0; j--) {
			int bNum = digitsInteger2[j] - '0';
			int product = aNum * bNum + carry;

			opResultReversed.append(to_string(product % 10));
			carry = product / 10;
		}
		string opResult = "";
		if (carry != 0)
			opResult.append(to_string(carry));
		while (!opResultReversed.empty()) {
			opResult.push_back(opResultReversed.back());
			opResultReversed.pop_back();
		}
		
		for (int j = i; j < digitsInteger1.length() - 1; j++) {
			opResult.append("0");
		}
		inf_int temp(opResult);
		mul = mul + temp;
	}

	if (!resultTheSign)
		resultDigits = "-" + mul.digits;
	else
		resultDigits = mul.digits;

	inf_int result(resultDigits);
	return result;
}

string inf_int::tenComplement(const string integer, const int compLength) const {
	string tenComp = "10";
	for(int i= compLength; i>1; i--)
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

inf_int& inf_int::operator=(const inf_int& x) {
	this->digits = x.digits;
	this->length = x.length;
	this->thesign = x.thesign;

	return *this;
}

bool operator==(const inf_int& x, const inf_int& y) {
	if (x.digits == y.digits && x.thesign == y.thesign) {
		return true;
	}
	else {
		return false;
	}
}

bool operator!=(const inf_int& x, const inf_int& y) {
	return !operator==(x, y);
}

bool operator>(const inf_int& x, const inf_int& y) {
	if (x.thesign == true && y.thesign == false) {
		return true;
	}
	else if (x.thesign == false && y.thesign == true) {
		return false;
	}
	else if (x.thesign == true && y.thesign == true) {
		if (x.digits.size() > y.digits.size()) {
			return true;
		}
		else if (x.digits.size() < y.digits.size()) {
			return false;
		}
		else {
			if (x.digits > y.digits) {
				return true;
			}
			else {
				return false;
			}
		}
	}
	else {
		if (x.digits.size() > y.digits.size()) {
			return false;
		}
		else if (x.digits.size() < y.digits.size()) {
			return true;
		}
		else {
			if (x.digits < y.digits) {
				return true;
			}
			else {
				return false;
			}
		}
	}
}

bool operator<(const inf_int& x, const inf_int& y) {
	if (x.digits == y.digits) {
		return false;
	}
	else {
		return !operator>(x, y);
	}
}

ostream& operator<<(ostream& os, const inf_int& infint)
{
	string str(infint.digits);
	if (!infint.thesign) {
		str.insert(0, "-");
	}
	os << str;
	return os;
	// TODO: 여기에 return 문을 삽입합니다.
}