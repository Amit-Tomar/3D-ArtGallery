#include "AudioPlayer.h"

AudioPlayer::AudioPlayer()
{
    playerBoot = new QMediaPlayer;
    playerBoot->setVolume(100);
    playerDoor = new QMediaPlayer;
    playerDoor->setVolume(100);
}

void AudioPlayer::playBootSound()
{
    std::cout << "Playing" << std::endl ;

    playerBoot->stop();
    playerBoot->setMedia(QUrl::fromLocalFile("/mnt/35628DFB2C70967C/B_Documents/3D-ArtGallery/Audio/shoe.mp3"));
    playerBoot->play();
}

void AudioPlayer::playDoorSound()
{
    playerDoor->stop();
    playerDoor->setMedia(QUrl::fromLocalFile("/mnt/35628DFB2C70967C/B_Documents/3D-ArtGallery/Audio/door_squeak.mp3"));
    playerDoor->play();
}
