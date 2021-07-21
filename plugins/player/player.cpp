#include "player.hpp"

PlayerController::PlayerController(QObject *parent) : QObject(parent)
{
    m_isWork = false;

    thread = new QThread;
    sound = new QSoundEffect;
    sound->setSource(QUrl("qrc:/audio/stick_1(wav)"));
    sound->setVolume(0.25f);
    sound->setLoopCount(1);
    sound->moveToThread(thread);
    connect(this, &PlayerController::click,  sound, &QSoundEffect::play);
    connect(this, &PlayerController::stp,  sound, &QSoundEffect::stop);

    _timer = new QTimer(this);
    _timer->setTimerType(Qt::PreciseTimer);
    connect(_timer, &QTimer::timeout,  this, &PlayerController::sclick);

    thread->start();
}

PlayerController::~PlayerController()
{
    if(thread->isRunning())
        thread->terminate();
    delete sound;
    delete _timer;
    delete thread;
}

bool PlayerController::isWork()
{
    return m_isWork;
}

void PlayerController::setWorkState(const bool &workState)
{
    if (workState == m_isWork)
        return;

    m_isWork = workState;
    if(m_isWork)
    {
        _timer->start(100);
        time = clock();
    }
    else
    {
        _timer->stop();
    }
    emit workStateChanged();
}

void PlayerController::changeWorkState()
{
    setWorkState(!m_isWork);
}

void PlayerController::sclick()
{
    qDebug() << sound->isPlaying();
    qDebug() << "" << clock() - time;
    time = clock();
    emit click();
}
