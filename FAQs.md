
## What is the difference between new/delete and malloc/free?

### new/delete

* Allocate/release memory
* Memory allocated from 'Free Store'
* Returns a fully typed pointer.
* new (standard version) never returns a NULL (will throw on failure)
* Are called with Type-ID (compiler calculates the size)
* Has a version explicitly to handle arrays.
* Reallocating (to get more space) not handled intuitively (because of copy constructor).
* Whether they call malloc/free is implementation defined.
* Can add a new memory allocator to deal with low memory (set_new_handler)
* operator new/delete can be overridden legally
* constructor/destructor used to initialize/destroy the object

### malloc/free

* Allocates/release memory
* Memory allocated from 'Heap'
* Returns a void*
* Returns NULL on failure
* Must specify the size required in bytes.
* Allocating array requires manual calculation of space.
* Reallocating larger chunk of memory simple (No copy constructor to worry about)
* They will NOT call new/delete
* malloc/free can NOT be overridden legally
* No way to splice user code into the allocation sequence to help with low memory.

| Feature                  | new/delete                     | malloc/free |
|--------------------------| --------------------------------| -------------------------------|
|Memory allocated from     | 'Free Store'                   | 'Heap'                        |
| Returns                  | Fully typed pointer            | void*                         |
| On failure               | Throws (never returns NULL)    | Returns NULL                  |
| Required size            | Calculated by compiler         | Must be specified in bytes    |
| Handling arrays          | Has an explicit version        | Requires manual calculations  |
| Reallocating             | Not handled intuitively        | Simple (no copy constructor)  |
| Call of reverse          | Implementation defined         | No                            |
| Low memory cases         | Can add a new memory allocator | Not handled by user code      |
| Overridable              | Yes                            | No                            |
| Use of (con-)/destructor | Yes                            | No                            |

## What are the operators that cannot be overloaded in C++?

In C++, following operators can not be overloaded:

* . (Member Access or Dot operator)
* ?: (Ternary or Conditional Operator )
* :: (Scope Resolution Operator)
* .* (Pointer-to-member Operator )
* sizeof (Object size Operator)
* typeid (Object type Operator)

## Can we overloaded Destructors ?

You can't. There is only one destructor per class in C++.

What you can do is make a private destructor and then have several public methods which call the destructor in new and interesting ways.
```
class Foo {
  ~Foo() { ... }
public:
  DestroyFoo(int) { ... };
  DestroyFoo(std::string) { ... }
};
```
## What are the applications of Friend Function ?

- The friend specifier allows the designated class access to protected data or functionality within the class making the friend statement. For example in the below code anyone may ask a child for their name, but only the mother and the child may change the name.

- You can take this simple example further by considering a more complex class such as a Window. Quite likely a Window will have many function/data elements that should not be publicly accessible, but ARE needed by a related class such as a WindowManager.

```
class Child
{
//Mother class members can access the private parts of class Child.
friend class Mother;

public:

  string name( void );

protected:

  void setName( string newName );
};
```
## What is meant by Resource Acquisition is Initialization (RAII)?

It's a really terrible name for an incredibly powerful concept, and perhaps one of the number 1 things that C++ developers miss when they switch to other languages. There has been a bit of a movement to try to rename this concept as Scope-Bound Resource Management, though it doesn't seem to have caught on just yet.

When we say 'Resource' we don't just mean memory - it could be file handles, network sockets, database handles, GDI objects... In short, things that we have a finite supply of and so we need to be able to control their usage. The 'Scope-bound' aspect means that the lifetime of the object is bound to the scope of a variable, so when the variable goes out of scope then the destructor will release the resource. A very useful property of this is that it makes for greater exception-safety. For instance, compare this:

```
RawResourceHandle* handle=createNewResource();
handle->performInvalidOperation();  // Oops, throws exception
...
deleteResource(handle); // oh dear, never gets called so the resource leaks
```
With the RAII one
```
class ManagedResourceHandle {
public:
   ManagedResourceHandle(RawResourceHandle* rawHandle_) : rawHandle(rawHandle_) {};
   ~ManagedResourceHandle() {delete rawHandle; }
   ... // omitted operator*, etc
private:
   RawResourceHandle* rawHandle;
};

ManagedResourceHandle handle(createNewResource());
handle->performInvalidOperation();
```
In this latter case, when the exception is thrown and the stack is unwound, the local variables are destroyed which ensures that our resource is cleaned up and doesn't leak.
