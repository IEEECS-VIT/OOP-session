## Structures

Definition:
A struct in the C programming language (and many derivatives) is a complex data type declaration that defines a physically grouped list of variables to be placed under one name in a block of memory, allowing the different variables to be accessed via a single pointer, or the struct declared name which returns the same address. The struct can contain many other complex and simple data types in an association, so is a natural organizing type for records like the mixed data types in lists of directory entries reading a hard drive (file length, name, extension, physical (cylinder, disk, head indexes) address, etc.), or other mixed record type (patient names, address, telephone... insurance codes, balance, etc.).

The C struct directly corresponds to the assembly language data type of the same use, and both reference a contiguous block of physical memory, usually delimited (sized) by word-length boundaries. Language implementations which could utilize half-word or byte boundaries (giving denser packing, using less memory) were considered advanced in the mid-eighties. Being a block of contiguous memory, each variable within is located at a fixed offset from the index zero reference, the pointer.

Difference In C and C++ (Structures):
1) C structure can't contain functions means only data members are allowed, but structure in C++ can have both functions & data members.

2) struct keyword is necessary in C to create structure type variable, but it is redundant & not necessary in C++.

3) Size of empty structure is undefined behavior in C, but it is always 1 in C++.

4) Structure in C can't have static members, but C++ structure can have static members. 
This will work in C++;
Ex- #include <stdio.h>
    struct demo 
    {
        static int a;
    };
    int main()
    { return 0; }

// Invalid C, but valid C++ program
    #include <stdio.h>
     struct stu{
         int a=9;
     };
     int main(){
     struct stu s;
     printf("%d",s.a); 
     }

5) We can have both pointers and references to struct in C++, but only pointers to structs are allowed. (References aren't feature of C language).

6) C++ also have .* and -> operators to access individual members of struct, but C doesn't have such kind of operators.

7) struct declaration establishes a scope in C++ and not in C, which makes member enumerators and nested structs possible in C++ (you can *write* them inside a struct in C, but they escape and become local to whatever function the parent struct is in).

8) In C, we need to use struct tag whenever we declare a struct variable. In C++, the struct tag is not necessary. For example, let there be a structure for Student. In C, we must use ‘struct Student‘ for Student variables. In C++, we can omit struct and use ‘Student‘ only.    


