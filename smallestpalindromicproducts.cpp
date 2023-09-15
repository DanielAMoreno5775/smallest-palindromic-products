/*
This program will calculate every possible product of three 3-digit integers to determine the smallest products with an even and odd number of digits.
*/
#include <iostream>
#include <limits>
using namespace std;

//function prototypes
bool isPalindrome(int, int &);

int main() {
	//initialize the variables to prevent issues with junk data and to ensure relational operators function correctly in later lines
	int product = 0,
		numOfDigits = 0,
		lowestAndOddNumberOfDigits = INT_MAX,
		lowestAndEvenNumberOfDigits = INT_MAX;
	bool palindromicNumber = false;

	//Indicate that the program has started to run, thereby preventing concern from the user of a frozen program due to the time necessary to perform the calculations
	cout << "Program has begun running calculations" << endl;

	//the nested for loops follow the pattern of 100x100x100 -> 100x100x101 -> 100x101x101 -> 101x101x101 when calculating the product
	for (int i = 100; i < 1000; i += 1) {
		for (int j = 100; j < 1000; j += 1) {
			for (int k = 100; k < 1000; k += 1) {
				product = i * j * k; //calculate the product
				numOfDigits = 0; //reset the number of digits to 0
				palindromicNumber = isPalindrome(product, numOfDigits); //get the number of digits and determine whether it is a palindrome
				//this if statement ensures that product is less than current lowest, is a palindrome, and has an odd number of digits
				if (lowestAndOddNumberOfDigits > product && palindromicNumber && ((numOfDigits % 2) != 0)) {
					lowestAndOddNumberOfDigits = product;
				}
				//this if statement ensures that product is less than current lowest, is a palindrome, and has an even number of digits
				if (lowestAndEvenNumberOfDigits > product && palindromicNumber && ((numOfDigits % 2) == 0)) {
					lowestAndEvenNumberOfDigits = product;
				}
			}
		}
	}

	cout << lowestAndOddNumberOfDigits << " is the smallest palindromic number that has an odd number of digits and is the product of three 3-digit numbers." << endl;
	cout << endl;
	cout << lowestAndEvenNumberOfDigits << " is the smallest palindromic number that has an even number of digits and is the product of three 3-digit numbers." << endl;

	return 0;
 }

//function definition that will determine whether an integer is a palindrome
//it uses a reference variable to let the function return 2 values and to eliminate the need to reproduce work in a separate function, thereby saving processing time
bool isPalindrome(int num, int &numOfDigits) {
	//initialize all relevant variables
	int digit = num % 10;
	int individualDigits[100]{ 0 };
	int i = 0;
	bool palindromeFlag = true;

	//fills the array with the digits in reverse order
	while (num > 0) {
		digit = num % 10;
		num /= 10;
		individualDigits[numOfDigits] = digit; //stores the digits in reverse order in the array
		numOfDigits += 1; //stores the number of digits to prevent integer overflow
	}

	numOfDigits -= 1; //must subtract it by one so that numOfDigits represents maximum index rather than number of elements

	//checks whether first and last digit match, then moves layer by layer until i exceeds the number of digits minus i
	while (i <= (numOfDigits-i)) {
		if (individualDigits[i] != individualDigits[numOfDigits-i])
			palindromeFlag = false;
		i += 1;
	}

	numOfDigits += 1; //must add one to it so that numOfDigits represents number of elements rather than maximum index

	return palindromeFlag;
}