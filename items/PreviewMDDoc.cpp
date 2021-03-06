#include "PreviewMDDoc.h"

void PreviewMDDoc::setText(const QString &text)
{
    if (text == m_text)
        return;
    m_text = text;
    emit textChanged(m_text);
}
