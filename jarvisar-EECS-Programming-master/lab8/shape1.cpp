#include <iostream>

using namespace std;

class Cube {
public:
    Cube(){
        setW(0);
        setL(0);
        setH(0);
    }

    Cube(double in_w, double in_l, double in_h){
        setW(in_w);
        setL(in_l);
        setH(in_h);
    }

    double getW(){
        return w;
    }

    double getL(){
        return l;
    }
    
    double getH(){
        return h;
    }

    void setW(double in_w){
        w = in_w;
    }

    void setL(double in_l){
        l = in_l;
    }
    
    void setH(double in_h){
        h = in_h;
    }

    void display(){
        cout << "Cube Parameters: " << endl;
        cout << "Width: " << getW() << endl;
        cout << "Length: " << getL() << endl;
        cout << "Height: " << getH() << endl;
        cout << "Volume: " << getVolume() << endl;
        cout << "Surface Area: " << getSurfArea() << endl << endl;
    }

private:
    double getVolume(){
        return w*l*h;
    }

    double getSurfArea(){
        return (2 * w * l) + (2 * l * h) + (2 * h * w);
    }

    double w;
    double l;
    double h;

};

int main(){

    Cube cube1;
    cube1.display();

    Cube cube2(2,4,2);
    cube2.display();

    cube2.setW(3);
    cube2.display();

    return 0;
}