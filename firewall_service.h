// Copyright 2014 The Chromium OS Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef FIREWALLD_FIREWALL_SERVICE_H_
#define FIREWALLD_FIREWALL_SERVICE_H_

#include <base/callback.h>
#include <base/macros.h>
#include <base/memory/scoped_ptr.h>
#include <chromeos/dbus/dbus_object.h>

#include "firewalld/dbus_adaptor/org.chromium.Firewalld.h"
#include "firewalld/iptables.h"

using CompletionAction =
    chromeos::dbus_utils::AsyncEventSequencer::CompletionAction;

namespace firewalld {

class FirewallService : public org::chromium::FirewalldAdaptor {
 public:
  explicit FirewallService(const scoped_refptr<dbus::Bus>& bus);
  virtual ~FirewallService() = default;

  // Connects to D-Bus system bus and exports methods.
  void RegisterAsync(const CompletionAction& callback);

 private:
  chromeos::dbus_utils::DBusObject dbus_object_;
  IpTables iptables_;

  DISALLOW_COPY_AND_ASSIGN(FirewallService);
};

}  // namespace firewalld

#endif  // FIREWALLD_FIREWALL_SERVICE_H_
