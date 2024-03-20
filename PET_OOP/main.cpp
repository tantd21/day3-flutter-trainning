#include "Pet.h"
#include "Dog.h"
#include "Cat.h"
#include "Chicken.h"
#include "Pig.h"
#include "Farm_function.h"
#include <bits/stdc++.h>

int main(){
    Farm_function farm_function;
    vector<Pet*> listPets = farm_function.createPets();
    for(Pet *pet : listPets){
        pet->ShowMe();
    } 
    vector<string> food = vector<string>{"ca","xuong","thoc","rau","thoc","ca"};
    farm_function.doFoodPets(listPets,food);
    cout<<"After do foofd for pets"<<endl;
    for(auto pet: listPets){
        pet->ShowMe();
    }
    cout<<"Pet sound:"<<endl;
    farm_function.makeSoundPets(listPets);
    return 0;
}