// mac937@nyu.edu
// CS Bridge 2020 Winter Extended
// HW7 Question 2

#include <iostream>
#include <cmath>

using namespace std;

// Analyzes the divisors of num, assigning the number of proper divisors of
// num to outCountDivs and the sum of num's proper divisors to outSumDivs.
void analyzeDivisors(int num, int& outCountDivs, int& outSumDivs) {
    double numSqrt = sqrt(num);
    outCountDivs = 1;  // 1 is a divisor of all integers
    outSumDivs = 1;    
    for (int divisor = 2; divisor <= numSqrt; divisor++) {
        if (num % divisor == 0) {
            int complementary = num / divisor;
            if (divisor == complementary) {
                outCountDivs += 1;
                outSumDivs += divisor;
            } else {
                outCountDivs += 2;
                outSumDivs += (divisor + complementary);
            }
        }
    }
}

int main() {
    int maxNum;
    int numDivisorCount, numDivisorSum;
    cout << "Enter a positive integer: ";
    cin >> maxNum;
    
    for (int num = 2; num <= maxNum; num++) {
        analyzeDivisors(num, numDivisorCount, numDivisorSum);
        if (num == numDivisorSum) {
            cout << "perfect: " << num << endl;
        }
        // now look for an amicable partner; 
        // perfect implies amicable to itself, so start at num + 1
        for (int maybeAmicable = num + 1; maybeAmicable <= maxNum; maybeAmicable++) {
            if (numDivisorSum == maybeAmicable) {
                int amiDivisorCount, amiDivisorSum;
                analyzeDivisors(maybeAmicable, amiDivisorCount, amiDivisorSum);
                if (amiDivisorSum == num) {
                    cout << "amicable: " << num << " and " << maybeAmicable << endl;
                }
                break;
            }
        }
    }
    return 0;
}
