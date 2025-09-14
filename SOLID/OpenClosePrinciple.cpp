#include<bits/stdc++.h>
using namespace std;


// O - Open for extension but closed for modification
//       You can extend the methods but should not modify the existing tested live classes.



class Marker {
    public:
    string name;
    string color;
    int year;
    int price;

    public:
     Marker(string name,string color,int year,int price){
        this->name=name;
        this->color=color;
        this->year=year;
        this->price=price;
     }
};


class Invoice{
    // Invoice has has-a relationship with Marker (it has one instance of marker).
     Marker &marker;
     int quantity;
     
     public:
     Invoice(Marker &marker,int quantity):marker(marker), quantity(quantity){}

     int calculateTotal(){
        int price = (marker.price)*(this->quantity);
        return price;
     }
};


class InvoiceDao{
    public:
    virtual void save(Invoice *invoice)=0;
};

class DatabaseInvoiceDao:public InvoiceDao{
    public:
    void save(Invoice *invoice) override {
        // Save to DB
    }
};

class FileInvoiceDao:public InvoiceDao{
    public:
    void save(Invoice *invoice)override{
        // Save to file
    }
};