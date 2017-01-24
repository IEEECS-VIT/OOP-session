#include <iostream>
#include <string>
using namespace std;
class classname
 {
     private:
        string *pname;
        string name;
        int * page;

     public:
     classname() {
        cout<<"I am Alive"<<endl;
        pname = new string;
        page = new int;
        *pname = "Default";
        *page = 0;
        name = "";

     }
     classname(string s_name,int s_age) {
         cout<<"I am Alive"<<endl;
         pname = new string;
         page = new int;
         * pname = s_name;
         * page = s_age;
     }
     classname(string s_name) {
        cout<<"I am Alive"<<endl;
        pname = new string;
        page = new int;
        *pname = "Default";
        *page = 0;
        name = s_name;
     }
     ~classname() {
         delete pname;
         delete page;
         cout<<"I will be back !"<<endl;
     }

 };
 void CheckOutScope() {
     // A constructor will be called as object is initialized.
     classname obk("aditya");
     // A destructor will be called as object is going out of scope(deleted).
 }
 int main()
 {
     // A constructor will be called as object is initialized.
     classname obk1;

     classname obk("aditya",19);

     CheckOutScope();

     cout<<"Hello World!\n";
     // A destructor will be called as object is going out of scope(deleted).
 }
