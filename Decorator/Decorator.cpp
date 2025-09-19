#include<bits/stdc++.h>
using namespace std;



// Decorator is a structural design pattern that lets you attach new behaviors
// to objects by placing these objects inside special wrapper objects that contain the behaviors.

/*
What is the Decorator Pattern?

The Decorator Pattern is a structural design pattern that allows you to add new behaviors or responsibilities to objects dynamically, without modifying their class.
It’s like wrapping an object in another object.

Use case: When you want to extend functionality of objects at runtime (not by subclassing).

Example analogy: Think of a coffee. You can add milk, sugar, caramel dynamically. Each decorator adds new behavior without changing the base coffee class.

#Structure

) Component (interface/abstract class)
Defines the base interface for objects.

) Concrete Component
The core object that we want to decorate.

) Decorator (abstract)
Has a reference to a Component object and implements the same interface.

) Concrete Decorators
Add new responsibilities/behaviors.

*/


class Coffee{
    public:
    virtual string getDescription()=0;
    virtual double cost()=0;
    virtual ~Coffee(){}
};

class SimpleCoffee: public Coffee {
    public:
    string getDescription() override{
        return "Simple Coffee";
    }
     double cost() override{
        return 5.0;
     }
};


class CoffeeDecorator: public Coffee{
    public:
      Coffee* coffee;
      CoffeeDecorator(Coffee* c) : coffee(c) {}
      virtual ~CoffeeDecorator() { delete coffee; }
};


class MilkDecorator:public CoffeeDecorator{
    public:
    MilkDecorator(Coffee * c):CoffeeDecorator(c){};
    string getDescription() override{
        return coffee->getDescription()+", Milk";
    }
    double cost() override{
        return coffee->cost()+1.8;
    }
};


class SugarDecorator:public CoffeeDecorator{
    public:
    SugarDecorator(Coffee *c):CoffeeDecorator(c){};
    string getDescription() override{
        return coffee->getDescription()+", Sugar";
    }

    double cost() override{
        return coffee->cost()+0.5;
    }

};


class CaramelDecorator : public CoffeeDecorator {
public:
    CaramelDecorator(Coffee* c) : CoffeeDecorator(c) {}
    string getDescription() override {
        return coffee->getDescription() + ", Caramel";
    }
    double cost() override {
        return coffee->cost() + 2.0;
    }
};



int main(){
    Coffee * myCoffee=new SimpleCoffee();
    cout << myCoffee->getDescription() << " $" << myCoffee->cost() << endl;

     myCoffee = new MilkDecorator(myCoffee);

     myCoffee = new SugarDecorator(myCoffee);
      myCoffee = new CaramelDecorator(myCoffee);
      cout << myCoffee->getDescription() << " $" << myCoffee->cost() << endl;

    delete myCoffee;
    return 0;
}



