#include "AudioPlayer.h"

AudioPlayer::AudioPlayer()
{
    player = new QMediaPlayer;
    player->setVolume(100);
}

void AudioPlayer::playBootSound()
{
    std::cout << "Playing" << std::endl ;
    player->stop();
    player->setMedia(QUrl::fromLocalFile("/mnt/35628DFB2C70967C/B_Documents/3D-ArtGallery/Audio/shoe.mp3"));
    player->play();
}
