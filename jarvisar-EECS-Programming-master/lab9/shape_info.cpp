#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <math.h>
#include <fstream>
#include <sstream>

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
        //output << "Point 1: " << Q.P1 << endl << "Point 2: " << Q.P2 << endl << "Point 3: " << Q.P3 << endl << "Point 4: " << Q.P4 << endl;
        if (Q.isQuad == true){
            output << "Object is a Quadrilateral" << endl;
            output << "Area: " << Q.area << " sq. units" << endl;
        }
        else
            output << "Object is NOT a Quadrilateral" << endl;
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


class Circle {
    // implement cout for Circle classes objects
    friend ostream & operator<<( ostream &output, const Circle &C ){
        //output << "Center: " << C.P1 << endl << "Point: " << C.P2 << endl;
        if (C.validCircle == true){
            output << "Object is a Circle." << endl;
            output << "Radius: " << C.radius << " units" << endl;
            output << "Diameter: " << C.radius * 2 << " units" << endl << "Area: " << C.area << " sq. units" << endl;
            output << "Circumference: " << C.circumference << " units" << endl;
        }
        else
            output << "Object is NOT a Circle." << endl;
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

class Triangle {
    // implement cout for Circle classes objects
    friend ostream & operator<<( ostream &output, const Triangle &T ){
        //output << "Point 1: " << T.P1 << endl << "Point 2: " << T.P2 << endl << "Point 3: " << T.P3 << endl;
        if (T.isTriangle == true){  
            output << "Object is a Triangle" << endl;
            output << "Area: " << T.area << " sq. units" << endl << "Perimeter: " << T.perimeter << " units" << endl;
            if (T.equalTriangle == true)    
                output << "Is it equilateral: Yes" << endl;
            else
                output << "Is it equilateral: No" << endl;
            return output;
        }
        else
            output << "Object is NOT a Triangle" << endl;
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

vector<double> breakup(string str){
    vector<double> points;
    stringstream ss;
    ss << str;
    while(!ss.eof()){
        double temp;
        ss >> temp;
        points.push_back(temp);
    }
    return points;
}

int main(){
    
    ifstream MyFile;
    ofstream outputFile;
    outputFile.open("shapes-info.txt");
    MyFile.open("shapes.txt");
    vector<double> points;
    string str;
    vector<string> file_contents;
    while (getline(MyFile,str)){
        file_contents.push_back(str);
    }
    string temp;
    for (int i=0;i<file_contents.size();++i){
        temp = file_contents.at(i);
        points = breakup(temp);
    }
    if (points.size() == 4){
        Circle C1(points.at(0),points.at(1),points.at(2),points.at(3));
        outputFile << C1;
    }
    else if (points.size() == 6){
        Triangle T1(points.at(0),points.at(1),points.at(2),points.at(3),points.at(4),points.at(5));
        outputFile << T1;
    }
    else if (points.size() == 8){
        Quadrilateral Q1(points.at(0),points.at(1),points.at(2),points.at(3),points.at(4),points.at(5),points.at(6),points.at(7));
        outputFile << Q1;
    }
    else{
        cout << "Sufficient coordinates NOT input." << endl;
    }
    return 0;   
}