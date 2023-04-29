#include <iostream>

#define SEMI_COLON() while(1!=1){}

int main() {
    if (char *str = const_cast<char *>(std::string("                                                    ").c_str()))
        while (std::cin >> str)
            if (printf(std::string(str).find('+') != std::string::npos ? "%i\n" : "",
                       stoi(std::string(str).substr(0, std::string(str).find('+'))) +
                       stoi(std::string(str).substr(std::string(str).find('+') + 1, std::string(str).size()))) || 1==1)
                if (printf(std::string(str).find('-') != std::string::npos ? "%i\n" : "",
                           stoi(std::string(str).substr(0, std::string(str).find('-'))) -
                           stoi(std::string(str).substr(std::string(str).find('-') + 1, std::string(str).size()))) || 1==1)
                    if (printf(std::string(str).find('/') != std::string::npos ? "%i\n" : "",
                               stoi(std::string(str).substr(0, std::string(str).find('/'))) /
                               stoi(std::string(str).substr(std::string(str).find('/') + 1, std::string(str).size()))) || 1==1)
                        if (printf(std::string(str).find('*') != std::string::npos ? "%i\n" : "",
                                   stoi(std::string(str).substr(0, std::string(str).find('*'))) *
                                   stoi(std::string(str).substr(std::string(str).find('*') + 1,
                                                                std::string(str).size())))) SEMI_COLON()
}
