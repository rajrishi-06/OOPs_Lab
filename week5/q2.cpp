#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

bool isValidEmail(const string& email) {
    size_t atPos = email.find('@');
    size_t dotPos = email.find('.', atPos);

    return (atPos != string::npos && dotPos != string::npos && atPos < dotPos);
}

string extractUsername(const string& email) {
    return email.substr(0, email.find('@'));
}

string extractDomain(const string& email) {
    return email.substr(email.find('@') + 1);
}

string toLowerCase(const string& str) {
    string lowerStr = str;
    transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}

int countDigits(const string& str) {
    return count_if(str.begin(), str.end(), ::isdigit);
}

string replaceDotsWithDashes(string email) {
    replace(email.begin(), email.end(), '.', '-');
    return email;
}

int main() {
    string email;
    cout << "Enter your email: ";
    cin >> email;

    if (!isValidEmail(email)) {
        cout << "Invalid email format.\n";
        return 1;
    }

    string username = extractUsername(email);
    string domain = extractDomain(email);
    string lowerDomain = toLowerCase(domain);
    int digitCount = countDigits(email);
    string modifiedEmail = replaceDotsWithDashes(email);

    cout << "Username: " << username << endl;
    cout << "Domain: " << domain << endl;
    cout << "Lowercase Domain: " << lowerDomain << endl;
    cout << "Number of digits in email: " << digitCount << endl;
    cout << "Email with periods replaced by dashes: " << modifiedEmail << endl;

    return 0;
}