#include <stdio.h>

double check_intersection(double X1, double Y1, double X2, double Y2, double L1, double L2) {
    double answer = 1;
    if  ((X1+L1<X2) || (X2+L2<X1) || (Y1+L1<Y2) || (Y2+L2<Y1)) {
         answer = 0;
    }
    return answer;
}

double maximum(double a, double b) {
    double max = a;
    if (b > a) {
        max = b;
    }
    return max;
}

double minimum(double a, double b) {
    double min = a;
    if (b < a) {
        min = b;
    }
    return min;
}

int main() {
    double x1, y1, x2, y2, len1, len2;
    printf("input coordinates of upper left corner and length of sides for 1 square: ");
    scanf("%lf, %lf, %lf", &x1, &y1, &len1);
    printf("input coordinates of upper left corner and length of sides for 2 square: ");
    scanf("%lf, %lf, %lf", &x2, &y2, &len2);
    if (check_intersection(x1, y1, x2, y2, len1, len2) == 1){
        printf("they intersect\n");
        double xl = maximum(x1, x2);
        double yl = maximum(y1 + len1, y2 + len2);
        double xr = minimum(x1 + len1, x2 + len2);
        double yr = minimum(y1, y2);
        printf("coordinates of bottom left and top right of intersection: (%lf, %lf), (%lf, %lf)\n", xl, yl, xr, yr);
    }
    else {
        printf("they don't\n");
    }

}
