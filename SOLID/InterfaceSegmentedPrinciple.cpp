#include<bits/stdc++.h>
using namespace std;


// I Interface Segmented Principle
// Interfaces should be such that client should not implement unnecessary functions they do not need.


// example voilating Interface Segmented Principle

class RestaurantEmployee{
    public:
    virtual void washDishes()=0;
    virtual void serveCustomers()=0;
    virtual void cookFood() =0;
};

// Here the waiter class still has to implement cookFood which is not the work of the waiter

class waiter: public RestaurantEmployee{
    public:
    void washDishes() override{
        // not my job
    }

    void serveCustomers() override{
        // yes and here is my implemetation

    }

    void cookFood() override{
        // not my job
    }

};


// correct examples

class WaiterInterface {
    virtual void serveCustomers()=0;
    virtual void takeOrder()=0;
};


class ChefInterface{
    virtual void cookFood()=0;
    virtual void decideMenu()=0;
};


class Waiter:public WaiterInterface{
    public:
    void serveCustomers() override{
        // serving cutomers
    }

    void takeOrder() override{
        // taking order
    }
};

class Chef:public ChefInterface{
    void cookFood()override{
        // cooking food
    }
    void decideMenu() override{
        // decideMenu
    }
};

