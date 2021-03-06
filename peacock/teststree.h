#ifndef TESTSTREE_H
#define TESTSTREE_H

#include "peacock.h"

#include <QWidget>
#include <QTreeWidget>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>

class TestsTree : public QWidget
{
    Q_OBJECT
public:
    TestsTree(QWidget *parent = 0);
    TestsTree(TestNode *root, QWidget *parent = 0);

    void set_tests_tree(TestNode *root);
    bool display_tree();
    QList<TestCase> get_selected_tests();

protected:
    QTreeWidgetItem* build_tests_tree(TestNode *root, QTreeWidgetItem *parent);
private:
    TestNode *tests_root;
    QTreeWidget *tests_tree;
    bool  m_check_child;
    bool  m_check_parent;
    bool  m_check_start;

    TestNode* find_test_node(QTreeWidgetItem *item);

    TestNode* get_test_node(QStringList path);

    QStringList get_test_path(QTreeWidgetItem *item);

signals:
    void tests_chnaged();
public slots:
    void select_tests_node(QTreeWidgetItem *item, int column);
};

#endif // TESTSTREE_H
