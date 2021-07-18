#ifndef PICKER_CONTROLLER_H
#define PICKER_CONTROLLER_H

#include <QObject>

class PickerController : public QObject
{
    Q_OBJECT
public:
    explicit PickerController(QObject *parent = nullptr);

signals:

};

#endif // PICKER_CONTROLLER_H
