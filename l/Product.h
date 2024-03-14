#include<string>
using namespace std;
class Product
{
private:
    string name;
    float *price;
    int quantity;
public:
    Product();
    Product(string _name, float _price, int _quantity);
    void setPrice(float _price);
    float getPrice();
    void displayProduct();
};


// Method to get price

