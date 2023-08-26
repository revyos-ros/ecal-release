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

/**
 * @brief  eCAL service server interface
**/

#pragma once

#include <ecal/ecal.h>
#include <ecal/ecal_callback.h>

#include "ecal_tcpserver.h"

#ifdef _MSC_VER
#pragma warning(push, 0) // disable proto warnings
#endif
#include <ecal/core/pb/ecal.pb.h>
#ifdef _MSC_VER
#pragma warning(pop)
#endif

#include <map>
#include <mutex>

namespace eCAL
{
  /**
   * @brief Service server implementation class.
  **/
  class CServiceServerImpl
  {
  public:
    CServiceServerImpl();
    CServiceServerImpl(const std::string& service_name_);

    ~CServiceServerImpl();

    bool Create(const std::string& service_name_);

    bool Destroy();

    bool AddDescription(const std::string& method_, const SDataTypeInformation& request_type_information_, const SDataTypeInformation& response_type_information_);
      
    // add and remove callback function for server method calls
    bool AddMethodCallback(const std::string& method_, const std::string& req_type_, const std::string& resp_type_, const MethodCallbackT& callback_);
    bool RemMethodCallback(const std::string& method_);

    // add and remove callback function for server events
    bool AddEventCallback(eCAL_Server_Event type_, ServerEventCallbackT callback_);
    bool RemEventCallback(eCAL_Server_Event type_);
      
    // check connection state
    bool IsConnected();

    // called by eCAL:CServiceGate every second to update registration layer
    void RefreshRegistration();

    std::string GetServiceName() { return m_service_name; };

    // this object must not be copied and moved
    CServiceServerImpl(const CServiceServerImpl&) = delete;
    CServiceServerImpl& operator=(const CServiceServerImpl&) = delete;
    CServiceServerImpl(CServiceServerImpl&&) = delete;
    CServiceServerImpl& operator=(CServiceServerImpl&&) = delete;

  protected:
    void Register(bool force_);
    void Unregister();

    /**
     * @brief Calls the request callback based on the request and fills the response
     * 
     * @param[in]  request_   The service request in serialized protobuf form
     * @param[out] response_  A serialized protobuf response. My not be set at all.
     * 
     * @return  0 if succeeded, -1 if not.
     */
    int RequestCallback(const std::string& request_, std::string& response_);
    void EventCallback(eCAL_Server_Event event_, const std::string& message_);

    bool ApplyServiceToDescGate(const std::string& method_name_
      , const SDataTypeInformation& request_type_information_
      , const SDataTypeInformation& response_type_information_);

    CTcpServer            m_tcp_server;

    static constexpr int  m_version = 0;
    std::string           m_service_name;
    std::string           m_service_id;

    struct SMethod
    {
      eCAL::pb::Method method_pb;
      MethodCallbackT  callback;
    };
    std::mutex            m_method_map_sync;
    using MethodMapT = std::map<std::string, SMethod>;
    MethodMapT m_method_map;

    std::mutex            m_event_callback_map_sync;
    using EventCallbackMapT = std::map<eCAL_Server_Event, ServerEventCallbackT>;
    EventCallbackMapT     m_event_callback_map;
    
    bool                  m_connected;
    bool                  m_created;
  };
}
