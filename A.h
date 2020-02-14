#ifndef A_H
#define A_H
#include <QObject>
#include <QList>
#include <QTimer>
class A : public QObject{
  Q_OBJECT
public:
  A( int id );
public slots:
  void processList();
  void timing();
  void makeUpdate( int update );
private:
  int name;
  QList<int> list;
  QList<int> buffer;
  bool running = true;
  QTimer *t = new QTimer(this); //witout 'this' as parent: QObject::killTimer: Timers cannot be stopped from another thread
};
#endif
