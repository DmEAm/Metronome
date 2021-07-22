#ifndef SOUNDSTRUCT_H
#define SOUNDSTRUCT_H

#include <QObject>
#include <QSoundEffect>

class SoundStruct : public QObject
{
    Q_OBJECT

public:
    explicit SoundStruct(QObject *parent = nullptr);
    ~SoundStruct();

    size_t _tempo;

    int interval();
    void setStandartMode();

public slots:
    void click();
    void stop();

private:
    QVector<QSoundEffect*> *_effects;
    int currentEffect;

    void upPosition();
    void resetPosition();

signals: 

};

#endif // SOUNDSTRUCT_H
