/*
 *   Copyright (C) 2017 Kai Uwe Broulik <kde@privat.broulik.de>
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU Library General Public License version 2 as
 *   published by the Free Software Foundation
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details
 *
 *   You should have received a copy of the GNU Library General Public
 *   License along with this program; if not, write to the
 *   Free Software Foundation, Inc.,
 *   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#pragma once

#include <KRunner/AbstractRunner>

#include <QDBusMessage>

class TabsRunner : public Plasma::AbstractRunner
{
    Q_OBJECT

public:
    TabsRunner(QObject *parent, const QVariantList &args);
    ~TabsRunner() override;

    void match(Plasma::RunnerContext &context) override;
    void run(const Plasma::RunnerContext &context, const Plasma::QueryMatch &action) override;

protected slots:
    QMimeData *mimeDataForMatch(const Plasma::QueryMatch &match) override;
    QList<QAction *> actionsForMatch(const Plasma::QueryMatch &match) override;

private:
    static QDBusMessage createMessage(const QString &method);

};
