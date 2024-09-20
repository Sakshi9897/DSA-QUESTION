#include <iostream>
using namespace std;

class NStack{
    int *a,*top,*next;
    int n;
    int size;
    int freeSpot;

    public:
      NStack(int _n, int _s) : n(_n), size(_s){
        freeSpot=0;
        a= new int[size];
        top= new int[n];
        next= new int[size];

        for(int i=0; i<n; i++){
            top[i]= -1;
        }
        for(int i=0; i<size; i++){
            next[i]= i+1;
        }
        next[size- 1] = -1;
      }
      bool push(int X, int m){
        if(freeSpot == -1){
            return false;
        }

        //1 find index
        int index= freeSpot;

        //2 update freespot
        freeSpot= next[index];

        //3 insert
        a[index]= X;

        //4 update next
        next[index]= top[m-1];

        //5 update top 
        top[m-1]= index;

        return true; //oush successfully 

      }

    //   pop from nth dstack

    int pop(int m){
        if(top[m-1] == -1){
            return -1;
        }
        int index = top[m-1];
        top[m-1]= next[index];
        int poppedElement = a[index];
        next[index]= freeSpot;
        freeSpot= index;
        return poppedElement;
    }
  ~NStack(){
    delete[]a;
    delete[] top;
    delete [] next;
  }

};

int main(){
 
 NStack s(3, 6);

 cout<<s.push(10,1)<<endl;
  cout<<s.push(16,1)<<endl;
//    cout<<s.push(10,1)<<endl;
    cout<<s.push(77,1)<<endl;
     cout<<s.push(50,2)<<endl;
      cout<<s.push(17,3)<<endl;
 cout<<s.pop(1) <<endl;
 cout<<s.pop(2)<<endl;

}