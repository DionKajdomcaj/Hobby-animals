#include <iostream>
#include <vector>
#include <fstream>
#include<cstdlib>
#include"animals.h"
#include"keeper.h"
using namespace std;
void readData(const string file,vector<Animals*>&animals, vector<Keeper*>&moods){
    ifstream f;
    f.open(file.c_str());
    if(f.fail()){
        cout<<"Wrong filename"<<endl;
        exit(1);
    }
    else{
        int numofanim;
        f>>numofanim;
        if(numofanim==0){
            cout<<"There is no animals in the file name"<<endl;
        }
        else{
            for(unsigned int i=0;i<numofanim;i++){
                char l;
                string name;
                int exhlvl;
                f>>l>>name>>exhlvl;
                if(l=='B'){
                    animals.push_back(new Bird(name,exhlvl));
                }
                else if(l=='F'){
                    animals.push_back(new Fish(name,exhlvl));
                }
                else if(l=='D'){
                    animals.push_back(new Dog(name,exhlvl));
                }
            }
            string line;
            f>>line;
            char m;
            if(line.length()==0){
                cout<<"There are no moods"<<endl;
            }
            for(unsigned int j=0;j<line.length();j++){
                m=line[j];
                if(m=='g'){
                    moods.push_back(Good ::moodins());
                }
                else if(m=='o'){
                    moods.push_back(Ordinary ::moodins());
                }
                else if(m=='b'){
                    moods.push_back(Bad :: moodins());
                }


            }

        }
    }



}
int minSearch(vector<Animals*> animals){
    int min = animals[0]->getExhilaration();
    for(unsigned int i=1;i<animals.size();i++){
        if(animals[i]->isAlive() && animals[i]->getExhilaration()<min){
            min=animals[i]->getExhilaration();
        }

    }
    return min;
}
void takingCare(vector<Keeper*>moods, vector<Animals*>animals){
    try{
    for(unsigned int i=0;i<animals.size();i++){
        for(unsigned int j=0;j<moods.size();j++){
                if(animals[i]->isAlive()){
                    animals[i]->takeCare(moods[j]);
                }

        }
    }
    }
    catch(exception e){
        cout<<e.what()<<endl;
    }
    int minimum = minSearch(animals);
    cout<<"The animal/'s that are alive and have the minimum energy is/are: "<<endl;
    for(unsigned k=0;k<animals.size();k++){
        if(animals[k]->isAlive() && animals[k]->getExhilaration()==minimum){
            cout<<animals[k]->getName()<<" "<<animals[k]->getExhilaration()<<endl;
        }
    }



}
void clearAnim(vector<Animals*>animals){
    for(unsigned i=0;i<animals.size();i++){
        delete animals[i];
    }
}
void clearMoods(){
    Good ::clearptr();
    Ordinary ::clearptr();
    Bad ::clearptr();

}
int Testing(vector<Keeper*>moods, vector<Animals*>animals){;
    int counting=0;
    if(animals.size()==0){
        return counting;
    }
    if(moods.size()==0){
        return counting;
    }
    takingCare(moods,animals);
    int minimum = minSearch(animals);
     for(unsigned k=0;k<animals.size();k++){
        if(animals[k]->isAlive() && animals[k]->getExhilaration()==minimum){
            counting++;
        }
    }
    return counting;
}
//#define NORMAL_MODE
#ifdef NORMAL_MODE
int main()
{
    vector<Animals*>animals;
    vector<Keeper*>moods;
    readData("input.txt",animals,moods);
    takingCare(moods,animals);
    clearAnim(animals);
    clearMoods();

    return 0;
}
#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
TEST_CASE("1","regular"){
     vector<Animals*>animals;
    vector<Keeper*>moods;
    readData("input.txt",animals,moods);
    CHECK(Testing(moods,animals)==1);
}
TEST_CASE("2","0 animals"){
         vector<Animals*>animals;
    vector<Keeper*>moods;
    readData("input0.txt",animals,moods);
    CHECK(Testing(moods,animals)==0);

}
TEST_CASE("3","0 moods"){
    vector<Animals*>animals;
    vector<Keeper*>moods;
    readData("input1.txt",animals,moods);
    CHECK(Testing(moods,animals)==0);

}
TEST_CASE("4","2 minimal animals"){
    vector<Animals*>animals;
    vector<Keeper*>moods;
    readData("input2.txt",animals,moods);
    CHECK(Testing(moods,animals)==2);


}

#endif
