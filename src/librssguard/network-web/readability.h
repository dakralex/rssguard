// For license of this file, see <project-root-folder>/LICENSE.md.

#ifndef READABILITY_H
#define READABILITY_H

#include <QObject>

#include "miscellaneous/nodejs.h"

#include <QProcess>

class Readability : public QObject {
    Q_OBJECT

  public:
    explicit Readability(QObject* parent = nullptr);

    void makeHtmlReadable(QObject* sndr, const QString& html, const QString& base_url = {});

  private slots:
    void onReadabilityFinished(QObject* sndr, int exit_code, QProcess::ExitStatus exit_status);
    void onPackageReady(const QList<NodeJs::PackageMetadata>& pkgs, bool already_up_to_date);
    void onPackageError(const QList<NodeJs::PackageMetadata>& pkgs, const QString& error);

  signals:
    void htmlReadabled(QObject* sndr, const QString& better_html);
    void errorOnHtmlReadabiliting(QObject* sndr, const QString& error);

  private:
    bool m_modulesInstalling;
    bool m_modulesInstalled;
};

#endif // READABILITY_H
