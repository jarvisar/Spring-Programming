#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
using std::setw;

double applied_voltage(double voltage, double freq,double t){
	double result;
	double w = 2 * M_PI * freq;
	result = voltage * sin(w*t);
	return result;
}

double amplitude(double freq,double voltage,double induct,double cappy,double resist){
	double result;
	double w = 2 * M_PI * freq;
	result = (w*voltage);
	result = result / sqrt((pow(induct*(w*w),2))+((resist*resist)*(w*w)));
	return result;
}

double phase_angle(double induct,double freq,double resist,double cappy){
	double result;
	double w = 2 * M_PI * freq;
	result = atan(((induct*w)/resist) - (1/(w * resist * cappy)));
	return result;
	
}

double total_current(double A, double freq, double t, double angle){
	double result;
	double w = 2 * M_PI * freq;
	result = A * sin((w*t) - angle);
	return result;
	
}

double resistor_voltage(double resist, double amplitude, double freq, double t, double angle){
	double result;
	double w = 2 * M_PI * freq;
	result = resist * amplitude * sin((w*t) - angle);
	return result;
}

double induct_voltage(double induct, double freq, double amplitude, double t, double angle){
    double result;
	double w = 2 * M_PI * freq;
	result = induct * w * amplitude * cos((w*t) - angle);
	return result;
}

double cappy_voltage(double amplitude, double freq, double cappy, double t, double angle){
    double result;
	double w = 2 * M_PI * freq;
	result = ((0 - amplitude)/(cappy * w)) * cos((w*t)-angle);
	return result;
}




int main() {
    double voltage;
    cin >> voltage;
    double freq;
    cin >> freq;
    double resist;
    cin >> resist;
    double induct;
    cin >> induct;
    double cappy;
    cin >> cappy;
    double nstep;
    cin >> nstep;
    double t;
    for (t=0;t<(1/freq)*2;t=t+((1/freq)/20)){
        cout << t << " " << applied_voltage(voltage,freq,t) << " " << total_current(amplitude(freq,voltage,induct,cappy,resist),freq,t,phase_angle(induct,freq,resist,cappy)) << " ";
		cout << resistor_voltage(resist, amplitude(freq, voltage, induct, cappy, resist), freq, t, phase_angle(induct, freq, resist, cappy)) << " ";
		cout << induct_voltage(induct, freq, amplitude(freq, voltage, induct, cappy, resist), t, phase_angle(induct, freq, resist, cappy)) << " ";
		cout << cappy_voltage(amplitude(freq, voltage, induct, cappy, resist), freq, cappy, t, phase_angle(induct, freq, resist, cappy)) << " ";
		cout << (applied_voltage(voltage,freq,t)) - (resistor_voltage(resist, amplitude(freq, voltage, induct, cappy, resist), freq, t, phase_angle(induct, freq, resist, cappy))+(induct_voltage(induct, freq, amplitude(freq, voltage, induct, cappy, resist), t, phase_angle(induct, freq, resist, cappy)))+(cappy_voltage(amplitude(freq, voltage, induct, cappy, resist), freq, cappy, t, phase_angle(induct, freq, resist, cappy)))) << endl;
    }
    
    return 0;
}
