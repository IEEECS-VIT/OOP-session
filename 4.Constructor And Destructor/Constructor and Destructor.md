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
- On Executing the code above destructor wont be called.
```
	delete aditya;
```
- Destructor will be called as we deleted the object pointer.
