#include "longnumber.h"
#define _CRT_SECURE_NO_WARNINGS

void main() {
	LongNumber numa = read_longnum("a.txt");
	print_longnum(numa);
	LongNumber numb = read_longnum("b.txt");
	print_longnum(numb);
	LongNumber numc = add_longnum(numa, numb);
	print_longnum(numc);
	LongNumber numd = mul_by_digit(numc, 9);
	print_longnum(numd);
	//LongNumber nume = mul_by_pow10(numd, 3);
	LongNumber nume = mul_by_pow10(numa,2);
	print_longnum(nume);
	reverse(numa);

	LongNumber numf = mul_longnum(numa, numb);
	print_longnum(numf);

	delete_longnum(numa);
	delete_longnum(numb);
	delete_longnum(numc);
	delete_longnum(numd);
	delete_longnum(nume);
	delete_longnum(numf);
}