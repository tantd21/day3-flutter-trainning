#ifndef _CHICKEN_PET_H_
#define _CHICKEN_PET_H_
#include "Pet.h"
class Chicken : public Pet
{

public:
    Chicken(){};
    Chicken(int _id, std::string _name, float _weight, std::string _color, int _age):Pet( _id,  _name, _weight, _color, _age){}
    void makeSound()
    {
        cout << "OH... OH... OH... Doan Tan" << endl;
    }
    bool eat(string food)
    {
        if (food == "thoc")
        {
            this->setWeight(0.2);
            cout<<"No !!Thuc an ngon. Cuc tack"<<endl;
            return true;
        }
        cout<<"DOI !!Thuc an cua Ga khong dung."<<endl;
        return false;
    }
};

#endif