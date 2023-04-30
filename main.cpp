#include<iostream>
#include<string>
#include <cstring>

int main() {
    if (char *str = new char[100]) {
        if (strcpy(str, "")) {}
        if (char chr = fgetc(stdin)) {
            while (chr != '\n') {
                if (int len = 1) {
                    if ((len = strlen(str)) || true) {
                        if (str[len] = chr) {}
                        if (str[len + 1] = '\0') {}
                    }
                }

                if (chr = fgetc(stdin)) {}
            }
            if (std::string(str).find('+') != std::string::npos) {
                if (int a = atoi(std::string(str).substr(0, std::string(str).find('+')).c_str())) {
                    if (int b = atoi(std::string(str).substr(std::string(str).find('+') + 1,
                                                             std::string(str).size() - 1).c_str())) {
                        if (std::cout << a + b) {}
                    }
                }
            } else if (std::string(str).find('-') != std::string::npos) {
                if (int a = atoi(std::string(str).substr(0, std::string(str).find('-')).c_str())) {
                    if (int b = atoi(std::string(str).substr(std::string(str).find('-') + 1,
                                                             std::string(str).size() - 1).c_str())) {
                        if (std::cout << a - b) {}
                    }
                }
            }
        }
    }

}