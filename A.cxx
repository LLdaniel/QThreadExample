#include "A.h"
#include <iostream>
//
A::A (int id){
  name = id;
}

void A::processList(){
  int i = 0;
  int q = 0;
  while(running){
    q++;
    if( i < list.size() and !list.isEmpty() ){
      //doing something that should not block main.cxx
      i++;
      if( i == list.size() ){
	//end of list, reset list index
	i = 0;
      }
    }
    if( !buffer.isEmpty() ){
      list.append(buffer);
      std::cout<<"Now list size is: "<<list.size()<<" and was added at step "<<q<<std::endl;
      buffer.clear();
      std::cout<<"after cleaning buffer, buffer size is:"<<buffer.size()<<std::endl;
    }
  }
}

void A::makeUpdate( int update ){
  std::cout<<"Updating..."<<std::endl;
  buffer.append(update);
}
