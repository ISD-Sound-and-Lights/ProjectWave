#include<cmath>
#include<iostream>
#include "rlutil.h"

using namespace std;
using namespace rlutil;

float temperature = 20;
float humidity = 25;
float pressure = 100.000;
float meters = NULL;
float sqr(float num){
    return pow(num,2);
}


float speedOfSound(float T, float Rh, float P){
    P=P*1000;
    float C = (0.603055*T + 331.5024 - sqr(T)*5.28*pow(10,-4) + (0.1495874*T + 51.471935 -sqr(T)*7.82*pow(10,-4))*((Rh*(3.14*pow(10,-8)*P + 1.00062 + sqr(T)*5.6*pow(10,-7))*(pow((2.71828182845904523536),(sqr(((273.15) + T))*1.2378847*pow(10,-5)-1.9121316*pow(10,-2)*((273.15) + T)))*pow((2.71828182845904523536),(33.93711047-6.3431645*pow(10,3)/((273.15) + T))))/P)/100.0)) + ((-1.82*pow(10,-7)+3.73*pow(10,-8)*T-sqr(T)*2.93*pow(10,-10))*P+(-85.20931-0.228525*T+sqr(T)*5.91*pow(10,-5))*(400.0*pow(10,-6))) - (sqr(((Rh*(3.14*pow(10,-8)*P + 1.00062 + sqr(T)*5.6*pow(10,-7))*(pow((2.71828182845904523536),(sqr(((273.15) + T))*1.2378847*pow(10,-5)-1.9121316*pow(10,-2)*((273.15) + T)))*pow((2.71828182845904523536),(33.93711047-6.3431645*pow(10,3)/((273.15) + T))))/P)/100.0))*2.835149 + sqr(P)*2.15*pow(10,-13) - sqr((400.0*pow(10,-6)))*29.179762 - 4.86*pow(10,-4)*((Rh*(3.14*pow(10,-8)*P + 1.00062 + sqr(T)*5.6*pow(10,-7))*(pow((2.71828182845904523536),(sqr(((273.15) + T))*1.2378847*pow(10,-5)-1.9121316*pow(10,-2)*((273.15) + T)))*pow((2.71828182845904523536),(33.93711047-6.3431645*pow(10,3)/((273.15) + T))))/P)/100.0)*P*(400.0*pow(10,-6)));
    return C;
}

int main(){
    cout << "Project wave"<<endl;
    while (true){
        rlutil::cls();

        cout <<"1. Change enviorment parameters\n2. Change scene parameters\n3. Calculate\n";

        char in = getch();

        if(in == '1'){
            string t_val = to_string(temperature);
            string h_val = to_string(humidity);
            string p_val = to_string(pressure);

            int select = 0;

            rlutil::cls();

            cout << "Temperature (C): ";
            cin >> temperature;
            cout << endl << "Humidity (%): ";
            cin >> humidity;
            cout<<endl << "Pressure (kPa): ";
            cin >> pressure;
            cout<<endl;

        }else if (in == '2'){
            cout << "Distance (meters): "<<endl;
            cin >> meters;
        }else if (in == '3'){
            if(meters == NULL){
                cout << "Please enter a distance!!"<<endl;
            }else{
                cout << "Calculating speed of sound...";
                float c = speedOfSound(temperature, humidity, pressure);
                cout << "Speed of sound calculated at " << c<<"m/s"<<endl;
                cout << "Calculating delay..."<<endl;
                float delay = meters / c;
                cout << "Delay is " << delay*1000 << "ms"<<endl;
                cout << "Press any key to continue..."<<endl;
                rlutil::anykey();
            }
        }
    }
}
