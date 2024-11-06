#include <iostream>
#include <ctime>

using namespace std;

class Auto {
    string brand;
    double percentageOfFuel;
    bool onOffLights;
    int lightMod;
public:
    Auto() { // Конструктор за замовчуванням
        brand = "Renault";
        percentageOfFuel = 60;
        lightMod = 0;
    }
    Auto(string a, double b, int d) { // Конструктор
        brand = a; // з параметрами
        percentageOfFuel = b;
        lightMod = d;
    }

    void SetBrand(string a) {
        brand = a;
    }

    void SetPercentageOfFuel(double b) {
        percentageOfFuel = b;
    }

    string GetBrand() {
        return brand;
    }

    double GetPercentageOfFuel() {
        return percentageOfFuel;
    }

    int GetLightMod() {
        return lightMod;
    }

    void FillAuto(double a) {
        if ((percentageOfFuel + a) < 100) {
            percentageOfFuel += a;
            cout << "Current percentage of fuel: " << percentageOfFuel << endl;
        }
        else {
            cout << "Percentage of fuel can not be over than 100\nTry next time" << endl;
        }
    }

    void Drive() {
        if (lightMod == 0) {
            int fuelToFire = rand() % 25 + 1;
            percentageOfFuel -= fuelToFire;
        }
        else if (lightMod == 1) {
            double fuelToFire = rand() % 25 + 1;
            fuelToFire += fuelToFire * 0.1;
            cout << "fuelToFire: " << fuelToFire << ": " << fuelToFire / 10 << endl;
            percentageOfFuel -= fuelToFire;
        }
    }

    void Headlights() {
        if (lightMod == 0) {
            cout << "Your headlights are ON" << endl;
            lightMod++;
        }
        else if (lightMod == 1) {
            cout << "Your headlights are OFF" << endl;
            lightMod--;
        }
    }
};

void main() {
    srand(time(NULL));
    Auto obj;

    while (true)
    {
        cout << "1 -> Fill\n2 -> Drive\n3 -> Headlights\n";
        int result;
        cin >> result;
        if (result == 1) {
            obj.FillAuto(35);
        }
        else if (result == 2) {
            obj.Drive();
        }
        else if (result == 3) {
            obj.Headlights();
        }
        else {
            return;
        }

        cout << "Current percentage of fuel: " << obj.GetPercentageOfFuel() << endl;

        if (obj.GetPercentageOfFuel() <= 0) {
            cout << "Our auto is empty" << endl;
            break;
        }
    }
}