/*
* Copyright (C) 2019 ~ 2021 Uniontech Software Technology Co.,Ltd
*
* Author:      baohaifeng <baohaifeng@uniontech.com>
* Maintainer:  baohaifeng <baohaifeng@uniontech.com>
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

//self
#include "compact_cpu_monitor.h"
#include "model/cpu_info_model.h"

//gtest
#include "stub.h"
#include <gtest/gtest.h>

//qt
#include <DApplication>
#include <QPaintEvent>
#include <QMouseEvent>

/***************************************STUB begin*********************************************/

qreal stub_cpuAllPercent_noNum()
{
    qreal cpu = 1;
    return cpu;
}

QList<qreal> stub_cpuPercentList_small()
{
    QList<qreal> percentList;
    percentList<<10<<20<<30<<40<<50<<10<<20<<30<<40<<50<<10<<20<<30<<40<<50
                 <<10<<20<<30<<40<<50<<10<<20<<30<<40<<50<<10<<20<<30<<40<<50;
    return percentList;
}

QList<qreal> stub_cpuPercentList_big()
{
    QList<qreal> percentList;
    percentList<<10<<20<<30<<40<<50<<10<<20<<30<<40<<50<<10<<20<<30<<40<<50
                 <<10<<20<<30<<40<<50<<10<<20<<30<<40<<50<<10<<20<<30<<40<<50;
    return percentList;
}

/***************************************STUB end**********************************************/


class UT_CompactCpuMonitor: public ::testing::Test
{
public:
    UT_CompactCpuMonitor() : m_tester(nullptr) {}

public:
    virtual void SetUp()
    {
        m_tester = new CompactCpuMonitor();
    }

    virtual void TearDown()
    {
        if (m_tester) {
            delete m_tester;
            m_tester = nullptr;
        }
    }

protected:
    CompactCpuMonitor *m_tester;
};

TEST_F(UT_CompactCpuMonitor, initTest)
{
}

TEST_F(UT_CompactCpuMonitor, test_onDetailInfoClicked)
{
    m_tester->onDetailInfoClicked();
}

TEST_F(UT_CompactCpuMonitor, test_updateStatus_01)
{
    Stub stub;
    stub.set(ADDR(CPUInfoModel, cpuAllPercent), stub_cpuAllPercent_noNum);
    m_tester->updateStatus();
}

TEST_F(UT_CompactCpuMonitor, test_updateStatus_02)
{
    Stub stub;
    stub.set(ADDR(CPUInfoModel, cpuPercentList), stub_cpuPercentList_small);
    m_tester->updateStatus();
}

TEST_F(UT_CompactCpuMonitor, test_updateStatus_03)
{
    Stub stub;
    stub.set(ADDR(CPUInfoModel, cpuPercentList), stub_cpuPercentList_big);
    m_tester->updateStatus();
}


TEST_F(UT_CompactCpuMonitor, test_setDetailButtonVisible)
{
    m_tester->setDetailButtonVisible(true);
}

TEST_F(UT_CompactCpuMonitor, test_resizeEvent)
{
    QResizeEvent *event = nullptr;
    m_tester->resizeEvent(event);
}

TEST_F(UT_CompactCpuMonitor, test_resizeItemRect)
{
    m_tester->resizeItemRect();
}

TEST_F(UT_CompactCpuMonitor, test_paintEvent)
{
    EXPECT_FALSE(m_tester->grab().isNull());
}

TEST_F(UT_CompactCpuMonitor, test_changeFont)
{
    QFont font;
    font.setWeight(QFont::Medium);
    m_tester->changeFont(font);
}

TEST_F(UT_CompactCpuMonitor, test_mouseReleaseEvent)
{
    QMouseEvent *event = new QMouseEvent(QEvent::Type::Move, QPointF(0, 0), Qt::MouseButton::LeftButton, Qt::MouseButton::LeftButton, Qt::KeyboardModifier::ShiftModifier);
    m_tester->mouseReleaseEvent(event);
    delete event;
}

TEST_F(UT_CompactCpuMonitor, test_mouseMoveEvent)
{
    QMouseEvent *event = new QMouseEvent(QEvent::Type::Move, QPointF(0, 0), Qt::MouseButton::LeftButton, Qt::MouseButton::LeftButton, Qt::KeyboardModifier::ShiftModifier);
    m_tester->mouseMoveEvent(event);
    delete event;
}
