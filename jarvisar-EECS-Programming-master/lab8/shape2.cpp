

#include <iostream>
#include <math.h>

using namespace std;

class Cylinder {
public:
    Cylinder(){
        setR(0);
        setH(0);
    }

    Cylinder(double in_R, double in_H){
        setR(in_R);
        setH(in_H);
    }

    double getR(){
        return r;
    }

    double getH(){
        return h;
    }

    void setR(double in_R){
        r = in_R;
    }

    void setH(double in_H){
        h = in_H;
    }

    void display(){
        cout << "Cylinder Parameters: " << endl;
        cout << "Radius: " << getR() << endl;
        cout << "Height: " << getH() << endl;
        cout << "Area: " << getVolume() << endl;
        cout << "Perimeter: " << getSurfArea() << endl << endl;
    }

private:
    double getVolume(){
        return M_PI * r * r * h;
    }

    double getSurfArea(){
        return 2 * M_PI * r * (r + h);
    }

    double r;
    double h;

};

int main(){

    Cylinder cyl1;
    cyl1.display();

    Cylinder cyl2(2,4);
    cyl2.display();

    cyl2.setR(3);
    cyl2.display();

    return 0;
}