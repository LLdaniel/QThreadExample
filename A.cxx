#include "A.h"
#include <iostream>
//
A::A (int id){
  name = id;
  t->callOnTimeout(this, &A::processList);
}

void A::timing(){
  t->start();
  
}

void A::processList(){
  if( !buffer.isEmpty() ){
    list.append(buffer);
    std::cout<<"Now list size in second thread is: "<<list.size()<<std::endl;
    buffer.clear();
    std::cout<<"After cleaning buffer in second thread, buffer size is:"<<buffer.size()<<std::endl;
  }
  timing();
}

void A::makeUpdate( int update ){
  std::cout<<"Updating list in second QThread..."<<std::endl;
  std::cout<<"Second QThread is: "<<thread()<<std::endl;
  buffer.append(update);
}
