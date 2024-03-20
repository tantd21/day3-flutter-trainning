#ifndef _PIG_PET_H_
#define _PIG_PET_H_
#include "Pet.h"
class Pig : public Pet
{

public:
    Pig(){};
    Pig(int _id, std::string _name, float _weight, std::string _color, int _age):Pet( _id,  _name, _weight, _color, _age){}
    void makeSound()
    {
        cout << "ECCC... ECCC... ECCC... Doan Tan" << endl;
    }
    bool eat(string food)
    {
        if (food == "rau")
        {
            this->setWeight(1.0);
             cout<<"No !!Thuc an ngon. Mam Mam"<<endl;

            return true;
        }
        cout<<"DOI !!Thuc an cua Heo khong dung."<<endl;
        return false;
    }
};

#endif