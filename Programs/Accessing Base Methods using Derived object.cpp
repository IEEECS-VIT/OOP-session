#include <iostream>
using namespace std;

class universityMember {

public :
    string Id = "0000";
    void getID(){
        cout<<"The ID of the Member is "<<Id<<endl;
    }
};
class student : public universityMember {

public :
    string Id = "1000";
    void getID(){
        cout<<"The ID of the Member is "<<Id<<endl;
    }
};
int main()
{
    student aditya;
    universityMember ram = aditya;
    aditya.getID();
    ram.getID();

}
