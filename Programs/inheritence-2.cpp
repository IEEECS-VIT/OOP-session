#include <iostream>
 
using namespace std;

// Base class
class Shape  {
   public:
      void setWidth() {
         cout<<"Enter the width"<<endl;
         cin>>width;
      }
		
      void setHeight() {
         
         cout<<"Enter the height"<<endl;
         cin>>height;
      }
		
   protected:
      int width;
      int height;
};

// Derived class
class Rectangle: public Shape {
   public:
      int getArea() { 
         return (width * height); 
      }
};

int main(void) {
//object for Rectangle class	
   Rectangle Rect;
   
 //Rect object accessing and using the parent Shape class members..
   Rect.setWidth();
   Rect.setHeight();

   // Print the area of the object.
   cout << "Total area: " << Rect.getArea() << endl;

   return 0;
}
