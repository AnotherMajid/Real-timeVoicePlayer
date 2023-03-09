#include <QCoreApplication>

#include "AudioSource/audiosource.h"
#include "AudioSink/audiosink.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    AudioSource microphone{};
    AudioSink speaker{};

    QObject::connect(&microphone,&AudioSource::audioDataTransmit,&speaker,&AudioSink::audioDataReceived);


    return a.exec();
}
