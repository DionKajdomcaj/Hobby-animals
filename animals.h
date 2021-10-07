#ifndef ANIMALS_H_INCLUDED
#define ANIMALS_H_INCLUDED
#pragma once
#include<iostream>
#include "keeper.h"
using namespace std;
class Animals{
protected:
    string name;
    int exhilaration;
    Animals(const string &n, int exhlevel): name(n), exhilaration(exhlevel){}
public:
    string getName(){return name;}
    int getExhilaration(){return exhilaration;}
    void modExh(int exhlevel){exhilaration+=exhlevel;}
    bool isAlive(){return exhilaration>0;}
    virtual ~Animals(){}
    virtual void takeCare(Keeper* &k)=0;
};
class Fish : public Animals{
public:
    Fish(const string& name,int exhlevel) : Animals(name,exhlevel){}
    void takeCare(Keeper* &k) override{
        k=k->takeCare(this);
    }
};
class Dog : public Animals{
public:
    Dog(const string& name, int exhlevel): Animals(name,exhlevel){}
        void takeCare(Keeper* &k) override{
        k=k->takeCare(this);
    }
};
class Bird : public Animals{
public:
    Bird(const string& name, int exhlevel): Animals(name,exhlevel){}
        void takeCare(Keeper* &k) override{
        k=k->takeCare(this);
    }
};
#endif // ANIMALS_H_INCLUDED

