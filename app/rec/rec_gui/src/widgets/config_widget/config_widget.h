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

#include <QWidget>
#include "ui_config_widget.h"

class ConfigWidget : public QWidget
{
  Q_OBJECT

public:
  ConfigWidget(QWidget *parent = Q_NULLPTR);
  ~ConfigWidget();

private slots:
  void measurementRootDirectoryChanged (const std::string& root_dir);
  void measurementNameChanged          (const std::string& name);
  void updatePathPreviewAndWarningLabel();
  void maxFileSizeChanged              (unsigned int megabytes);
  void oneFilePerTopicEnabledChanged   (bool enabled);
  void descriptionChanged              (const std::string& description);
  void userRecPathButtonPressed        ();

protected:
  void showEvent(QShowEvent *event) override;

private:
  Ui::ConfigWidget ui_;

  bool first_show_event_;
};
