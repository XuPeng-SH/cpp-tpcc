#pragma once

#include "TpccFactory.h"
#include <algorithm>
#include <memory>

class Driver {
 public:
    virtual bool
    DoDelivery(TpccContextPtr& ctx) = 0;
    virtual bool
    DoNewOrder(TpccContextPtr& ctx) = 0;
    virtual bool
    DoPayment(TpccContextPtr& ctx) = 0;
    virtual bool
    DoOrderStatus(TpccContextPtr& ctx) = 0;
    virtual bool
    DoStockLevel(TpccContextPtr& ctx) = 0;

    virtual void
    ForceRollBack(TpccContextPtr&) = 0;

    virtual ~Driver() {}
};

using DriverPtr = std::shared_ptr<Driver>;
