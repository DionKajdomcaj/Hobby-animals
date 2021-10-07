#ifndef KEEPER_H_INCLUDED
#define KEEPER_H_INCLUDED
#include<iostream>
class Fish;
class Dog;
class Bird;

using namespace std;
class Keeper{
public:
    virtual Keeper* takeCare(Fish* f)=0;
    virtual Keeper* takeCare(Bird* b)=0;
    virtual Keeper* takeCare(Dog* d)=0;
    virtual ~Keeper(){}

};
class Good : public Keeper{
public:
    static Good* moodins();
    Keeper* takeCare(Fish* f) override;
    Keeper* takeCare(Bird* b) override;
    Keeper* takeCare(Dog* d) override;
    static void clearptr();
protected:
    Good(){}
private:
    static Good* _moodins;

};
class Ordinary : public Keeper{
public:
    static Ordinary* moodins();
    Keeper* takeCare(Fish* f) override;
    Keeper* takeCare(Bird* b) override;
    Keeper* takeCare(Dog* d) override;
    static void clearptr();
protected:
    Ordinary(){}
private:
    static Ordinary* _moodins;

};
class Bad : public Keeper{
public:
    static Bad* moodins();
    Keeper* takeCare(Fish* f) override;
    Keeper* takeCare(Bird* b) override;
    Keeper* takeCare(Dog* d) override;
    static void clearptr();
protected:
    Bad(){}
private:
    static Bad* _moodins;

};
#endif // KEEPER_H
