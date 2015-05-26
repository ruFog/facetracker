#ifndef ASERVICECONTROLLER_H
#define ASERVICECONTROLLER_H

#include <QtCore/QPointer>
#include <QtCore/QObject>

class QNetworkAccessManager;
class QAction;

class AServiceDatabaseController;
class ASessionController;
class ATableController;
class ASystemTrayIcon;

class AServiceController : public QObject {
    Q_OBJECT

    signals:
        void loginStarted();
        void loginSucceed();
        void loginFailed();

        void logoutStarted();
        void logoutSucceed();
        void logoutFailed();

    public:
        //! Get instance.
        static AServiceController *instance();

        //! Constructor.
        explicit AServiceController(QObject *parent = NULL);

        //! Destructor.
        virtual ~AServiceController() {}

        //! Get database is opened.
        bool isDatabaseOpened() const;

        //! Get messages.
        ATableController *messages() const;

        //! Get statistic.
        ATableController *statistic() const;

        //! Get rss.
        ATableController *rss() const;

    public slots:
        //! Login.
        void login();

        //! Logout.
        void logout();

        //! Start.
        void start();

        //! Stop.
        void stop();

        //! Show message.
        void showMessage(const QString &msg);

    private:
        enum Mode {
            MODE_GRAY,
            MODE_GREEN,
            MODE_RED
        };

        Mode _mode;

        AServiceDatabaseController *_service_db_ctrl;

        ASessionController *_session_ctrl;

        QPointer<QNetworkAccessManager> _nam;

        QPointer<ASystemTrayIcon> _tray;

        QAction *_settings_action;

        //! Create tray.
        void createTray();

        //! Set actions enabled.
        void setActionsEnabled(bool enabled);

    private slots:
        //! Show settings dialog.
        void showSettingsDialog();

        //! Shutdown.
        void shutdown();

        //! On gray activated.
        void onGrayActivated();

        //! On green activated.
        void onGreenActivated();

        //! On red activated.
        void onRedActivated();

};

#endif
