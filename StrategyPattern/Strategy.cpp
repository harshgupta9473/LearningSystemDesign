#include<bits/stdc++.h>
using namespace std;


// Strategy is a behavioral design pattern that lets you define a family of algorithms, put each of them into a separate class, and make their objects interchangeable.
// Link     https://refactoring.guru/design-patterns/strategy


// The Strategy pattern suggests that you take a class that does something specific in a lot of different ways and extract all of these algorithms into separate classes called strategies.

// The original class, called context, must have a field for storing a reference to one of the strategies. The context delegates the work to a linked strategy object instead of executing it on its own.

// The context isn’t responsible for selecting an appropriate algorithm for the job. Instead, the client passes the desired strategy to the context. In fact, the context doesn’t know much about strategies. It works with all strategies through the same generic interface, which only exposes a single method for triggering the algorithm encapsulated within the selected strategy.

// This way the context becomes independent of concrete strategies, so you can add new algorithms or modify existing ones without changing the code of the context or other strategies.



// Strategy Interface

class PaymentStrategy {
    public:
    virtual void pay(int amount)=0;
    virtual ~PaymentStrategy(){}
};

// Concrete Strategeies
class CreditCardPayment : public PaymentStrategy{
    string cardNumber;
    public:
    CreditCardPayment(string card):cardNumber(card){}
     void pay(int amount) override {
        cout << "Paid " << amount << " using Credit Card: " << cardNumber << endl;
    }
};



class UPIPayment : public PaymentStrategy{
    string upiId;
    public:
    UPIPayment(string id): upiId(id){}
    
    void pay(int amount) override {
        cout << "Paid " << amount << " using UPI: " << upiId << endl;
    }
};

class PayPalPayment : public PaymentStrategy {
    string email;
public:
    PayPalPayment(string mail) : email(mail) {}

    void pay(int amount) override {
        cout << "Paid " << amount << " using PayPal: " << email << endl;
    }
};




// Context

class ShoppingCart{
    PaymentStrategy *paymentStrategy;
    public:
    void setPaymentStrategy(PaymentStrategy *strategy){
        paymentStrategy=strategy;
    }
    void checkout(int amount){
        paymentStrategy->pay(amount);  // delegate to strategy
    }
};



int main() {
    ShoppingCart cart;

    CreditCardPayment credit("1234-5678-9876-5432");
    UPIPayment upi("harsh@upi");
    PayPalPayment paypal("harsh@gmail.com");

    cart.setPaymentStrategy(&credit);
    cart.checkout(500);

    cart.setPaymentStrategy(&upi);
    cart.checkout(1000);

    cart.setPaymentStrategy(&paypal);
    cart.checkout(1500);

    return 0;
}