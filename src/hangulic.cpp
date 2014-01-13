#include <QTextCodec>
#include <QByteArray>
#include <hangul.h>
#include <QDebug>

#include "hangulic.h"

HangulIC::HangulIC(QQuickItem *parent):
    QQuickItem(parent) {

    qDebug() << "libhangul started";

    this->hic = hangul_ic_new("2");
    this->codec = QTextCodec::codecForName("UTF-32");

    // By default, QQuickItem does not draw anything. If you subclass
    // QQuickItem to create a visual item, you will need to uncomment the
    // following line and re-implement updatePaintNode()

    // setFlag(ItemHasContents, true);
}

HangulIC::~HangulIC() {
    hangul_ic_delete(this->hic);
    this->hic = NULL;
}

bool HangulIC::process(int ascii) {
    if (!this->hic) return false;
    return hangul_ic_process(this->hic, ascii);
}

QString HangulIC::getPreeditString() {
    if (!this->hic) return QString();
    QByteArray b;
    const ucschar *pestr = hangul_ic_get_preedit_string(this->hic);
    const ucschar *iter = pestr;
    while (*iter > 0) {
        b.append((const char *)iter, sizeof(ucschar));
        iter++;
    }
    return this->codec->toUnicode(b);
}

QString HangulIC::getCommitString() {
    if (!this->hic) return QString();
    QByteArray b;
    const ucschar *cstr = hangul_ic_get_commit_string(this->hic);
    const ucschar *iter = cstr;
    while (*iter > 0) {
        b.append((const char *)iter, sizeof(ucschar));
        iter++;
    }
    return this->codec->toUnicode(b);
}

void HangulIC::reset() {
    if (!this->hic) return;
    return hangul_ic_reset(this->hic);
}

QString HangulIC::flush() {
    if (!this->hic) return QString();
    QByteArray b;
    const ucschar *fstr = hangul_ic_flush(this->hic);
    const ucschar *iter = fstr;
    while (*iter > 0) {
        b.append((const char *)iter, sizeof(ucschar));
        iter++;
    }
    return this->codec->toUnicode(b);
}

bool HangulIC::backspace() {
    if (!this->hic) return false;
    return hangul_ic_backspace(this->hic);
}

bool HangulIC::isEmpty() {
    if (!this->hic) return false;
    return hangul_ic_is_empty(this->hic);
}

bool HangulIC::hasChoseong() {
    if (!this->hic) return false;
    return hangul_ic_has_choseong(this->hic);
}

bool HangulIC::hasJungseong() {
    if (!this->hic) return false;
    return hangul_ic_has_jungseong(this->hic);
}

bool HangulIC::hasJongseong() {
    if (!this->hic) return false;
    return hangul_ic_has_jongseong(this->hic);
}

void HangulIC::selectKeyboard(const QString &id) {
    if (!this->hic) return;
    return hangul_ic_select_keyboard(this->hic, id.toLatin1());
}

bool HangulIC::isTransliteration() {
    if (!this->hic) return false;
    return hangul_ic_is_transliteration(this->hic);
}
