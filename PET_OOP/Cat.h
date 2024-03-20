#ifndef _CAT_PET_H_
#define _CAT_PET_H_
#include "Pet.h"
class Cat : public Pet
{

public:
    Cat(){};
    Cat(int _id, std::string _name, float _weight, std::string _color, int _age):Pet( _id,  _name, _weight, _color, _age){}
    void makeSound()
    {
        cout << "Meow Meow Doan Tan" << endl;
    }
    bool eat(string food)
    {
       if (food == "ca")
        {
            this->setWeight(0.3);
            cout<<"No !!Thuc an ngon. Meo Meo"<<endl;
            return true;
        }
        cout<<"DOI !!Thuc an cua Meo khong dung."<<endl;
        return false;
    }
};

#endif