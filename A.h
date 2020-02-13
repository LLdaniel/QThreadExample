#ifndef A_H
#define A_H
#include <QObject>
#include <QList>
class A : public QObject{
  Q_OBJECT
public:
  A( int id );
public slots:
  void processList();
  void makeUpdate( int update );
private:
  int name;
  QList<int> list;
  QList<int> buffer;
  bool running = true;
};
#endif
