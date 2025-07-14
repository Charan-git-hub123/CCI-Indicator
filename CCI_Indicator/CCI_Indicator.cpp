// CCI indicator code

#include<stdio.h>
#include<stdio.h>
#include<math.h>
#include <corecrt_malloc.h>

#pragma warning(disable : 6011)

typedef struct {
	double high;
	double low;
	double close;
}bar;



//function to get average

double Average(double* price, int len) {
	double sum = 0;
	int counter = 0;
	double average;

	for (counter = 1; counter <= len; counter++) {
		sum = sum + *(price + counter);
	}
	if (len > 0) {
		average = sum / len;
	}
	else {
		average = 0;
	}
	return average;
}

//------------------------------------------------------------------------------------------------


//function to get cci
double CCI(int length, double* price, bar* ptr) {
	int sum = 0;
	int counter = 0;
	double MD = 0;
	double avg = 0;
	double cci = 0;


	if (length > 0) {
		double avg = Average(price, length);
		for (counter = 1; counter <= length; counter++) {
			MD = MD + fabs(((ptr + counter)->high + (ptr + counter)->low + (ptr + counter)->close) - avg);

		}
		MD = MD / length;
		if (MD == 0) {
			cci = 0;
		}
		else
		{
			cci = (((ptr + counter)->high + (ptr + counter)->low + (ptr + counter)->close) - avg) / (0.015 * MD);
		}
		return cci;
	}
	else cci = 0;
}
//-----------------------------------------------------------------------------



int main() {
	int length;
	printf("enter n.o of bars(length) : ");
	scanf_s("%d", &length);

	bar* ptr = (bar*)calloc(length, sizeof(bar));
	double* price = (double*)calloc(length, sizeof(double));


	for (int i = 1; i <= length; i++) {

		printf("enter the %d bar high\n", i);
		scanf_s("%lf", &((ptr + i)->high));

		printf("enter the %d bar low\n", i);
		scanf_s("%lf", &((ptr + i)->low));

		printf("enter the %d bar close\n", i);
		scanf_s("%lf", &((ptr + i)->close));


	}
	for (int i = 1; i <= length; i++) {
		*(price + i) = (ptr + i)->high + (ptr + i)->low + (ptr + i)->close;

		printf("the price of %d bar : %lf \n", i, *(price + i));

	}

	printf("the average of bars:  %lf\n", Average(price, length));

	printf("the cci of bars %lf", CCI(length, price, ptr));

}