#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QApplication>
#include <QQuickWindow>
#include "m3showcontroller.h"
#include "screencapture.h"
#include <QQmlContext>
#include "qmlplot.h"
//typedef float qreal;
int main(int argc, char *argv[])
{
    qputenv("QT_IM_MODULE",QByteArray("qtvirtualkeyboard"));//引入虚拟键盘
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    //QGuiApplication app(argc, argv);
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    qRegisterMetaType<QList<quint16*>> ("QList<quint16>*");
    qRegisterMetaType<QList<quint16>> ("QList<quint16>&");
    qRegisterMetaType<QList<quint16>> ("QList<quint16>");
    qRegisterMetaType<QList<quint8>> ("QList<quint8>");
    qRegisterMetaType<QList<float>*> ("QList<float>[12]"); //注册一个12导联的数组 传递要显示的数据用的
    qRegisterMetaType<QList<int>*> ("QList<int>[12]"); //注册一个12导联的数组 传递要显示的数据用的
    qRegisterMetaType<QList<double>*> ("QList<double>[12]"); //注册一个12导联的数组 传递要显示的数据用的
    qRegisterMetaType<QQmlListProperty<float>> ("QQmlListProperty<float>");
    qmlRegisterType<M3ShowController>("M3ShowDataController",1,0,"M3ShowController");//将M3的数据控制类注册到Qt的元系统中，QML可以使用
    qmlRegisterType<CustomPlotItem>("CustomPlot", 1, 0, "CustomPlotItem");  //将CustomPlotItem注册到Qt元系统中，QML可以使用
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));


    //屏幕截屏
    QObject      *topLevel = engine.rootObjects().value(0);
    QQuickWindow *window   = qobject_cast<QQuickWindow *>(topLevel);
    ScreenCapture launcher (window);
    //engine.rootContext()->setContextProperty("ScreenShot", &launcher);
    engine.rootContext()->setContextProperty("ScreenShot",&launcher);//在qml中以ScreenShot这个名字访问ScreenCapture,这个类
    //launcher.capture();
    window->show();



    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
