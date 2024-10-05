# QThreadExample
Example for `QThread` without inheriting from `QThread` directly, but changing thread affinity of `QObject` via `obj->moveToThread(thread)`.
The example uses the new connection syntax and can be build with `CMakeLists.txt`.

This is a example how to add `QObject` to an `QThread` via `moveToThread`. The goal is to achieve a constantly updating list, which will then be processed.
Thanks to the discussion on QtForum https://forum.qt.io/topic/111621/signals-and-slots-across-threads-without-qthread-inheritance.

The trick here is to insert a `QTimer` of time = 0ms and call that timer reapeatedly. This will help to prevent blocking the thread with the loop and allow regular processed updates.
Without using the timing function the connection of `processList` with the thread's start would give no chance to update the list. The processing of the list would have become blocking.
