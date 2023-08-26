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

namespace EcalPlayGlobals
{
  static const int VERSION_MAJOR = 2;
  static const int VERSION_MINOR = 0;
  static const int VERSION_PATCH = 0;

  static const char* const VERSION_STRING = "2.0";

  static const char* const ECAL_PLAY_NAME = "eCALPlay";

  static constexpr int Version()
  {
    return (VERSION_PATCH
      + (VERSION_MINOR * 1000)
      + (VERSION_MAJOR * 1000 * 1000));
  }
};