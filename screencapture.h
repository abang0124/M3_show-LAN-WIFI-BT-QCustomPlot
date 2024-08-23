#ifndef SCREENCAPTURE_H
#define SCREENCAPTURE_H

#include <QObject>

class QString;
class QQuickWindow;

class ScreenCapture : public QObject
{
    Q_OBJECT
public:
    //explicit ScreenCapture(QObject *parent = nullptr);
    explicit ScreenCapture(QQuickWindow *parent = 0);

signals:

public slots:
    void capture () const;

private:
    QQuickWindow *currentWindow;
};

#endif // SCREENCAPTURE_H
