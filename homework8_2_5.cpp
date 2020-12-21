#include <iostream>
#include <math.h>
#include <string>
using namespace std;

class Point {
private:
    float x;
    float y;
public:
    Point () {};
    Point(float x, float y) {
        this->x = x;
        this->y = y;
    }

    void input() {
        cout << "input x: " << endl;
        cin >> x;
        cout << "input y: " << endl;
        cin >> y;
    }

    void print() {
        cout << "(" << this->x << ", " << this->y << ")" << endl;
    }

    double find_distance(Point p1) {
        double res;
        res = sqrt(pow((p1.x - x),2) + pow((p1.y - y), 2));
        return res;
    }
};

int main() {
    double perimeter = 0;
    int count = 1;
    string answer = "n";
    Point first_point;
    Point temp;
    first_point.input();
    temp = first_point;
    while (true) {
        cout << "input point? y/n" << endl;
        cin >> answer;
        if (answer == "n") {
            perimeter += first_point.find_distance(temp);
            break;
        }
        Point new_point;
        new_point.input();
        perimeter += first_point.find_distance(new_point);
        count += 1;
        first_point = new_point;
    }
    cout << count << " points, perimeter: " << perimeter << endl;
}
