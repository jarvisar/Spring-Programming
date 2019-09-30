// Please place your information here
//
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// This prototype is complete
class stringManip {
    public:
        stringManip();
        stringManip(string input);
        string retrieve();
        void setString(string input);
        void chop();
        void padString(int n);
        void center(int length);
        void truncate(int n);
        void removeNonAlpha();
        void convertToUpperCase();
        void convertToLowerCase();
    private:
        string tobeEdited;
};

// Not all functions are defined here

// Default Constructor
stringManip::stringManip(){
    tobeEdited = "";
}

// Overloaded Constructor
stringManip::stringManip(string in_string){
    tobeEdited = in_string;
}

// retrieve function
string stringManip::retrieve(){
    return tobeEdited;
}

void stringManip::chop(){
    int n = 0;
    for (int i = 0; i < tobeEdited[i]; i++){
        if ((isspace(tobeEdited[i])) == false){
            tobeEdited[n++] = tobeEdited[i];
        }
    }
    tobeEdited[n] = '\0';
}

// padString() function
void stringManip::padString(int length){
    if (tobeEdited.size() < length){
        for (int i = tobeEdited.size(); i < length; i++){
            tobeEdited.append(" ");
        }
    }
}

void stringManip::center(int length){
    chop();
    for (int i = 0; i < length/2; i++){
        tobeEdited.insert(0," ");
    }
    for (int i = 0; i < length/2; i++){
        tobeEdited.append(" ");
    }
}

void stringManip::truncate(int length){
    if (tobeEdited.size() > length){
        for (int i = length; i < tobeEdited.size(); i++){
            tobeEdited[i] = '\0';
        }
    }
}

void stringManip::removeNonAlpha(){
    for (int i = 0; i < tobeEdited.size(); i++){
        if (isalpha(tobeEdited[i]) == false)
            tobeEdited[i] = '\0';
    }
}

void stringManip::convertToUpperCase(){
    for (int i = 0; i < tobeEdited.size(); i++){
        tobeEdited[i] = toupper(tobeEdited[i]);
    }
}

void stringManip::convertToLowerCase(){
    for (int i = 0; i < tobeEdited.size(); i++){
        tobeEdited[i] = tolower(tobeEdited[i]);
    }
}

void stringManip::setString(string input){
    tobeEdited = input;
}

// Add rest of functions here

// Add test cases to main()
int main(){
    //stringManip S1;
    stringManip S2("testing 123");

    // Test case for padString() You should correct some of your own.
    //cout << "S2 before padString(20): <" << S2.retrieve() << ">" << endl;
    //S2.padString(20);
    //cout << "S2 after padString(20): <" << S2.retrieve() << ">" << endl;
    //cout << "Should be: <testing 123       >" << endl;
    S2.convertToUpperCase();
    cout << S2.retrieve();
  
    return 0;
}