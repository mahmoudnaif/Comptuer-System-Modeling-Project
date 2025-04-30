#include <iostream>
using namespace std;

std::string getMiddleNPlusOneChars(const std::string& str) {
    int len = str.length();
    int n = len / 2; // Number of characters to extract (n/2)

    // Start from the middle of the string, adjust to get n/2 + 1 characters
    int mid = len / 2;
    return str.substr(mid - n / 2, n ); // Take n/2 + 1 characters from the middle
}
int main(){
    string tempstr = "11xxxx11";
    cout << double(1234) / 10000;
return 0;
}