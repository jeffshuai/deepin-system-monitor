#ifndef NETIF_STAT_VIEW_WIDGET_H
#define NETIF_STAT_VIEW_WIDGET_H

#include <DScrollArea>
#include <QMap>

class ChartViewWidget;
class NetifInfoModel;
class QGridLayout;
class NetifItemViewWidget;

namespace core {
namespace system {
class NetifInfoDB;
}
}

DWIDGET_USE_NAMESPACE
class NetifStatViewWidget : public DScrollArea
{
    Q_OBJECT
public:
    explicit NetifStatViewWidget(QWidget *parent = nullptr);
    void updateWidgetGeometry();

private:
    void showItemOnlyeOne();
    void showItemDouble();
    void showItemLgDouble();

protected:
    void resizeEvent(QResizeEvent *event);

public slots:
    void fontChanged(const QFont &font);

    void onModelUpdate();
    void onSetItemActiveStatus(const QString &mac);

private:
    core::system::NetifInfoDB *m_info;

    QWidget *m_centralWidget;
    QMap<QByteArray, NetifItemViewWidget *> m_mapItemView;
};

#endif // NETIF_STAT_VIEW_WIDGET_H
