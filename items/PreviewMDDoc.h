#ifndef PREVIEWMDDOC_H
#define PREVIEWMDDOC_H

#include <QObject>

class PreviewMDDoc : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString text MEMBER m_text NOTIFY textChanged FINAL)
public:
    explicit PreviewMDDoc(QObject *parent = nullptr) : QObject(parent) {
        this->m_text = "No Description !!!";
    }

    void setText(const QString &text);

signals:
    void textChanged(const QString &text);

private:
    QString m_text;
};

#endif // PREVIEWMDDOC_H
