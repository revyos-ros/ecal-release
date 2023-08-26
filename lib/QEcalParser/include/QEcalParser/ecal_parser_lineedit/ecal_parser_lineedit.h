/* ========================= eCAL LICENSE =================================
 *
 * Copyright (C) 2016 - 2019 Continental Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *      http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * ========================= eCAL LICENSE =================================
*/

#pragma once

#include <QLineEdit>

class QEcalParserLineEdit : public QLineEdit
{
  Q_OBJECT

public:
  QEcalParserLineEdit(QWidget *parent = Q_NULLPTR);
  QEcalParserLineEdit(const QString &contents, QWidget *parent = Q_NULLPTR);

  ~QEcalParserLineEdit();

protected:
  void contextMenuEvent(QContextMenuEvent *event) override;
  void changeEvent(QEvent *event) override;

private slots:
  void openDialog();

private:
  void adaptIconsToTheme();

private:
  QAction* open_dialog_action_;
};
