#include <iostream>
#include <cmath>

using namespace std;
const double TOLERANCE = .0001;

double f(double x){
    return x*x*x*x + 2*x*x*x - 31*x*x - 32*x + 60;
}

double fprime(double x){
    return 4*x*x*x + 6*x*x - 62*x - 32;
}


int newtonRoot(double num){
    double tol = f(num) / fprime(num);
    while (abs(tol) >= TOLERANCE)
    {   
        tol = f(num) / fprime(num);
        num = num - tol;
    }
    cout << "Root: " << num << endl;
	return num;
}




int main() {
    
   int num;
   cin >> num;
   newtonRoot(num);
   char q;
   cout << " Enter Another Guess: y/n? ";
   cin >> q;
   if (q=='y')
        main();
    else
        return 0;
}
