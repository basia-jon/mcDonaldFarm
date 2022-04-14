#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>


using namespace std;

int main()
{
    int fence_length;
    int a;
    int b;
    float farm_area;
    string str;
 

    do {
        cout << "In order to start type - RUN\n";
        cin >> str;
    } while (str.compare("RUN") != 0);


    bool valid_input = false;
    while (!valid_input) {
        cout << "How many meters of fence is available (3-"<< INT_MAX<< "): ";
        cin >> fence_length; 
        if (cin.fail()) {
            cout << " wrong input, not an integer \n";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (fence_length < 3) {
            cout << " wrong input, fance lenght must be at least 3 meters\n";
            continue;
        }
        valid_input = true;
    }

    // dlugosc siatki: d=2a+b; b=d-2*a;
    // pole dzialki: y = a*b; 
    // y=a*(d-2a); y=ad-2a^2
    // y'=d-4a
    // d-4a=0; d=4a; a=d/4
    // najbardziej optymalne pole otrzymamy dla a=25% dlugosci siatki, b=50% dlugosci siatki   
    
    a = round((float)fence_length/4);
    b = fence_length -2*a;
    cout << " fence segment a = " << a << " meters\n";
    cout << " fence segment b = " << b << " meters\n";
    
    farm_area = (float)a*b;
    cout << " area of McDonald's farm = " << std::fixed << std::setprecision(0) << farm_area << " square meters\n";

    return 0;
}

