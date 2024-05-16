#pragma once

#include <QJsonObject>
#include <QString>
#include <QVector>

#include "MemWatchEntry.h"

class MemWatchTreeNode
{
public:
  explicit MemWatchTreeNode(MemWatchEntry* entry, MemWatchTreeNode* parent = nullptr,
                            bool isGroup = false, QString groupName = {});
  ~MemWatchTreeNode();

  MemWatchTreeNode(const MemWatchTreeNode&) = delete;
  MemWatchTreeNode(MemWatchTreeNode&&) = delete;
  MemWatchTreeNode& operator=(const MemWatchTreeNode&) = delete;
  MemWatchTreeNode& operator=(MemWatchTreeNode&&) = delete;

  bool isGroup() const;
  QString getGroupName() const;
  void setGroupName(const QString& groupName);
  MemWatchEntry* getEntry() const;
  void setEntry(MemWatchEntry* entry);
  QVector<MemWatchTreeNode*> getChildren() const;
  void setChildren(QVector<MemWatchTreeNode*> children);
  MemWatchTreeNode* getParent() const;
  void setParent(MemWatchTreeNode* parent);
  int getRow() const;
  bool isValueEditing() const;
  bool hasChildren() const;
  int childrenCount() const;
  void setValueEditing(bool valueEditing);

  void appendChild(MemWatchTreeNode* node);
  void insertChild(int row, MemWatchTreeNode* node);
  void removeChild(int row);
  void removeChildren();

  void readFromJson(const QJsonObject& json, MemWatchTreeNode* parent = nullptr);
  void writeToJson(QJsonObject& json) const;
  QString writeAsCSV() const;

private:
  bool m_isGroup;
  bool m_isValueEditing = false;
  QString m_groupName;
  MemWatchEntry* m_entry;
  QVector<MemWatchTreeNode*> m_children;
  MemWatchTreeNode* m_parent;
};
