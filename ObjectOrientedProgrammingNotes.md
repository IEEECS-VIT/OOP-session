# Object Oriented Programming :

This Paradigm was introduced to make the programs more developer friendly and readable.

A programming paradigm is a style or “way” of programming

[Steve Jobs on OOP](https://www.youtube.com/watch?v=2kjtQnPqq2U)


## Class
 - Class is nothing but a `data-type`
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

## Constructor :

A method which has no return type and the same name of the class.

The constructors are called when we create an object of the class.
```
class class_name {
private:
	int age ;
	string status;
public:
	class_name() {
		age = 19;
		status = "Student";
		//constructor definition
	}
}
```
Constructor cannot be called in the program manually.

## Why use constructors ?
To initialize the properties of the class.

Constructor can only be specified in the public domain.

Because if it is defined in the private domain it cannot be accessed by the function outside the class definition

### Overloading a constructor

Constructor can be overloaded and according to its definition , parameters can be passed in the object initialization.

Default constructor is added only when we don't define an overloaded constructor.

* Example
	#### class definition
	```
	class student {
	string name;
	string school;
	public :
		Student(string name) {
			cout<<"Hi ! My name is "<<name;
		}
	}
	```
	#### object initialization
	```
		student aditya ;
		// Throws an Error as no default constructor defined (without parameters)

	```
## Destructors

A destructor is a special member function of the class which is executed whenever the object if the class goes out of scope or whenever a delete expression is applied to the pointer that points to the object of that class

```
class student {
public :
	~ student() {
		//  Statement we want to execute before releasing all the memeory assigned to the object
	}
}
```

- A destructor cannot take any argument and cannot return any values

```
 student *aditya;
 aditya = new student();
```
- On Executing the code above destructor wont be called.4
```
	delete aditya;
```
- Destructor will be called as we deleted the object pointer.

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
## Friend Function and Friend class

- A C++ friend functions are special functions which can access the private members of a class. They are considered to be a loophole in the Object Oriented Programming concepts, but logical use of them can make them useful in certain cases.

```
class Child
{
//Mother class members can access the private parts of class Child.
friend class Mother;
private:
	string name;

public:

  string name( void );
	friend void display(Child name); // Friend Function
protected:

  void setName( string newName );
};
```
- We can also make a class friend of another class
```
	friend class classname;
```

## Inheritance

- Inheritance is the capability of one class to acquire properties and characteristics from another class.
- The class whose properties are inherited by other class is called the Parent or Base or Super class. And, the class which inherits properties of other class is called Child or Derived or Sub class.

- Inheritance makes the code reusable.
- When we inherit an existing class, all its methods and fields become available in the new class, hence code is reused.

* NOTE : All members of a class except Private, are inherited

### Generic code
```
class <Parent_classname> {
		public :
			rt func1();
			rt func2();
};
class <Child_classname> : public/protected <Parent_classname> {
	public :
		rt func3();
};

int main()
{
	Child_classname object;
	object.func1();
	object.func2();
	object.func3();
}
```
### Protected Access Specifier :

- The member variables and member functions are availabe inside the class and they are also availabe in the subclass which inherits them but not availabe outside these classes

```
class parentClass {
	protected :
		string name;
	public :
		void setName(string Names) {
name = Names;
}
};

class childClass : public parentClass{
	public:
		void giveName() {
		cout<< name <<endl;
	}
};
int main()
{
	childClass childobj;
	cout<<childobj.name;
	//Error because protected
	childobj.setName("Aditya");
	childobj.giveName();
}
```
## Memebers and their Accessibility



|	[x]		|Public		|Protected		|Private  |
|--------|-----------|--------|------|
|sameClass	|	YES		|	YES			|	YES	  |
|derievedClass|YES		|	YES			|	NO	  |
|outsideClass  |YES		|	NO		| 	NO	  |

## Types of Inheritance

### Public inheritance

- In this type of inheritance the access-specifier public is used while inheriting

- In this type of inheritance the public memebers of the base class become the public member of the derieved class and the protected and private  memebers become protected and private respectively.

Generic Code :

```
class baseClass {
protected :
	int age;
public :
	string name;
private :
	string password;
}

class derievedClass : public baseClass {

}

int main() {
	derievedClass derObj;
	cout<<derObj.name; // No Error
	cout<<derObj.age; // Error
	cout<<derObj.password; // Error
}
```
### Protected inheritance

- In this type of inheritance the access-specifier public is used while inheriting

- In this type of inheritance the public and Protected memebers of the base class become the protected member of the derieved class and the private  memebers become private .

Generic Code :

```
class baseClass {
protected :
	int age;
public :
	string name;
private :
	string password;
}

class derievedClass : protected baseClass {

}

class subDerievedClass : public derievedClass {
	public :
	void printAttributes() {
		cout<<age;	//No Error
		cout<<name;//No Error
		cout<<password;//Error
	}
}

int main() {
	derievedClass derObj;
	cout<<derObj.name; // Error
	cout<<derObj.age; // Error
	cout<<derObj.password; // Error
}
```
### Private inheritance

- In this type of inheritance the access-specifier private is used while inheriting

- In this type of inheritance the public protected and private memebers of the base class become the private members of the derieved class.

Generic Code :

```
class baseClass {
protected :
	int age;
public :
	string name;
private :
	string password;
}

class derievedClass : private baseClass {
		public :
		void printAttributes() {
		cout<<age;	// Error
		cout<<name;// Error
		cout<<password;//Error
	}
}


int main() {
	derievedClass derObj;
	cout<<derObj.name; // Error
	cout<<derObj.age; // Error
	cout<<derObj.password; // Error
}
```
- NOTE : If no accesss-specifier is mentioned , then by default the inheritance will be considered as private

### Memebers Accessibility after Inheritance

* Rows -> Inheritance
* Columns -> Memebers

|	[x]		|Public		|Protected		|Private  |
|--------|-----------|--------|------|
|Public	|	Public		|	Protected			|	Private	  |
|Protected|Protected		|	Protected			|	Private	  |
|Private  |Private		|	Private		| 	Private	  |


### Multiple Inheritance

- Inheriting from two or more classes
- The Base class is going to contain the properties of both the classes

Generic Code :

```
class A_baseClass {
public :
	string vodaphone_number="5678";
	void callVNumber () {
		cout<<"Calling ..."<<vodaphone_number;
	}
}

class B_baseClass {
public:
	string jio_number="1234";
	void callJNumber () {
		cout<<"Calling ..."<<jio_number;
	}
}

class user : public A_baseClass , B_baseClass {

}


int main() {
	user userObj;
	userObj.callVNumber();
	userObj.callJNumber();
}
```
### Changing the Access Level

- By changing the Access declaration we can change the access level or the scope of the member of the base class in derieved class.

Generic Code :

```
class derievedClass : private baseClass {
		public :
		baseClass :: password ;
}

int main() {
	baseClass baseObj;
	derievedClass derObj;
	cout<<baseObj.password; // Error
	cout<<derObj.password; //No Error
}
```
- In the above code we changed the accessibility of password(protected Attribute) in the base class by using Scope resolution operator.

### Order of Execution of Constructors and Destructors in Inheritance

- By changing the Access declaration we can change the access level or the scope of the member of the base class in derieved class.

Generic Code :

```
class baseClass {
public :
	baseClass() {
	cout<<"Base-Class Constructor\n";
	}
	~ baseClass() {
	cout<<"Base-Class Destructor\n";
	}
}

class derievedClass : private baseClass {
public :
		derievedClass() {
		cout<<"Derieved-Class Constructor\n";
		}
		~ derievedClass() {
		cout<<"Derieved-Class Destructor\n";
		}
}


int main() {
	derievedClass derObj;
}
```
Output :
```
Base-Class Constructor
Derieved-Class Constructor
Derieved-Class Destructor
Base-Class Destructor
```
### Calling the Constructor of the baseClass from the Derieved Class

- The baseClass constructor can be called from the derieved class and the values from the baseClass can be initialized.
- If there is multiple inheritance , multiple base class constructors can be called.

Generic Code :

```
class A_baseClass {
public :
	string vodaphone_number;
	A_baseClass (string vNumber) {
		vodaphone_number = vNumber;
	}
	void callVNumber () {
		cout<<"Calling ..."<<vodaphone_number;
	}
}

class B_baseClass {
public:
	string jio_number;
	B_baseClass (string jNumber) {
		jio_number = jNumber;
	}
	void callJNumber () {
		cout<<"Calling ..."<<jio_number;
	}
}

class user : public A_baseClass , B_baseClass {
	public :
		user(string vNumber,string jNumber):A_baseClass(vNumber),B_baseNumber(jNumber) {
		cout<<"user Construc"
	};

}


int main() {
	user userObj("1234","5678");
}
```
- In the above code , first the A_baseClass constructor will be called and the value of v_Number will be initialized.
- Then the B_baseClass will be called and jNumber will be initialized
- The initialization is done using the initialization of derieved class object.

## Overriding

- We can have 2 methods , 1 in base class and 1 in derieved class with the same signature

- The method in the base class will be over-ridden by the method in the derieved class

Generic Structure
```
class Employee {
public :
 	int getSalary() {
		salary = 300000;
		return salary;
	}
};

class SeniorDeveloper : public Employee {
public:
	int getSalary() {
		salary = 2000000;
		return salary;
	}
}

int main()
{
	SeniorDeveloper aditya ;
	cout<<aditya.getSalary();
}
```
* Output
```
2000000
```
- In the above code the SeniorDeveloper Class(Derieved) is inheriting from the Employee class and overriding the salary function

#### Accessing the over-ridden method

```
aditya.Employee::getSalary();
```
* Output
```
300000
```
- The method can also be accessed in derieved class

```
  // In derieved class
  Employee::getSalary();
```
## `this` Pointer

- Every Object in C++ has access to its own address through `this` pointer

- `this` pointer is an implicit parameter to all the member functions

- Note : Friend functions don't have a `this` pointer because they are not the member functions of the class

- In Simple terms `this` pointer contains address of the object

- Code
```
	class Student {
	private:
		string name;
		string regNo;
	public:
		void setName(string name) {
			this->name = name;
			// name = name; Will throw a garbage value in name variable
			}
		void setReg(string reg_no) {
			regNo = reg_no;
			// Here C++ implicitly uses the this pointer to access regNo variable
			}
	}
```
