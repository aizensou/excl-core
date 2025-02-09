// Copyright (c) 2017-2018 The EXCL developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef ZEXCLCONTROLDIALOG_H
#define ZEXCLCONTROLDIALOG_H

#include <QDialog>
#include <QTreeWidgetItem>
#include "zexcl/zerocoin.h"
#include "privacydialog.h"

class CZerocoinMint;
class WalletModel;

namespace Ui {
class ZExclControlDialog;
}

class CZExclControlWidgetItem : public QTreeWidgetItem
{
public:
    explicit CZExclControlWidgetItem(QTreeWidget *parent, int type = Type) : QTreeWidgetItem(parent, type) {}
    explicit CZExclControlWidgetItem(int type = Type) : QTreeWidgetItem(type) {}
    explicit CZExclControlWidgetItem(QTreeWidgetItem *parent, int type = Type) : QTreeWidgetItem(parent, type) {}

    bool operator<(const QTreeWidgetItem &other) const;
};

class ZExclControlDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ZExclControlDialog(QWidget *parent);
    ~ZExclControlDialog();

    void setModel(WalletModel* model);

    static std::set<std::string> setSelectedMints;
    static std::set<CMintMeta> setMints;
    static std::vector<CMintMeta> GetSelectedMints();

private:
    Ui::ZExclControlDialog *ui;
    WalletModel* model;
    PrivacyDialog* privacyDialog;

    void updateList();
    void updateLabels();

    enum {
        COLUMN_CHECKBOX,
        COLUMN_DENOMINATION,
        COLUMN_PUBCOIN,
        COLUMN_VERSION,
        COLUMN_PRECOMPUTE,
        COLUMN_CONFIRMATIONS,
        COLUMN_ISSPENDABLE
    };
    friend class CZExclControlWidgetItem;

private slots:
    void updateSelection(QTreeWidgetItem* item, int column);
    void ButtonAllClicked();
};

#endif // ZEXCLCONTROLDIALOG_H
