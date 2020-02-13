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
  check1 = QObject::connect(thread, &QThread::started, &a, &A::processList, Qt::QueuedConnection);
  check2 = QObject::connect(&b, &B::updater , &a, &A::makeUpdate, Qt::QueuedConnection);
  std::cout<<"successful connection?: check1= "<<check1<<" and check2= "<<check2<<std::endl;

  //starting thread
  thread->start();
  
  //now: give an update from B to A:
  emit b.updater(42); // --> currently not working, why?
  return app.exec();
}
