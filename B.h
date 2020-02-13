#ifndef B_H
#define B_H
#include <QObject>
class B : public QObject{
  Q_OBJECT
public:
  B( int id );
signals:
  void updater( int update );
  private:
  int name;
};
#endif
