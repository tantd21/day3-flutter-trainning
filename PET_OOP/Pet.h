#ifndef _PETMANAGEMENT_PET_H_
#define _PETMANAGEMENT_PET_H_
#include <bits/stdc++.h>
using namespace std;
class Pet
{
private:
    int id;
    std::string name;
    float weight;
    std::string color;
    int age;

public:
    Pet()
    {
        id = 0;
        name = "";
        weight = 0.0;
        color = "";
        age = 0;
    };
    Pet(int _id, std::string _name, float _weight, std::string _color, int _age)
    {
        id = _id;
        name = _name;
        weight = _weight;
        color = _color;
        age = _age;
    };
    virtual bool eat(std::string) = 0;
    void ShowMe()
    {
        cout << "Pet name: " << name  << "| " << "Pet weight: " << weight << "| " << "Pet color: " << color << "| "<< "Pet age: " << age << std::endl;
         cout << "--------------------------------------: " << std::endl;
    };
    virtual  void makeSound();
    float getWeight()
    {
        return weight;
    };
    void setWeight(float _weight)
    {
        weight += _weight;
    };
};
#endif