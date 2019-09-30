#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
const double Q = 0.000000001;
const double ke = 9000000000;


double Efield(double r, double a = 1){
    double result;
    if (r < a){
        result = ke * Q * (r/(a*a*a));
    }
    if (r >= a){
        result = ((ke * Q)/(r*r));
    }
    
    cout << "Efield: " << setprecision(6) << result << endl;
	return result;
}



int main() {
    double r;
    double a;
    cout << "Enter r: ";
    cin >> r;
    cout << endl << "Enter a: ";
    cin >> a;
    cout << endl;
    Efield(r,a);
    
    return 0;
}
