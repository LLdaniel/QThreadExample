#include <QApplication>
#include <QThread>
#include <iostream>
#include "A.h"
#include "B.h"
int main(int argc , char *argv[]){
  QApplication app(argc, argv);
  //doing something for gui and user ...
  // ...
  std::cout<<"Hello Qt Forum."<<std::endl;
  // ...
  A a(1);
  B b(2);
  //creating thread 
  QThread* thread = new QThread;
  a.moveToThread(thread); // change thread affinity
  bool check1, check2;
  check1 = QObject::connect(thread, &QThread::started, &a, &A::timing);
  check2 = QObject::connect(&b, &B::updater , &a, &A::makeUpdate);
  std::cout<<"Successful connection? check1 = "<<check1<<" and check2 = "<<check2<<std::endl;

  //starting thread
  thread->start();
  
  //now: give an update from B to A:
  emit b.updater(42); // --> now it`s working
  for(int i = 0; i < 123; i++){ // doing something else in the main event loop
    std::cout<<"Here in main event loop, doing something else: i = "<<i<<std::endl;
  }
  emit b.updater(1001);// --> and again...
  return app.exec();
}
