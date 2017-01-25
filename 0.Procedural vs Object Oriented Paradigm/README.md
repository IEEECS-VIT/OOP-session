# Q1 ) Why Object Oriented Programming?
### ex- Say, we have to write a program :
### There are shapes on the UI a square , a circle and a triangle. When the user clicks on the shape ,the shape will rotate clockwise 360 degrees and play .flv file related to the shape?
#### How will the code be written in procedural programming paradigm?

```
// procedural approach
rotate(shapeNum){
  //rotate shape by 360
}
playSound(shapeNum){
  //use shape to look
  //which flv file to play, and play it
}

```
#### Now let's look the object oriented approach.
```
//OOP
class Circle
{
  rotate(){
    //
  }
  playSound(){

  }
  }
  class Triangle
  {
    rotate(){
      //
    }
    playSound(){

    }
    }

```

# Q2 ) What is Object Oriented Programming?
## Ans: For understanding this first we have to understand objects.
### So , what are objects ? Anyone?
### Yeah, Or any physical entity which has some property and perform some action is object. So now we know what are objects.
### Now lets see how we use these objects in Programming.
### Say,
```
// oop program
class rect{      // class definition

  int x;         // defining variables

  int y;

  public:         //access specifier
   void input(int a,int b){            //function to take input
     x=a;
     y=b;
   }

    void area(){                   //function for calculating area
       cout<<x*y;
    }
}
int main(){      //main function
  rect obj;
  int a = 5;
  int b = 10;
  obj.input(a,b);
  obj.area();

}

```
```
// procedural program
void area(int a, int b){
  cout<<a*b;  
}
void main(){
  int a=5;
  int b=10;
  area(a,b);
}
```
```


```
## Advantages of oop
1 It is more natural. Everything has a way of evolving.

2 We don't have retest the tested part of code.

3 Data and methods are together in one class.

4 Reusability of code.

5 Flexibilty to extend the code.
