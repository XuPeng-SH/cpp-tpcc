#pragma once

#include <duckdb.hpp>
#include <duckdb/main/connection.hpp>
#include <duckdb/main/database.hpp>
#include <memory>

#include "Types.h"
#include "Context.h"
#include "Driver.h"

class DuckdbDriver : public Driver {
 public:
     explicit DuckdbDriver(std::shared_ptr<duckdb::Connection> conn) : conn_(conn) {
     }

     bool
     DoDelivery(TpccContextPtr& ctx) override;
     bool
     DoNewOrder(TpccContextPtr& ctx) override;
     bool
     DoPayment(TpccContextPtr& ctx) override;
     bool
     DoOrderStatus(TpccContextPtr& ctx) override;
     bool
     DoStockLevel(TpccContextPtr& ctx) override;

     void
     ForceRollBack(TpccContextPtr&) override;

 protected:
     std::shared_ptr<duckdb::Connection> conn_;
};

using DuckdbDriverPtr = std::shared_ptr<DuckdbDriver>;
