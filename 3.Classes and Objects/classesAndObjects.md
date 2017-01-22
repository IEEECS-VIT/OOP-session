## Class
 -  A class in C++ is a `user defined` data type or data structure declared with keyword `class` that has data and functions (also called methods) as its members whose access is governed by the three access specifiers private, protected or public.
 - By default access to members of a class is private
 - When we declare class in global space it can be accessed by all the functions
 - A user Defined data type which allows us to group data and activites together
 - A class is a blue-print of a data-type and the object is a real world Scenario
 - Object is just a variable of a class


 ## Code

### Generic Structure
	class <class_name> {
	access_specifier :
		dt var_name;
		function def() {
		};
		rt undef_func();  
	};

## Object Definintion
  ```
  class_name <object_name>;

  ```
## Accessing Class-Functions and Class-Variables

  ```
    object_name.function_name();
    object_name.data_type();

  ```
## Access-specifiers

- The name of every class member (static, non-static, function, type, etc) has an associated "member access".
- When a name of the member is used anywhere a program, its access is checked, and if it does not satisfy the access       rules, the program does not compile
- All members of a class (bodies of member functions, initializers of member objects, and the entire nested class definitions) have access to all the names to which a class can access.
- A local class within a member function has access to all the names the member function itself can access.

  Code
```
      class Example {
        public: // all declarations after this point are public
          void add(int x) { // member "add" has public access
            n += x; // OK: private Example::n can be accessed from Example::add
            }
        private: // all declarations after this point are private
          int n = 0; // member "n" has private access
      };
      int main()
      {
        Example e;
        e.add(1); // OK: public Example::add can be accessed from main
        // e.n = 7;  // Error: private Example::n cannot be accessed from main
      }
```

## Accessing the memebers of the Object using Arrow `->` Operator

### Arrow Operator :

* The Arrow operator is used to access the values of the variables stored in the Heap Section of the memory

* The New keyword returns the address of the variable `object_name` which is created in the heap section of the memory.

* The -> Operator is used to derefrencce the address and fetch the value stored in the address.

* So the `->` is equivalent to `(*object_name).variable`


### Creating an Object-Pointer
```
	class * <object_name> = new <class_name>;
```
> The above code will use the new operator and allocate some space in the `free space` section of the memeory and return the address of the allocated space.

> The above code was implemented in C language using malloc function which was quite cumbersome and difficult to read . The `new` operator make reading and writing code easy and also gives a bunch of functionality on top of it.

### Accessing Class-Functions and Class-Variables
```
	object_name->function_name();
```

## Scope Resolution `::`  Operator

Scope resolution operator `::` is used to define a function outside a class or when we want to use a global variable but also has a local variable with same name.

```
	return_type class_name :: undef_func() {
		//function Definintion
	}
```
We cannot use the Scope resolution operator on a variable for initializing it unless and until it is defined `static`.

## Static KeyWord

### Using Static inside Function:

When we use static inside a function , that variable will be availabe through the function calls.

#### Example
```
void counterFunction() {
	static int counter = 0;
	cout<<"count = "<<count;
}

int main() {
	counterFunction();
	// counter =1
	counterFunction();
	// counter =2
	counterFunction();
	// counter =3
}
```
- Any variable store with the Static Keyword is Stored in the heap Section of the memory and can be shared by multiple function calls

### Using Static inside a Class

- Each object has its individual set of all the class variable .
-  But whenever a variable is stored as a static variable it can be shared between all its objects(instances)

#### As a class member

```
class classname {
	public:
		static int obj_number;
	classname() {
		obj_count ++;
		cout<<"Current Object count is "<<obj_count;
	}
};

// Defining static variable  after class definition is allowed

int classname :: obj_number =0;

int main()
{
	classname object_1 ;
	clasname object_2;
}
```
#### As class member functions:

```
static void objectCount() {
	cout<<obj_count<<endl;
}
```

- Whenever we create a static method , that method is going to have a class scope . So simply put , the method will be shared by all the classes

- Whenever we have a static method defined inside the class we can only use the static variable inside it.

For calling a Static method we can use a Scope resolution operator

```
classname::objectCount();
```
