Video player based on [this code](https://gstreamer.freedesktop.org/data/doc/gstreamer/head/qt-gstreamer/html/examples_2player_2main_8cpp-example.html)

You pass it a file system path (or URI) to play and it will repeatedly play that video in a full sized window (not "fullscreen") but a window that occupies all the pixels of a screen.

example:

./player /path/to/file.mp4
