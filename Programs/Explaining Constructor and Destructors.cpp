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
     }
     classname(string s_name,int s_age) {
         pname = new string;
         page = new int;
         * pname = s_name;
         * page = s_age;
     }
     classname(string s_name) {
        name = s_name;
     }
     ~classname() {
         //delete pname;
         //delete page;
         cout<<"I will be back !"<<endl;
     }

 };
 void CheckOutScope() {
     classname obk("aditya");
 }
 int main()
 {
     classname obk1;
     classname obk("aditya",19);
     CheckOutScope();
     cout<<"Hello World!\n";
 }
