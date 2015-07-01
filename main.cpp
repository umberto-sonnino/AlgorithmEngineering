#include <iostream>
#include <math.h>

bool solutionProof(double a, double b, double c, double *x1, double *x2){

    double delta = b*b-4*a*c ;
    if( delta < 0)
        return false;
    *x1 = (-b - sqrt(delta))/2*a;
    *x2 = (-b + sqrt(delta))/2*a;

    return true;
}

int main(){
    double x1, x2;
    cout << "Solve this equation: 2x^2-3x+7 = 0" << endl;
    solutionProof(2, 3, 7, &x1, &x2);
    cout << "The result are: " << x1 << "and " << x2;

    return 0;
}
