#ifndef _DOG_PET_H_
#define _DOG_PET_H_
#include "Pet.h"
class Dog : public Pet
{

public:
    Dog(){};
    Dog(int _id, std::string _name, float _weight, std::string _color, int _age):Pet( _id,  _name, _weight, _color, _age){}
    void makeSound()
    {
        cout << "GAU... GAU... GAU... Doan Tan" << endl;
    }
    bool eat(string food)
    {
        if (food == "xuong")
        {
            this->setWeight(0.8);cout<<"No !!Thuc an ngon. Gou gou"<<endl;
            return true;
        }
        cout<<"DOI !!Thuc an cua Cho khong dung."<<endl;
        return false;
    }
};

#endif