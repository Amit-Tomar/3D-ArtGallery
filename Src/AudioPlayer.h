#ifndef AUDIOPLAYER_H
#define AUDIOPLAYER_H

#include <qobject.h>
#include <QMediaPlayer>
#include <iostream>

class AudioPlayer : public QObject
{
    Q_OBJECT

public:
    AudioPlayer();

public slots :

    void playBootSound();

private:

    QMediaPlayer * player;
};

#endif // AUDIOPLAYER_H
