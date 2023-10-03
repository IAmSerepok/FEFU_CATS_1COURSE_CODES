#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

double c1 = 0, c2 = 0, t1 = 0, t2 = 0;

int stupid_angle(double x0, double y0, double x1, double y1, double x2, double y2){

    double a1 = x1 - x0, a2 = x2 - x0, b1 = y1 - y0, b2 = y2 - y0;
    double d1 = sqrt(a1*a1+b1*b1), d2 = sqrt(a2*a2+b2*b2);
    double t = a1*a2+b1*b2;
    t = t/(d1*d2);
    if(t < ((-1)/2)){
        return 1;
    }
    else return -1;
}

int first_step(double x1, double y1, double x2, double y2, double x3, double y3){

    if(stupid_angle(x1,y1,x2,y2,x3,y3) == 1) return 1;
    if(stupid_angle(x2,y2, x1, y1,x3,y3) == 1) return 2;
    if(stupid_angle(x3,y3, x1, y1, x2, y2) == 1) return 3;
    return -1;
}

void second_step1(double x1, double y1, double x2, double y2, double x3, double y3){

    double xm = (x1 + x2) / 2.;
    double ym = (y1 + y2) / 2.;

    double yc1 = ym + (x1 - x2) * sqrt(3) / 2.;
    double xc1 = xm + (y2 - y1) * sqrt(3) / 2.;

    double yc2 = ym - (x1 - x2) * sqrt(3) / 2.;
    double xc2 = xm - (y2 - y1) * sqrt(3) / 2.;

    cout << setprecision(2) << xc1 << " " << yc1 << " ; " << xc2 << " " << yc2 << endl;

    if((x3-xc1)*(x3-xc1)+(y3-yc1)*(y3-yc1) >= (x3-xc2)*(x3-xc2)+(y3-yc2)*(y3-yc2)){
        c1 += xc1*1.0; c2 += yc1*1.0;
    }
    else{
        c1 += xc2*1.0; c2 += yc2*1.0;
    }
}

void second_step2(double x1, double y1, double x2, double y2, double x3, double y3){

    double xm = (x1 + x2) / 2.;
    double ym = (y1 + y2) / 2.;

    double yc1 = ym + (x1 - x2) * sqrt(3) / 2.;
    double xc1 = xm + (y2 - y1) * sqrt(3) / 2.;

    double yc2 = ym - (x1 - x2) * sqrt(3) / 2.;
    double xc2 = xm - (y2 - y1) * sqrt(3) / 2.;

    cout << setprecision(2) << xc1 << " " << yc1 << " ; " << xc2 << " " << yc2 << endl;

    if((x3-xc1)*(x3-xc1)+(y3-yc1)*(y3-yc1) >= (x3-xc2)*(x3-xc2)+(y3-yc2)*(y3-yc2)){
        t1 += xc1*1.0; t2 += yc1*1.0;
    }
    else{
        t1 += xc2*1.0; t2 += yc2*1.0;
    }
}

int main(){

    ifstream fin("input.txt");
    ofstream fout("output.txt");

    double a1, a2, a3, b1, b2, b3;
    fin >> a1 >> b1 >> a2 >> b2 >> a3 >> b3;
    fout << a1 << ' ' << b1 << ' ' << a2 << ' ' << b2 << ' ' << a3 << ' ' << b3 << ' ';
    if(first_step(a1,b1,a2,b2,a3,b3) == -1){

        second_step1(a1, b1, a2, b2, a3, b3);
        second_step2(a2, b2, a3, b3, a1, b1);

        double k1 = (b3-c2)/(a3-c1), k2 = (b1-t2)/(a1-t1), b_1 = c2 - k1*c1, b_2 = t2 - k2*t1;

        cout << setprecision(2) << c1 << " " << c2 << " ; " << t1 << " " << t2 << endl;
        fout << (b_1-b_2)/(k2-k1) << ' ' << k1*((b_1-b_2)/(k2-k1))+b_1;

    }
    else if(first_step(a1,b1,a2,b2,a3,b3) == 1){
        fout << a1 << ' ' << b1;
    }
    else if(first_step(a1,b1,a2,b2,a3,b3) == 2){
        fout << a2 << ' ' << b2;
    }
    else if(first_step(a1,b1,a2,b2,a3,b3) == 3){
        fout << a3 << ' ' << b3;
    }
}
