#ifndef AUDIOSOURCE_H
#define AUDIOSOURCE_H

#include <QObject>
#include <QDebug>
#include <QAudioSource>
#include <QAudioDevice>
#include <QMediaDevices>


class AudioSource : public QObject
{
    Q_OBJECT
public:
    explicit AudioSource(QObject *parent = nullptr);
    ~AudioSource();

    void audioSourceData(QIODevice *,QAudioSource *);
    qreal audioSourceLevel(const char* data,qint64 maxLen);

signals:
    void audioDataTransmit(QByteArray audioBuffer,qreal AudioLevel);

private:
    QAudioFormat m_format;
    QMediaDevices *m_devices = nullptr;
    QAudioSource *m_audioSource = nullptr;

    QByteArray m_buffer;
    qreal m_audioLevel = 0.0;

};

#endif // AUDIOSOURCE_H
