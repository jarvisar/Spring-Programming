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

class Triangle {
    // implement cout for Circle classes objects
    friend ostream & operator<<( ostream &output, const Triangle &T ){
        output << "Point 1: " << T.P1 << endl << "Point 2: " << T.P2 << endl << "Point 3: " << T.P3 << endl;
        if (T.isTriangle == true)    
            output << "Valid: Yes" << endl;
        else
            output << "Valid: No" << endl;
        output << "Area: " << T.area << endl << "Perimeter: " << T.perimeter << endl;
        if (T.equalTriangle == true)    
            output << "Is it equilateral: Yes" << endl;
        else
            output << "Is it equilateral: No" << endl;
        return output;
    }

    // implement cin for Circle classes objects
    friend istream & operator>>( istream &input, Triangle &T ){
        input >> T.P1 >> T.P2 >> T.P3;
        return input;
    }

public:
    // Add your functions/methods here //
    Triangle(){
        setP1(0,0);
        setP2(0,0);
        setP3(0,0);
        setLengths();
        setPerimeter();
        setArea();
        validTriangle();
        equalilaterTriangle();
    }
    
    Triangle(int p1x, int p1y, int p2x, int p2y, int p3x, int p3y){
        setP1(p1x, p1y);
        setP2(p2x, p2y);
        setP3(p3x, p3y);
        setLengths();
        setPerimeter();
        setArea();
        validTriangle();
        equalilaterTriangle();
    }
    
    void setP1(int x, int y){
        P1.setX(x);
        P1.setY(y);
    }
    void setP2(int x, int y){
        P2.setX(x);
        P2.setY(y);
    }
    void setP3(int x, int y){
        P3.setX(x);
        P3.setY(y);
    }
    
    bool operator==(Triangle &ths) {
	    if ((ths.isTriangle == false) || (isTriangle == false))
	       return false;
	   else
	       return (ths.P1 == P1 && ths.P2 == P2 && ths.P3 == P3);
    }
    
    double getPerimeter(){
        return perimeter;
    }
    
    void setPerimeter(){
        perimeter = p12 + p23 + p31;
    }
    
    double getArea(){
        return area;
    }
    
    void setArea(){
        
        area = sqrt((perimeter/2)*((perimeter/2) - p12)*((perimeter/2) - p23)*((perimeter/2) - p31));
    }
    
    void setLengths(){
        p12 = sqrt((((P2.getX() - P1.getX()))*((P2.getX() - P1.getX()))) + ((P2.getY() - P1.getY()) * (P2.getY() - P1.getY())));
        p23 = sqrt((((P3.getX() - P2.getX()))*((P3.getX() - P2.getX()))) + ((P3.getY() - P2.getY()) * (P3.getY() - P2.getY())));
        p31 = sqrt((((P3.getX() - P1.getX()))*((P3.getX() - P1.getX()))) + ((P3.getY() - P1.getY()) * (P3.getY() - P1.getY())));
    }
    
    bool validTriangle(){
        double test = P1.getX() * (P2.getY() - P3.getY()) + P2.getX() * (P3.getY() - P1.getY()) + P3.getX() * (P1.getY() - P2.getY());
        if (test == 0){
            isTriangle = false;
            return false;
        }
        else{
            isTriangle = true;
            return true;
        }
    }
    
    bool equalilaterTriangle(){
        if ((p12 == p23) && (p23 == p31) && (p31 == p12)){
            equalTriangle = true;
            return true;
        }
        else{
            equalTriangle = false;
            return false;
        }
    }
    
private:
    
    Point P1;
    Point P2;
    Point P3;
    double area;
    bool isTriangle;
    double perimeter;
    bool equalTriangle;
    double p12;
    double p23;
    double p31;
    
};

int main(){
    Triangle T1(0,0,3,0,3,3);
    Triangle T2(0,0,3,0,3,3);
    //Circle C2(0,5,8,9);
    //cout << "L1: should have all zeros for values" << endl;
    //cout << C1 << endl;
    //cout << L2 << endl;
    //cin >> C1;
    cout << T1;
    
    bool test;
    if (T1 == T2)
        test = true;
    else
        test = false;
        
    cout << test;
    
    //cout << "Enter Two Points For Line: ";
    //cin >> L1;
    //cout << L1 << endl;

    return 0;
}

