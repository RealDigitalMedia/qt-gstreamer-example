/*
    Copyright (C) 2010 Marco Ballesio <gibrovacco@gmail.com>
    Copyright (C) 2011 Collabora Ltd.
      @author George Kiagiadakis <george.kiagiadakis@collabora.co.uk>
    This library is free software; you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published
    by the Free Software Foundation; either version 2.1 of the License, or
    (at your option) any later version.
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.
    You should have received a copy of the GNU Lesser General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef MEDIAAPP_H
#define MEDIAAPP_H
#include <QTimer>
#include <QWidget>
#include <QStyle>
class Player;
class QBoxLayout;
class QLabel;
class QSlider;
class QToolButton;
class QTimer;
class MediaApp : public QWidget
{
    Q_OBJECT
public:
    MediaApp(QWidget *parent = 0);
    ~MediaApp();
    void openFile(const QString & fileName);
private Q_SLOTS:
    void onStateChanged();
private:
    Player *m_player;
};
#endif
