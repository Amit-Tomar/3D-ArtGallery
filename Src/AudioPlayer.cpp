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
    playerBoot->stop();
    playerBoot->setMedia(QUrl::fromLocalFile("/home/gvcl-admin/Documents/AdvancedGraphics/3D-ArtGallery/Audio/shoe.mp3"));
    playerBoot->play();
}

void AudioPlayer::playDoorSound()
{
    playerDoor->stop();
    playerDoor->setMedia(QUrl::fromLocalFile("/home/gvcl-admin/Documents/AdvancedGraphics/3D-ArtGallery/Audio/door_squeak.mp3"));
    playerDoor->play();
}
