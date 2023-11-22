#include <iostream>
#include <exception>

using namespace std;

class EngineProblem : public exception {};

class GarageProblem : public exception {};

class Motor {
public:
    void problem() const {
        throw EngineProblem();
    }
};

class Avtomobil {
private:
    Motor engine;
public:
    Avtomobil(Motor _engine = Motor()){
        engine = _engine;
    }
    const Motor& getEngine() const { return engine; }
    const void startEngine() const { engine.problem(); }
};

class Garaza {
private:
    Avtomobil vehicle;
public:
    Garaza() {
        try {
            vehicle = Avtomobil();
            vehicle.getEngine().problem();
        }
        catch (EngineProblem &engineProblem) {
            cout << "The car won't start" << endl;
            throw GarageProblem();
        }
    }
    const Avtomobil getCar() const { return vehicle; }
};

int main()
{
//    Garaza garage;
    try {
        Garaza garage = Garaza();
    } catch (GarageProblem& garageProblem) {
        cout << "There is something wrong in the garage" << endl;
    }
    cout << "" << endl;
    return 0;
}
