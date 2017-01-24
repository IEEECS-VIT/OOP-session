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
			return_type function_name();
			return_type function2_name();
};
class <Child_classname> : public/protected <Parent_classname> {
	public :
		return_type function3_name();
};

int main()
{
	Child_classname object_name;
	object.function1_name();
	object.function2_name();
	object.function3_name();
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


int main()
{
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
