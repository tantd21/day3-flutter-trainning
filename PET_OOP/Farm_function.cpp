#include "Farm_function.h"
#include <vector>
  std::vector<Pet *> Farm_function::createPets(){
    Dog* dog = new Dog(1,"Doan Tan",5.0,"yellow",20);
    Cat* cat = new Cat(2,"Doan Tan",2.0,"black",1);
     Chicken* chicken = new Chicken(3,"Doan Tan Ga",1.0,"blue",4);
     Pig* pig = new Pig(4,"Doan Tan Map U",10.0,"pink",5);
     std::vector<Pet*> pets;
     pets.push_back(dog);
     pets.push_back(cat);
     pets.push_back(chicken);
     pets.push_back(pig);
     return pets;
  };
   
    void Farm_function::doFoodPets(std::vector<Pet * >pets, std::vector<string> food){
        for(auto pet: pets){
            for (int i = 0; i < food.size(); i++)
            {
                if(pet->eat(food[i])){
                    food[i]="";
                }
            }
            
        }
    };
   
    void Farm_function::makeSoundPets(std::vector<Pet *> pets){
        for(auto pet:pets){
            pet->makeSound();
            
        }
    };