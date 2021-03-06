/*
 * Copyright 2019 garciafa
 * This file is part of PprzLinkCPP
 *
 * PprzLinkCPP is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * PprzLinkCPP is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with ModemTester.  If not, see <https://www.gnu.org/licenses/>.
 *
 */

/** \file Transport.h
 *
 *
 */

#ifndef PPRZLINKCPP_TRANSPORT_H
#define PPRZLINKCPP_TRANSPORT_H


#include "Message.h"
#include "Device.h"
#include "MessageDictionary.h"
#include <memory>
#include <type_traits>

namespace pprzlink {
  class Transport {
  public:
    explicit Transport(Device *device, const MessageDictionary &dictionary) : device(device), dictionary(dictionary)
    {}

    virtual bool hasMessage() =0;

    virtual std::unique_ptr<Message> getMessage()  = 0;

    /**
     *
     * @param msg
     * @return the number of bytes actually sent on the device
     */
    virtual size_t sendMessage(Message const & msg) = 0;

    Device *getDevice() const
    {
      return device;
    }

    void setDevice(Device *dev)
    {
      Transport::device = dev;
    }

  protected:
    Device * device;
    const MessageDictionary &dictionary;
  };
}
#endif //PPRZLINKCPP_TRANSPORT_H
