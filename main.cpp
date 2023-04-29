#include <iostream>
#include <string>
using namespace std;int main(){string s[1000];string a,b,c;while(cin>>a>>b>>c)if(a=="get"){int i=stoi(b);if(s[i].substr(0,s[i].find(';'))==c)cout<<s[i].substr(s[i].find(';')+1,s[i].size())+"\n";}else{int i=stoi(a);s[i]=b+";"+c;}}
