#include<bits/stdc++.h>
using namespace std;

// S Single Responsibility Principle
//      A class should have only one reason to change (i.e. only single responsibility).

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
     Marker *marker;
     int quantity;
     
     public:
     Invoice(Marker *marker,int quantity){
        this->marker=marker;
        this->quantity=quantity;
     }

     int calculateTotal(){
        int price = (marker->price)*(this->quantity);
        return price;
     }
};


class InvoiceDao{
    private:
    Invoice *invoice;
    public:
    InvoiceDao(Invoice *invoice){
        this->invoice=invoice;
    }
    void saveToDB(){
        // Save to DB
    }
};


class InvoicePrinter{
    private:
    Invoice *invoice;
    public:
    InvoicePrinter(Invoice *invoice){
        this->invoice=invoice;
    }

    void print(){
        // Print the Invoice
    }

};