#include <iostream>
#include <cmath>
using namespace std;


class Triangle
{
private:
    float x_coord, y_coord;
    float first_side;
    float second_side;
    float third_side;

public:
    Triangle(float x_crd, float y_crd, float f_side, float s_side, float th_side)
    {
        x_coord = x_crd;
        y_coord = y_crd;
        if(abs(f_side - th_side) < abs(f_side - s_side) + abs(s_side - th_side))
        {
            if(f_side > 0 && s_side > 0 && th_side > 0)
            {
                first_side = f_side;
                second_side = s_side;
                third_side = th_side; 
            }
        }
        
    }

    float GetFirstSide()
    {
        return this->first_side;
    }
    
    float GetSecondSide()
    {
        return this->second_side;
    }
    
    float GetThirdSide()
    {
        return this->third_side;
    }

    float GetPerimeter()
    {
        return this->first_side + this->second_side + this->third_side;
    }

    float GetArea()
    {
        float area = pow((GetPerimeter() / 2) * ((GetPerimeter() / 2) - GetFirstSide()) * \
                        ((GetPerimeter() / 2) - GetSecondSide()) * ((GetPerimeter() / 2) - GetThirdSide()), 0.5);
        return area;
    }
};

