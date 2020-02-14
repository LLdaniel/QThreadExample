# QThreadExample
Example for QThread without inheriting from QThread directly, but changing thread affinity of QObject via obj->moveToThread(thread). New QT Connection syntax

This is a example how to add QObject to an QThread via MoveToThread. The goal is to achieve a constantly updating list, which will then be processed.
Thanks to the discussion on QtForum https://forum.qt.io/topic/111621/signals-and-slots-across-threads-without-qthread-inheritance

The trick to not block the thread itself (after connection processList with thread; the thread processes directly the list, but has no chance to update):
Insert QTimer of time = 0ms and call that repeatedly, then there is a chance that the event handler in the thread executes updates.
