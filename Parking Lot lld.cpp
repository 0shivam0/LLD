#include <bits/stdc++.h>
using namespace std;



class vehicle{
protected:
  string type;
  int cost;
public:
  vehicle(string t, int c){
    type = t;
    cost = c;
  }
  void showDetails(){
    cout<<type;
  }
  int getCost(){
    return cost;
  }
};

class bike: public vehicle{
public:
  bike(): vehicle("bike", 10) {}
};

class car: public vehicle{
public:
  car(): vehicle("car", 20) {}
};

class ticket{
public:
  int getCost(vehicle &v, int h){
    return v.getCost() * h;
  }
};

class parkingLot{
private:
  int totalSlot;
  int currSlot;
  ticket price;
public:
  parkingLot(int totalSlot){
    this->totalSlot = totalSlot;
    currSlot = 0;
  }

  void park(vehicle &v, int hours){
    if(currSlot >= totalSlot){
      cout<<"Parking lot is full"<<"\n";
    }
    else{
      currSlot++;
      v.showDetails();
      cout<<" parked Successfully amount is "<<price.getCost(v, hours)<<"\n";
    }
  }
  void leave(){
    if(currSlot == 0){
      cout<<"There are no cars in parkingLot"<<"\n";
    }
    else{
      currSlot--;
    }
  }
  void getAvailableSlots(){
    cout<<"available slots = "<<totalSlot - currSlot<<"\n";
  }
};



int main(){

  parkingLot p1(100);
  bike b1;
  car c1;
  p1.park(b1, 2);
  p1.park(c1, 3);

  return 0;
}

