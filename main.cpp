#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sstream>
#include <bits/stdc++.h>

#define EXIT_CONVERTER {cout << "Invalid IPv4 address" << endl; \
                        exit(EXIT_FAILURE);}

using namespace std;


int convert_string_to_int(string str) {
    int x;
    stringstream geek(str);
    geek >> x;
    return x;
}


string transform_in_binary(int octet_value) {

    string octet_binary;

    for (int digit = 7; digit >= 0; digit--) {
        octet_binary.push_back(octet_value & (1 << digit) ? '1' : '0');
    }

    reverse(octet_binary.begin(), octet_binary.end());

    return octet_binary;
}

string foo(string ipv4_dec) {

    string ipv4_bin;
    size_t pos;
    unsigned int count = 4;
    unsigned int octet_int;

    pos = ipv4_dec.find('.');
    while (count) {

        octet_int = convert_string_to_int(ipv4_dec.substr(0, pos));

        ipv4_dec = ipv4_dec.substr(pos + 1, ipv4_dec.length());

        string tmp = transform_in_binary(octet_int);

        reverse(tmp.begin(), tmp.end());

        ipv4_bin += tmp;

        if (count != 1)
            ipv4_bin.push_back('.');

        pos = ipv4_dec.find('.');

        count--;
    }

    return ipv4_bin;
}

int main() {

    string ipv4_dec, ipv4_bin;

    cin >> ipv4_dec;

    ipv4_bin = foo(ipv4_dec);

    cout << ipv4_bin << endl;

    return 0;
}
