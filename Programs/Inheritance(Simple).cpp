#include <iostream>
#include <string>
using namespace std;

class universityMember{
private:
  string name;
  int age;
public:
  void setName(string iname);
  void setAge(int iage);
  void getAttr() {
    cout<<" Has name "<<name<<" and Age "<<age;
  };
};
void universityMember :: setName(string iname) {
  name = iname;
}
void universityMember :: setAge(int iage) {
  age = iage;
}
class student : public universityMember{
public:
  string reg_no;
  void setRegno(string Regno){
    reg_no=Regno;
  };
};

int main()
{
  student aditya;
  aditya.setName("Aditya");
  aditya.setAge(19);
  aditya.setRegno("15BCE0227");
  cout<<aditya.reg_no;
  aditya.getAttr();
}
