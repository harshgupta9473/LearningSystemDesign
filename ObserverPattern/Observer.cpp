#include<bits/stdc++.h>
using namespace std;

// Observer is a behavioral design pattern that lets you define a subscription mechanism 
// to notify multiple objects about any events that happen to the object they’re observing.


// Subscriber interface (Observer)
class Subsriber {
    public:
    virtual void update(string &message)=0;
    virtual ~Subsriber(){}
};

// Publisher interface (Subject)
class Publisher{
    public:
    virtual void subscribe(Subsriber *sub)=0;
    virtual void unsubscribe(Subsriber* sub)=0;
    virtual void notifySubscribers(string &messgae)=0;
    virtual ~Publisher(){}
};


// Concrete Publisher
class NewsPublisher:public Publisher{
    vector<Subsriber*>subscribers;
    public:
    void subscribe(Subsriber* sub)override{
        subscribers.push_back(sub);
    }
    void unsubscribe(Subsriber* sub)override{
        subscribers.erase(remove(subscribers.begin(),subscribers.end(),sub),subscribers.end());
    }
    void notifySubscribers(string &messgae){
        for(auto sub:subscribers){
            sub->update(messgae);
        }
    }
    void publishNews(string &news){
        cout<<"Publisher: "<<news<<endl;
        notifySubscribers(news);
    }
};


// Concrete Subscribers

class EmailSubscriber:public Subsriber{
    string email;
    public:
    EmailSubscriber(string e):email(e){}
    void update(string &message)override{
        cout<<"email sent to "<<email<<"with news: "<<message<<endl;
    }
};


class SMSSubscriber : public Subsriber{
    string phone;
    public:
    SMSSubscriber(string p):phone(p){}
    void update(string & message)override{
        cout<<"SMS sent to "<<phone<<" with news: "<<message<<endl;
    }
};


int main(){
    NewsPublisher publisher;
    EmailSubscriber emailSub("harsh9473@gmail.com");
    SMSSubscriber smsSub("9999999999999");
    publisher.subscribe(&emailSub);
    publisher.subscribe(&smsSub);
    string n1="Breaking News: C++ Observer Pattern Simplified!";
    string n2="Sports Update: India won the match!";
    publisher.publishNews(n1);
    publisher.publishNews(n2);
};
