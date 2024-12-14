## Basic OOP Terminology
### James Steward
### 12/06/24
### 2143 OOP
### Description: 


# Object-Oriented Programming Primer

## Abstract Classes and Interfaces
### Definition
(Abstract classes and interfaces define templates for other classes but are not instantiated themselves. Abstract classes can include both complete and incomplete methods, while interfaces in C++ are handled using pure abstract classes.)
### Example

class Animal {
public:
    virtual void makeSound() = 0; // Pure virtual function
    void breathe() {
        std::cout << "I am breathing" << std::endl;
    }
};

1. Abstract Classes and Interfaces
Definition: Classes that cannot be instantiated directly. Abstract classes contain at least one pure virtual function. Interfaces are typically fully abstract classes with only pure virtual functions. Example:


class Shape {  // Abstract class
public:
    virtual void draw() = 0;  // Pure virtual function
};

class Drawable {  // Interface
public:
    virtual void render() = 0;
};
2. Abstraction
Definition: Hiding complex implementation details and exposing only the necessary components of a class or system. Example:


class Engine {
public:
    void start() { /* implementation hidden from the car */ }
};

class Car {
private:
    Engine engine;
public:
    void startCar() { engine.start(); }
};
3. Access Modifiers (Public, Private, Protected)
Definition: Keywords that set the accessibility of classes, methods, and attributes. Public items are accessible from anywhere, private items are accessible only within the class, and protected items are accessible within the class and its subclasses. Example:


class Box {
private:
    int length;
protected:
    int breadth;
public:
    int height;
};
4. Attributes / Properties
Definition: Characteristics or data members of a class that represent the state of an object. Example:


class Car {
    string color;  // Attribute
    int speed;     // Attribute
};
5. Class Variable
Definition: A variable that is declared within a class but outside any method and shared among all instances of the class. Example:


class Car {
public:
    static int numberOfCars;  // Class variable
};
6. Classes and Objects
Definition: A class is a blueprint for creating objects, providing initial values for state (member variables) and implementations of behavior (member functions or methods). An object is an instance of a class. Example:


class Dog {
public:
    void bark() { cout << "Woof!"; }
};

Dog myDog;  // Creating an object
myDog.bark();
7. Collections and Iterators
Definition: Collections are data structures that hold multiple items. Iterators are tools for sequentially accessing the elements of a collection. Example:


#include <vector>
#include <iostream>

int main() {
    std::vector<int> v = {1, 2, 3, 4, 5};
    for(auto it = v.begin(); it != v.end(); ++it) {
        std::cout << *it << " ";
    }
}
8. Composition
Definition: A design principle where a class is made up of other classes, indicating a has-a relationship. Example:


class Engine { /* Engine details */ };
class Car {
    Engine engine;  // Car has-an Engine
};
9. Constructors and Destructors
Definition: Constructors are special class functions which are executed whenever a new object of that class is created. Destructors are special class functions executed when an object is destroyed. Example:


class Box {
public:
    Box() { cout << "Constructor called!"; }
    ~Box() { cout << "Destructor called!"; }
};
10. Design Patterns (e.g., Singleton, Factory, Observer)
Definition: Standardized solutions to common software design problems.

Singleton: Ensures a class has only one instance and provides a global point of access to it.
Factory: Provides an interface for creating objects in a superclass, but allows subclasses to alter the type of objects that will be created.
Observer: A subject maintains a list of its dependents, called observers, and notifies them automatically of any state changes. Example (Singleton):

class Singleton {
private:
    static Singleton* instance;
    Singleton() {}
public:
    static Singleton* getInstance() {
        if (!instance)
            instance = new Singleton();
        return instance;
    }
};
Singleton* Singleton::instance = nullptr;
11. Encapsulation
Definition: The bundling of data with the methods that operate on that data, or the restriction of direct access to some of an object's components. Example:


class EncapsulatedObject {
private:
    int x;  // Data encapsulated within the class
public:
    void setX(int i) { x = i; }  // Public method to set the value of x
    int getX() { return x; }
};
12. Exception Handling
Definition: Mechanisms provided in many programming languages to handle the occurrence of exceptions, which are changes in the normal flow of a program due to errors. Example:


#include <iostream>
try {
    throw 20;  // Throw an error
} catch (int e) {
    std::cout << "An exception occurred. Exception Nr. " << e << std::endl;
}
13. File I/O in OOP
Definition: The process of reading from and writing to files using classes and objects in an OOP language. Example:


#include <fstream>
#include <iostream>
using namespace std;

int main() {
    ofstream myfile;
    myfile.open ("example.txt");
    myfile << "Writing this to a file.\n";
    myfile.close();
    return 0;
}
14. Friends
Definition: A function or another class declared with the friend keyword that can access private and protected members of another class. Example:


class MyClass {
private:
    int secret = 0;
public:
    friend void tellSecret(MyClass &m);  // Friend function
};

void tellSecret(MyClass &m) {
    std::cout << "The secret is " << m.secret;
}
15. Generics and Templates
Definition: Mechanisms that allow functions and classes to operate with generic types. This allows a function or class to work on many different data types without being rewritten for each one. Example:


template <typename T>
T add(T x, T y) {
    return x + y;
}
16. Inheritance
Definition: A mechanism by which a new class is derived from an existing class. The new class inherits all the properties and behaviors of the existing class. Example:


class Animal {
public:
    void eat() { cout << "I can eat!"; }
};

class Dog : public Animal {
public:
    void bark() { cout << "I can bark!"; }
};
17. Instance Variable
Definition: A variable defined in a class (i.e., a member variable), for which each instantiated object of the class has a separate copy. Example:


class Car {
public:
    int speed;  // Instance variable
};
18. Member Variable
Definition: A variable that is associated with a specific instance of a class and is accessible from all class functions. Example:


class Box {
public:
    int length;  // Member variable
};
19. Memory Management (Garbage Collection, Pointers)
Definition: Techniques and processes for allocating and deallocating memory in an application. Garbage collection automatically reclaims memory occupied by objects that are no longer in use. Pointers are used to access memory and manipulate addresses. Example:

cpp
Copy code
#include <iostream>
int main() {
    int* p = new int(10);  // Allocation
    std::cout << *p << std::endl;  // Use
    delete p;  // Deallocation
}
20. Method Overloading
Definition: The process of defining multiple methods in the same scope, with the same name but different parameters. Example:


class Print {
public:
    void show(int i) {
        std::cout << "Integer: " << i << std::endl;
    }
    void show(double f) {
        std::cout << "Float: " << f << std::endl;
    }
};
21. Method
Definition: Functions defined inside a class that operates on data members and performs actions. Methods help to execute the logic encapsulated by the class. Example:


class Box {
public:
    int calculateVolume() {
        return length * breadth * height;
    }
};
22. Multiple Inheritance
Definition: A feature of some OOP languages where a class can inherit from more than one parent class. Example:


class MusicalInstrument {
public:
    void play() { std::cout << "Playing instrument...\n"; }
};

class WoodenObject {
public:
    void burn() { std::cout << "Burning...\n"; }
};

class Guitar : public MusicalInstrument, public WoodenObject {
    // Inherits from both MusicalInstrument and WoodenObject
};
23. Multithreading in OOP
Definition: The capability of an OOP framework or language to support multiple threads of execution within the same application. Example:


#include <iostream>
#include <thread>

void function_1() {
    std::cout << "Thread 1 is running\n";
}

int main() {
    std::thread thread1(function_1);  // Create a thread running function_1
    thread1.join();  // Wait for thread1 to finish
    return 0;
}
24. Object Relationships (Association, Aggregation, Composition)
Definition:

Association: A relationship where all objects have their own lifecycle and there is no owner.
Aggregation: A specialized form of Association where all objects have their own lifecycle but there is ownership.
Composition: A strong Association where the lifecycle of the contained objects depends on the lifecycle of the container object. Example:

class Professor {};
class Department {
public:
    std::vector<Professor> professors;  // Composition: Department owns Professors
};
25. Object-Oriented Design Principles
Definition: Fundamental design principles that ensure scalability, reusability, and flexibility in a software application. Principles include Single Responsibility, Open/Closed, Liskov Substitution, Interface Segregation, and Dependency Inversion. Example: (Applying Single Responsibility Principle)


class Student {
public:
    void study() { std::cout << "Studying\n"; }
};

class StudentDatabase {
public:
    void addStudent(Student s) { /* add student to database */ }
};
26. Operator Overloading
Definition: The process of making an operator able to handle objects of custom types. This allows operators to be used in ways specific to the data model of the class. Example:


class Box {
public:
    int length, width, height;
    Box operator + (const Box& b) {
        Box box;
        box.length = this->length + b.length;
        box.width = this->width + b.width;
        box.height = this->height + b.height;
        return box;
    }
};
27. Overloading
Definition: Providing two or more definitions for a function or an operator in the same scope. Overloading allows the same function to process different types of arguments. Example:


void print(int i) { std::cout << "Here is an int: " << i << std::endl; }
void print(double f) { std::cout << "Here is a float: " << f << std::endl; }
28. Polymorphism
Definition: The ability of different classes to be treated as objects of a parent class, typically through the use of virtual functions, which are resolved at runtime. Example:


class Animal {
public:
    virtual void speak() { std::cout << "Some sound\n"; }
};

class Dog : public Animal {
public:
    void speak() override { std::cout << "Woof\n"; }
};

class Cat : public Animal {
public:
    void speak() override { std::cout << "Meow\n"; }
};
29. Public / Private / Protected
Definition: Access specifiers that control the visibility of members to other parts of the program. Example:


class Box {
private:
    int length;  // Only accessible within the class
protected:
    int breadth;  // Accessible within the class and derived classes
public:
    int height;  // Accessible from anywhere
};
30. SOLID Principles
Definition: A set of five principles that are aimed at making software designs more understandable, flexible, and maintainable.

S: Single Responsibility Principle
O: Open/Closed Principle
L: Liskov Substitution Principle
I: Interface Segregation Principle
D: Dependency Inversion Principle Example: (Open/Closed Principle)

class Shape {
public:
    virtual double getArea() = 0;
};

class Rectangle : public Shape {
private:
    double length, width;
public:
    Rectangle(double l, double w): length(l), width(w) {}
    double getArea() override {
        return length * width;
    }
};
31. Static (Methods and Variables)
Definition: Belong to the class, rather than any object instance. A static method can be called without creating an instance of the class. A static variable is shared by all instances of the class. Example:


class Math {
public:
    static int add(int x, int y) { return x + y; }
};
int Math::add(5, 3);  // Static method called without an object
32. Testing in OOP (Unit Testing, Test-Driven Development)
Definition: The practice of writing tests for the smallest parts of your application's code (unit tests), and developing software by writing the tests first and then the code to pass the tests (Test-Driven Development). Example:


#include <cassert>

void testAddition() {
    assert(Math::add(5, 3) == 8);
    std::cout << "Test passed.";
}

int main() {
    testAddition();
    return 0;
}
33. UML Diagrams and Modeling
Definition: Standardized diagrams and notations used to visually represent the design of a system. Example:




34. Virtual
Definition: A keyword in C++ that is used to allow a function or method to be overridden in a derived class. Example:


class Base {
public:
    virtual void show() { std::cout << "Base class"; }
};

class Derived : public Base {
public:
    void show() override { std::cout << "Derived class"; }
};
