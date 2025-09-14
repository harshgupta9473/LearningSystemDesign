#include<bits/stdc++.h>
using namespace std;


// L Liskove Substitution Principle
//     If  Class B is subtype of Class A, then we should be able to replace object of A with B without breaking the behaviour of the Program.
//    Subclass should  extend the capability of Parent class not narrow it down.



// // Violating Example

// class Bird{
//     public:
//     virtual void fly() = 0;
// };

// class Sparrow: public Bird{
//     public:
//     void fly() override{
//         // fly
//     }
// };

// class Ostrich: public Bird{
//     public:
//     void fly ()override{
//         // Problem: Ostrich Cannot fly!

//         // Ostrich is a Bird, but substituting it where a Bird is expected breaks the program because it throws an exception
//         // This violates Liskove Substitution Principle.
//         throw runtime_error("Ostrich cannot fly");
//     }
// };


// Correct Example


class Bird{
    public:
    virtual void eat()=0;
};

class FlyingBird:public Bird{
    public:
    virtual void fly()=0;
};

class Sparrow:public FlyingBird{
    public:
    void fly()override{
        cout<<"Sparrow is flying fast"<<endl;
    }
};

class Ostrich: public Bird{  // Ostrich does not inherit FlyingBird
    public:
    void eat()override{
        cout<<"ostrich is eating on ground"<<endl;
    }
};


