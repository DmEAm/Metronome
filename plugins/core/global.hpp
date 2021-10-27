#ifndef GLOBAL_HPP
#define GLOBAL_HPP

#include <QtGlobal>

#define Q_DISABLE_MOVE(T) \
    T(T &&) = delete;     \
    T &operator=(T &&) = delete;

#define Q_DISABLE_COPY_AND_MOVE(T) \
    Q_DISABLE_COPY(T)              \
    Q_DISABLE_MOVE(T)

#endif //GLOBAL_HPP
