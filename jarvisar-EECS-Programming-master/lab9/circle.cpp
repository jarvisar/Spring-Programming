#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <math.h>

using namespace std;

class Point {

    // cout implementation for Point class
    friend ostream & operator<<( ostream &output, const Point &P ){
        output << "x: " << P.x << " y: " << P.y;
        return output;
    }

    // cin implementation for Point class
    friend istream & operator>>( istream &input, Point &P ){
        input >> P.x >> P.y;
        return input;
    }

public:
    Point(){
        x = 0;
        y = 0;
    }

    Point(int in_x, int in_y){
        x = in_x;
        y = in_y;
    }

    double getX(){
        return x;
    }
    
    double getY(){
        return y;
    }
    
    void setX(int in_X){
        x = in_X;
    }
    void setY(int in_Y){
        y = in_Y;
    }
    
    bool operator==(Point &rhs) {
	    return (rhs.x == x && rhs.y == y);
    }
    
private:
    int x,y;
};

class Circle {
    // implement cout for Circle classes objects
    friend ostream & operator<<( ostream &output, const Circle &C ){
        output << "Center: " << C.P1 << endl << "Point: " << C.P2 << endl;
        if (C.validCircle == true)
            output << "Is circle: " << "Yes" << endl;
        else
            output << "Is circle: " << "No" << endl;
        output << "Radius: " << C.radius << endl;
        output << "Diameter: " << C.radius * 2 << endl << "Area: " << C.area << endl;
        output << "Circumference: " << C.circumference << endl;
        return output;
    }

    // implement cin for Circle classes objects
    friend istream & operator>>( istream &input, Circle &C ){
        input >> C.P1 >> C.P2;
        return input;
    }

public:
    // Add your functions/methods here //
    Circle(){
        setP1(0,0);
        setP2(0,0);
	setRadius();
        setArea();
        setCircumference();
	isCircle();
    }
    
    Circle(int p1x, int p1y, int p2x, int p2y){
        setP1(p1x, p1y);
        setP2(p2x, p2y);
        setRadius();
        setArea();
        setCircumference();
	isCircle();
    }
    
    void setP1(int x, int y){
        P1.setX(x);
        P1.setY(y);
    }
    void setP2(int x, int y){
        P2.setX(x);
        P2.setY(y);
    }
    
    bool operator==(Circle &chs) {
	    return (chs.P1 == P1 && chs.P2 == P2);
    }
    
    double getRadius(){
        return radius;
    }
    
    void setRadius(){
        radius = sqrt((((P2.getX() - P1.getX()))*((P2.getX() - P1.getX()))) + ((P2.getY() - P1.getY()) * (P2.getY() - P1.getY())));
    }

    double getDiameter(){
        return radius * 2;
    }
    
    double getArea(){
        return M_PI * ((sqrt((((P2.getX() - P1.getX()))*((P2.getX() - P1.getX()))) + ((P2.getY() - P1.getY()) * (P2.getY() - P1.getY()))))*(sqrt((((P2.getX() - P1.getX()))*((P2.getX() - P1.getX()))) + ((P2.getY() - P1.getY()) * (P2.getY() - P1.getY())))));
    }
    
    void setArea(){
        area = M_PI * radius * radius;
    }
    
    double getCircumference(){
        return 2 * 3.14139265 * (sqrt((((P2.getX() - P1.getX()))*((P2.getX() - P1.getX()))) + ((P2.getY() - P1.getY()) * (P2.getY() - P1.getY()))));
    }
    
    void setCircumference(){
        circumference = 2 * 3.14139265 * radius;
    }
    
    bool isCircle(){
        if (P1 == P2){
            validCircle = false;
            return false;
        }
        else{
            validCircle = true;
            return true;
        }
    }
    
private:
    
    Point P1, P2;
    double radius;
    bool validCircle;
    double area;
    double circumference;
    
};

int main(){
    Circle C1(0,5,4,9);
    Circle C2(0,5,8,9);
    //cout << "L1: should have all zeros for values" << endl;
    //cout << C1 << endl;
    //cout << L2 << endl;
    //cin >> C1;
    cout << C2;
    bool test;
    if (C1 == C2)
        test = true;
    else
        test = false;
        
    cout << test;
    
    
    //cout << "Enter Two Points For Line: ";
    //cin >> L1;
    //cout << L1 << endl;

    return 0;
}

