#include <math.h>
struct point {
    double x;
    double y;
};

struct rectangle {
    struct point ll;
    struct point ur;
};

//mkRectangle() that accepts two points
struct rectangle mkRectangle(struct point p1,struct point p2){
    struct rectangle rect;
    //assume that p1 is the ll and p2 is the ur
    rect.ll.x = p1.x;
    rect.ll.y = p1.y;
    rect.ur.x = p2.x;
    rect.ur.y = p2.y;
    return rect;  
}
//mkRectangle() that accepts 4 real numbers
struct rectangle mkRectangle(double a1, double b1, double a2, double b2){
    struct point point1, point2;
    struct rectangle rect;
    //construct 2 points from a1,a2,b1,b2
    //assume (a1,b1) & (a2,b2)
    point1.x = a1;
    point1.y = b1;
    point2.x = a2;
    point2.y = b2;
    //assume that (a1,b1) is ll, (a2,b2) is ur
    rect.ll.x = point1.x;
    rect.ll.y = point1.y;
    rect.ur.x = point2.x;
    rect.ur.y = point2.y;
    return rect;
}