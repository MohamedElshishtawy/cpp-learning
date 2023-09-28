#include <iostream>
using namespace std;

struct E {
    int *id = new int {0} ; // Should be deleted

    E(int _id){
        *id = _id;
    }

    ///- Will Make An Exception 
    void do_thing(){
      // Try will solve the proplem
       try{
         
         if (true)
            throw invalid_argument("Message");
         
       } catch ( invalid_argument &e ){
         
          cout << "Not good " << e.what() ;
         
       }
        cout << "Did"<< endl;
    }
    
    ~E(){
        cout << "Bye";
        delete id;
    }
};

int main()
{
    E e(12);
    e.do_thing();
    
    return 0;
}
