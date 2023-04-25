#include <iostream>
#include <string>
using namespace std;

std::string parse_10digit_number(std::string number) {
    return number.substr(0, 4) + " " + number.substr(4, 3) + " " + number.substr(7, 3);
}


std::string parse_phone_number(std::string number) {
    //cout<<number.size()<<endl;
    switch(number.size()) {
        case 10:
            return "(004) " + parse_10digit_number(number);
        case 12:
            return "(004) " + parse_10digit_number(number.substr(2, number.size() - 2));
        case 13:
            return "(004) " + parse_10digit_number(number.substr(2, number.size() - 3));
        default:
            return "";
    }
}


int main() {
    int size;
    std::string phone_number;
    cin>>size;
    //cin.get();

    for (int i = 0; i < size; i++) {
        //getline(cin, phone_number);
        std::cin >> phone_number;
        std::cout << parse_phone_number(phone_number) << std::endl;
    }
}