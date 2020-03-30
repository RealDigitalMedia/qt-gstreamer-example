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
#include "mediaapp.h"
#include "player.h"
#include <QBoxLayout>
#include <QFileDialog>
#include <QToolButton>
#include <QLabel>
#include <QSlider>
#include <QMouseEvent>
#include <QApplication>
#include <QDesktopWidget>

MediaApp::MediaApp(QWidget *parent)
    : QWidget(parent)
{
    // create the player
    m_player = new Player(this);
    connect(m_player, SIGNAL(stateChanged()), this, SLOT(onStateChanged()));

    // create the UI
    QVBoxLayout *appLayout = new QVBoxLayout;
    appLayout->setContentsMargins(0, 0, 0, 0);

    // Associate the player
    appLayout->addWidget(m_player);

    setWindowTitle(tr("QtGStreamer example player"));

    QRect rec = QApplication::desktop()->screenGeometry();
    int width = rec.width();
    int height = rec.height();

    // Size the window and the player to full size
    resize(width, height);
    m_player->resize(width, height);

    // Set translucent background
    setAttribute(Qt::WA_TranslucentBackground);

    // Frameless and drop-shadowless
    setWindowFlags(Qt::NoDropShadowWindowHint  | Qt::FramelessWindowHint);

}

MediaApp::~MediaApp()
{
    delete m_player;
}

void MediaApp::openFile(const QString & fileName)
{
    m_player->stop();

    m_player->setUri(fileName);

    m_player->play();
}

void MediaApp::onStateChanged()
{
    QGst::State newState = m_player->state();

    if (newState == QGst::StateNull) {
       m_player->play();
    }
}

#include "moc_mediaapp.cpp"
