#include<stdio.h>
#define MAXEXP 8

int main() {

	int k, a = 1, i, temp, factor, next, count, artioi = 0, perittoi = 0, d = 1, sinart, proig = 1, dekk = 10, ZP = 0, ZP1, sum, term, deficient = 0, abundant = 0;


	for (k = 1; k <= MAXEXP; k++)                                                                             //calculating of the limits of the program//
		a *= 10;

	for (i = 1; i <= a + 9; i++) {
		for (k = d; k <= i; k++) {
			d = i + 1;
			count = 0;
			if (k % 4 == 0 || k % 9 == 0)
				continue;
			temp = k;
			if (temp % 2 == 0) {
				temp /= 2;
				count++;
			}
			if (temp % 3 == 0) {
				temp /= 3;
				count++;
			}
			factor = 5;
			next = 0;
			while ((factor * factor) <= temp) {                                                              //we find the prime numbers that divide the specific number//
				if (temp % factor == 0) {
					count++;
					temp /= factor;
					if (temp % factor == 0) {                                                               // if the number is divided 2 continous times the number is not a square free number//
						next = 1;
						break;
					}
				}
				if (factor % 6 == 5)
					factor += 2;
				else
					factor += 4;                                                                           // change of the factors so we can find every number that divides i//
			}
			if (next == 0 && temp != 1)
				count++;
			if (next == 0 && count % 2 == 0)
				artioi++;
			else if (next == 0 && count % 2 != 0)
				perittoi++;
		}
		sinart = artioi - perittoi;                                                                       //calculation of the mertens function//

		if (sinart == 0)
			ZP++;                                                                                          
		if (i >= proig && i <= (dekk + 9))                                                                   
			printf("M(%d)= %d \n", i, sinart);                                                            //print of the results of mertens function as the problem says//
		if (i > dekk + 9) {
			printf("..........\n");                                                     
			dekk *= 10;
			proig = dekk - 9;                                                                             //we find zero points of the mertens function and we count them//
		}
	}

	printf("\nFound %d zero points of the Mertens function\n", ZP);                                   
	ZP1 = ZP * 1000;
	printf("\nChecking numbers in the range [2,%d]\n", ZP1);
	for (k = 2; k <= ZP1; k++) {                                                                         //the limits we can search is ftom [2,ZP], ZP is a variable we calculated before//
		sum = 1;
		temp = k;
		factor = 2;
		while (factor * factor <= temp) {
			term = 1;
			while (temp % factor == 0) {                                                                // a preparation so we can find the perfect,deficient and abundant numbers//
				term = factor * term + 1;
				temp /= factor;
			}
			sum *= term;
			if (factor == 2)
				factor = 3;
			else if (factor == 3)
				factor = 5;
			else if (factor % 6 == 5)
				factor += 2;
			else
				factor += 4;
		}
		if (temp != 1)
			sum *= (1 + temp);
		if (sum - k == k)
			printf("Found perfect number: %d \n", k);
		else if (sum - k < k)
			deficient++;
		else
			abundant++;
	}
	printf("\nFound %d deficient numbers\n", deficient);
	printf("Found %d abundant numbers\n", abundant);
}
