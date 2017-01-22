#include <iostream> 
using namespace std;
 
class Shape {
   protected:
      int width, height;
		
   public:
      Shape(int a ,int b) {
         width = a;
         height = b;
      }
      
//virtual keyword used in the parent class method to do dynamic linking-
//i.e function to be called at any given point in the program to be based on the kind of object for which it is called		
      virtual int area() {
         cout << "Parent class area :" <<endl;
         return 0;
      }
};

class Rectangle: public Shape {
   public:
   	//constructor
      Rectangle( int a , int b ):Shape(a,b) { }
      int area () { 
         cout << "Rectangle class area :" <<width * height<<endl;
         Shape::area();//scope Resolution operator , call area() method within the scope of Shape class-helps in overloading and avoiding ambiguity errors
        
      }
};

class Triangle: public Shape{
   public:
      Triangle( int a , int b ):Shape(a,b) { }
      int area () { 
         cout << "Triangle class area :" <<width * height / 2<<endl;
          
      }
};

// Main function for the program
int main( ) {
   Shape *shape;
   Rectangle rec(10,7);
   Triangle  tri(10,5);
   
   
   // store the address of Rectangle
   shape = &rec;
	
   // call rectangle area.
   //dynamic linkage based on the type of object passed for the overloaded function
   shape->area();

   // store the address of Triangle
   //dynamic linkage based on the type of object passed for the overloaded function
   shape = &tri;
	
   // call triangle area.
   shape->area();
   
   return 0;
}

