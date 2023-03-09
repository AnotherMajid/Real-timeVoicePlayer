#ifndef AUDIOSINK_H
#define AUDIOSINK_H

#include <QObject>
#include <QDebug>
#include <QAudioSink>
#include <QAudioDevice>
#include <QMediaDevices>

class AudioSink : public QObject
{
    Q_OBJECT
public:
    explicit AudioSink(QObject *parent = nullptr);
    ~AudioSink();

    void audioSinkData(QIODevice *);

public slots:
    void audioDataReceived(QByteArray newAudioBuffer, qreal newAudioLevel);

signals:
    void checkAudioDataReceived();

private:
    QAudioFormat m_format;
    QMediaDevices *m_devices = nullptr;
    QAudioSink *m_audioSink = nullptr;

    QByteArray m_buffer;
    qreal m_audioLevel = 0.0;

};

#endif // AUDIOSINK_H
