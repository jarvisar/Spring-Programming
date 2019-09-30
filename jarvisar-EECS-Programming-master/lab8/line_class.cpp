// Add your information here

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
    
    
private:
    int x,y;
};

class Line {
    // implement cout for Line classes objects
    friend ostream & operator<<( ostream &output, const Line &L ){
        output << "Point 1: " << L.P1 << endl << "Point 2: " << L.P2;
        return output;
    }

    // implement cin for Line classes objects
    friend istream & operator>>( istream &input, Line &L ){
        input >> L.P1 >> L.P2;
        return input;
    }

public:
    // Add your functions/methods here //
    Line(){
        setP1(0,0);
        setP2(0,0);
    }
    
    Line(int p1x, int p1y, int p2x, int p2y){
        setP1(p1x, p1y);
        setP2(p2x, p2y);
    }
    
    void setP1(int x, int y){
        P1.setX(x);
        P1.setY(y);
    }
    void setP2(int x, int y){
        P2.setX(x);
        P2.setY(y);
    }
    
    double getSlope(){
        return (P2.getY() - P1.getY()) / (P2.getX() - P1.getX());
    }
    
    double getLength(){
        return sqrt((((P2.getX() - P1.getX()))*((P2.getX() - P1.getX()))) + ((P2.getY() - P1.getY()) * (P2.getY() - P1.getY())));
    }

    double getYInt(){
        return (getSlope() * (0 - P1.getX())) + P1.getY();
    }
    
    bool isVertical(){
        if (P2.getX() == P1.getX())
            return true;
        else
            return false;
    }
    
    bool isHorizontal(){
        if (P2.getY() == P1.getY())
            return true;
        else
            return false;
    }
    
    bool isParallel(Line T1){
        if (T1.getSlope() == getSlope()){
            cout << T1.getSlope() << ":" << getSlope() << endl;
            return true;
        }
        else
            return false;
    }


private:
    
    
    Point P1, P2;
};

int main(){
    Line L1(0,5,8,9);
    Line L2(0,1,8,0);
    //cout << "L1: should have all zeros for values" << endl;
    //cout << L1 << endl;
    //cout << L2 << endl;

    cout << "Parallel to Line 1?: " << L2.isParallel(L1) << endl;
    cout << "Length: " << L2.getLength() << endl;
    cout << "Slope: " << L2.getSlope() << endl;
    cout << "Y-Int: " << L2.getYInt() << endl;
    
    
    //cout << "Enter Two Points For Line: ";
    //cin >> L1;
    //cout << L1 << endl;

    return 0;
}