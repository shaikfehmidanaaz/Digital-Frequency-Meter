#include <iostream>
#include <iomanip>
using namespace std;

class DigitalFrequencyMeter {
private:
    double timePeriod;   // Time period in seconds

public:
    DigitalFrequencyMeter(double period) {
        timePeriod = period;
    }

    double calculateFrequency() {
        if (timePeriod <= 0) {
            return 0;
        }

        return 1.0 / timePeriod;
    }

    void displayResult() {
        double frequency = calculateFrequency();

        cout << "\n====================================\n";
        cout << "       DIGITAL FREQUENCY METER\n";
        cout << "====================================\n";

        cout << fixed << setprecision(4);

        cout << "Time Period : " << timePeriod << " seconds\n";
        cout << "Frequency   : " << frequency << " Hz\n";

        if (frequency >= 49 && frequency <= 51) {
            cout << "Status      : NORMAL (50 Hz)\n";
        }
        else {
            cout << "Status      : FREQUENCY DEVIATION\n";
        }

        cout << "====================================\n";
    }
};

int main() {

    double period;

    cout << "Enter time period of input signal (seconds): ";
    cin >> period;

    if (period <= 0) {
        cout << "Invalid time period!" << endl;
        return 1;
    }

    DigitalFrequencyMeter meter(period);

    meter.displayResult();

    return 0;
}
