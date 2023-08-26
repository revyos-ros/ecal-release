// Copyright (c) Continental. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for details.

#include <iostream>
#include <thread>
#include <thread>

#include <atomic>

#include <tcp_pubsub/executor.h>
#include <tcp_pubsub/subscriber.h>

std::atomic<int> messages_received;

void printLog()
{
  for (;;)
  {
    int messages_received_temp = messages_received.exchange(0);
    std::cout << "Received " << messages_received_temp << " in 1 second" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
}

int main() {
  std::shared_ptr<tcp_pubsub::Executor> executor = std::make_shared<tcp_pubsub::Executor>(6, tcp_pubsub::logger::logger_no_verbose_debug);

  tcp_pubsub::Subscriber performance_subscriber(executor);
  performance_subscriber.addSession("127.0.0.1", 1588);

  std::thread print_thread(printLog);

  performance_subscriber.setCallback([](const auto& callback_data) ->void 
                                        {
                                          messages_received++;
                                        });


  // Prevent the application from exiting immediatelly
  for (;;)
  {
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }
}
