#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <math.h>
#include <fstream>

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

class Quadrilateral {
    // implement cout for Circle classes objects
    friend ostream & operator<<( ostream &output, const Quadrilateral &Q ){
        output << "Point 1: " << Q.P1 << endl << "Point 2: " << Q.P2 << endl << "Point 3: " << Q.P3 << endl << "Point 4: " << Q.P4 << endl;
        if (Q.isQuad == true)    
            output << "Valid: Yes" << endl;
        else
            output << "Valid: No" << endl;
        output << "Area: " << Q.area << endl;
        return output;
    }

    // implement cin for Circle classes objects
    friend istream & operator>>( istream &input, Quadrilateral &Q ){
        input >> Q.P1 >> Q.P2 >> Q.P3 >> Q.P4;
        return input;
    }

public:
    // Add your functions/methods here //
    Quadrilateral(){
        setP1(0,0);
        setP2(0,0);
        setP3(0,0);
        setP4(0,0);
        setLengths();
        setArea();
        validQuad();
    }
    
    Quadrilateral(int p1x, int p1y, int p2x, int p2y, int p3x, int p3y, int p4x, int p4y){
        setP1(p1x, p1y);
        setP2(p2x, p2y);
        setP3(p3x, p3y);
        setP4(p4x, p4y);
        setLengths();
        setArea();
        validQuad();
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
    void setP4(int x, int y){
        P4.setX(x);
        P4.setY(y);
    }
    
    
    bool operator==(Quadrilateral &qhs) {
	    return (qhs.P1 == P1 && qhs.P2 == P2 && qhs.P3 == P3 && qhs.P4 == P4);
    }
    
    double getArea(){
        return area;
    }
    
    void setArea(){
        
        area = 0.5 * (P1.getX()*P2.getY()+P2.getX()*P3.getY()+P3.getX()*P4.getY()+P4.getX()*P1.getY()-P2.getX()*P1.getY()-P3.getX()*P2.getY()-P4.getX()*P3.getY() - P1.getX()*P4.getY());
    }
    
    void setLengths(){
        p12 = sqrt((((P2.getX() - P1.getX()))*((P2.getX() - P1.getX()))) + ((P2.getY() - P1.getY()) * (P2.getY() - P1.getY())));
        p23 = sqrt((((P3.getX() - P2.getX()))*((P3.getX() - P2.getX()))) + ((P3.getY() - P2.getY()) * (P3.getY() - P2.getY())));
        p34 = sqrt((((P3.getX() - P4.getX()))*((P3.getX() - P4.getX()))) + ((P3.getY() - P4.getY()) * (P3.getY() - P4.getY())));
        p41 = sqrt((((P4.getX() - P1.getX()))*((P4.getX() - P1.getX()))) + ((P4.getY() - P1.getY()) * (P4.getY() - P1.getY())));
    }
    
    bool validQuad(){
        double test1 = P1.getX() * (P2.getY() - P3.getY()) + P2.getX() * (P3.getY() - P1.getY()) + P3.getX() * (P1.getY() - P2.getY());
        double test2 = P2.getX() * (P3.getY() - P4.getY()) + P3.getX() * (P4.getY() - P2.getY()) + P4.getX() * (P2.getY() - P3.getY());
        double test3 = P1.getX() * (P3.getY() - P4.getY()) + P3.getX() * (P4.getY() - P1.getY()) + P4.getX() * (P3.getY() - P1.getY());
        double test4 = P1.getX() * (P2.getY() - P4.getY()) + P2.getX() * (P4.getY() - P1.getY()) + P4.getX() * (P1.getY() - P2.getY());
        if ((test1 == 0) || (test2 == 0) || (test3 == 0) || (test4 == 0)){
            isQuad = false;
            return false;
        }
        else{
            isQuad = true;
            return true;
        }
    }
    
    
private:
    
    Point P1;
    Point P2;
    Point P3;
    Point P4;
    double area;
    bool isQuad;
    double p12;
    double p23;
    double p34;
    double p41;
    
};

int main(){
    //Quadrilateral T1(0,0,3,0,3,3);
    Quadrilateral Q2(0,0,3,0,3,3,0,3);
    //Circle C2(0,5,8,9);
    //cout << "L1: should have all zeros for values" << endl;
    //cout << C1 << endl;
    //cout << L2 << endl;
    //cin >> C1;
    cout << Q2;
    
    
    
    //cout << "Enter Two Points For Line: ";
    //cin >> L1;
    //cout << L1 << endl;

    return 0;
}

