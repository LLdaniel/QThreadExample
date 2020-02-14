#include "A.h"
#include <iostream>
//
A::A (int id){
  name = id;
  t->callOnTimeout(this, &A::processList);
}

void A::timing(){
  std::cout<<thread()<<std::endl;
    t->start();
  
}

void A::processList(){
  std::cout<<"in processList"<<std::endl;
  if( !buffer.isEmpty() ){
    list.append(buffer);
    std::cout<<"Now list size is: "<<list.size()<<std::endl;
    buffer.clear();
    std::cout<<"after cleaning buffer, buffer size is:"<<buffer.size()<<std::endl;
  }
  timing();
}

void A::makeUpdate( int update ){
  std::cout<<"Updating..."<<std::endl;
  std::cout<<thread()<<std::endl;
  buffer.append(update);
}
