#include <iostream>
#include <string>

using namespace std;

class Animal {
public :
    Animal(const std::string _name){
        name = _name;
        std::cout << name << " was created!" << std::endl;
        age = 0;
    }

    void grow() {
        age++;
        std::cout << name << " grew up to " << age << std::endl;
    }

    virtual void sound() = 0;

private :
    std::string name;
    int age;
};

class Dog : public Animal {
public :
    Dog() : Animal("Dog") {}
    void sound() { std::cout << "wal! wal!" << std::endl; }
};

class Cat : public Animal {
public :
    Cat() : Animal("Cat") {}
    void sound() { std::cout << "nya~o~ng" << std::endl; }
};

int main()
{
    //cout << "Hello World!" << endl;

    Dog dog1;
    dog1.grow();
    dog1.grow();
    std::cout << std::endl;

    Cat cat1;
    cat1.grow();
    cat1.grow();
    cat1.grow();
    cat1.grow();
    cat1.grow();
    std::cout << std::endl;

    return 0;
}
