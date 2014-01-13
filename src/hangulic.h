#ifndef HANGULIC_H
#define HANGULIC_H

#include <QQuickItem>
#include <QString>
#include <QTextCodec>

#include <hangul.h>

class HangulIC : public QQuickItem
{
    Q_OBJECT
    Q_DISABLE_COPY(HangulIC)
    //Q_PROPERTY(int value READ myFunction)
private:
    HangulInputContext *hic;
    QTextCodec *codec;
public:
    HangulIC(QQuickItem *parent = 0);
    ~HangulIC();
    Q_INVOKABLE bool process(int ascii);
    Q_INVOKABLE QString getPreeditString();
    Q_INVOKABLE QString getCommitString();
    Q_INVOKABLE void reset();    
    Q_INVOKABLE QString flush();
    Q_INVOKABLE bool backspace();
    Q_INVOKABLE bool isEmpty();
    Q_INVOKABLE bool hasChoseong();
    Q_INVOKABLE bool hasJungseong();
    Q_INVOKABLE bool hasJongseong();
    Q_INVOKABLE void selectKeyboard(const QString &id);
    Q_INVOKABLE bool isTransliteration();
};

#endif // HANGULIC_H

