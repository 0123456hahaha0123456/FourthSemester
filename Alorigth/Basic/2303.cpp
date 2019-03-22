#include <iostream>
#include <string>
#define MAXSTACKSIZE 100

using namespace std;

bool IsStringRight(string&);

struct STACK{
   char A[MAXSTACKSIZE];
   int v;
};

STACK S;

int main(){

   S.v = 0;

   string str;
   cin >> str;
   if(IsStringRight(str)){
      cout << "String is right";
   }
   else {
      cout << "String is wrong";
   }
   return 0;
}

bool IsStringRight(string& str){

	for(int i=0;i<str.length();i++){
		char c = str.at(i);
		switch (c) {
		    case '{' : case '(' : case '[' :
		        S.v++;
		        S.A[S.v] = c;
		        break;
		    case ')' :
		        if (S.A[S.v] == '(') S.v--;
		        else return false;
		        break;
            case '}' :
                if (S.A[S.v] == '{') S.v--;
		        else return false;
		        break;
            case ']' :
                if (S.A[S.v] == '[') S.v--;
		        else return false;
		        break;

		}
	}
	return true;
}
