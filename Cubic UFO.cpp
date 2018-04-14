#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cassert>
#include <cmath>
using namespace std;
const double pi = std::acos(-1);

void face_centers(double xr, double zr)
{
    double x[] = {.5,0,0,};
    double y[] = {0,.5,0,};
    double z[] = {0,0,.5,};

    for (int i=0;i<3;++i)
    {
        // rotate about x
        double cosxr = cos(xr*pi/180.);
        double sinxr = sin(xr*pi/180.);
        // y' = y*cos q - z*sin q
        // z' = y*sin q + z*cos q
        double yp = y[i]*cosxr-z[i]*sinxr;
        double zp = y[i]*sinxr+z[i]*cosxr;
        
        // save rotated coords
        y[i] = yp;
        z[i] = zp;

        // rotate about z
        double coszr = cos(zr*pi/180.);
        double sinzr = sin(zr*pi/180.);
        // x' = x*cos q - y*sin q
        // y' = x*sin q + y*cos q
        double xp = x[i]*coszr-y[i]*sinzr;
        double ypp= x[i]*sinzr+y[i]*coszr;

        // save rotated coords
        x[i] = xp;
        y[i] = ypp;

        cout << (abs(x[i])<0.000001?0:x[i]) << " " << (abs(y[i])<0.000001?0:y[i]) << " " << (abs(z[i])<0.000001?0:z[i]) << "\n";
    }
}

int main () {
    // rotate by 0  degrees gets us to unit area 2 x 0.5
    // rotate to 45 degrees gets us to |2 area   2 x 0.707ish
    // read count
    auto count=0;
    cin >> count;

    for (int i=1;i<=count;++i)
    {
        // divide desired area by 2 and take sin-1
        double area;
        cin >> area;

        double angle = asin(area*area-1.) * 180. / pi / 2;

        cout.precision(12);
        //cout << "Area: " << area << " Angle: " << angle << endl;
        cout << "Case #" << i << ":\n";
        face_centers(angle, 0.);
    }
}