#ifndef _FARM_FUNCTION_H_
#define _DOG__FARM_FUNCTION_H_PET_H_
#include "Pet.h"
#include "Dog.h"
#include "Cat.h"
#include "Chicken.h"
#include "Pig.h"
#include <bits/stdc++.h>
class Farm_function
{

public:
    std::vector<Pet *> createPets();
   
    void doFoodPets(std::vector<Pet * > pets, std::vector<string> food);
   
    void makeSoundPets(std::vector<Pet *>);
};

#endif
