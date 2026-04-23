# Stock Trading System — C++ OOP Prototype

A multi-file C++ project demonstrating core object-oriented programming concepts through a simplified stock trading simulation.

---

## How to build and run

```bash
# Compile all source files
g++ *.cpp -o main

# Run
./main
```

---

## Project structure

```
.
├── main.cpp            # Entry point — drives all demo scenarios
├── Person.h / .cpp     # Base class for all people
├── User.h / .cpp       # Extends Person — holds portfolio & orders
├── Staff.h / .cpp      # Extends Person — handles complaints
├── Broker.h / .cpp     # Extends Person — manages users & orders
├── Stock.h / .cpp      # Represents a listed stock
├── Portfolio.h / .cpp  # Holds a user's stock holdings
├── TradeOrder.h / .cpp # A single BUY or SELL order
├── Complaint.h / .cpp  # A filed complaint with lifecycle status
└── Makefile            # Optional: run `make` instead of g++ manually
```

---

## Class overview

### Person (base class)
All people in the system inherit from this.

| Member | Description |
|---|---|
| `name`, `email` | Protected fields — accessible by subclasses |
| `getName()`, `getEmail()` | Read-only accessors |
| `login()`, `logout()` | Virtual — can be overridden |
| `displayInfo()` | Virtual — overridden by every subclass |
| `totalPersons` | Static counter — tracks live instances |

---

### User : public Person
A client account. Owns a `Portfolio` and tracks orders and complaints.

| Member | Description |
|---|---|
| `placeOrder(order*)` | Adds a `TradeOrder` to the user's orders array |
| `viewPortfolio()` | Prints the current portfolio with values |
| `fileComplaint(complaint*)` | Registers a complaint against the account |
| `getPortfolio()` | Returns a pointer to the internal `Portfolio` |
| `displayInfo()` | Overrides `Person::displayInfo()` |
| `totalUsers` | Static counter |

---

### Staff : public Person
Support staff who manage complaints.

| Member | Description |
|---|---|
| `resolveComplaint(complaint*)` | Sets complaint status to `RESOLVED` |
| `assignComplaint(complaint*, to)` | Sets status to `ASSIGNED` and logs assignee |
| `displayInfo()` | Overrides `Person::displayInfo()` |
| `totalStaff` | Static counter |

---

### Broker : public Person
A broker who manages users and processes their trade orders.

| Member | Description |
|---|---|
| `addUser(user*)` | Adds a user to the broker's managed list |
| `processOrder(order*)` | Calls `executeOrder()` on the given order |
| `handleComplaint(complaint*)` | Sets complaint status to `UNDER_REVIEW` |
| `displayInfo()` | Overrides `Person::displayInfo()` |
| `totalBrokers` | Static counter |

---

### Stock
A listed stock with a ticker, price, and available share count.

| Member | Description |
|---|---|
| `getTicker()`, `getPrice()`, `getShares()` | Read-only accessors |
| `updatePrice(newPrice)` | Logs and updates the price |
| `checkAvailability(qty)` | Returns `true` if enough shares exist |
| `reduceShares(qty)` / `addShares(qty)` | Mutation — called by `TradeOrder` |
| `displayInfo()` | Prints ticker, price, share count |
| `totalStocks` | Static counter |

---

### Portfolio
Owned by a `User` (by value, not pointer). Holds up to 10 stock positions.

| Member | Description |
|---|---|
| `addStock(stock*, qty)` | Adds shares; merges if ticker already present |
| `removeStock(ticker, qty)` | Reduces shares; removes slot if qty reaches 0 |
| `calculateValue()` | Returns total value of all holdings |
| `displayInfo()` | Prints each holding with per-stock and total value |

---

### TradeOrder
A single BUY or SELL order against a specific stock.

| Member | Description |
|---|---|
| `getStatus()` | Returns `PENDING`, `EXECUTED`, or `CANCELLED` |
| `getType()` | Returns `BUY` or `SELL` |
| `executeOrder()` | Checks availability, updates shares, marks EXECUTED |
| `cancelOrder()` | Cancels if not already executed |
| `displayInfo()` | Prints order details and current status |
| `totalOrders` | Static counter |

---

### Complaint
A support complaint with a lifecycle status.

| Member | Description |
|---|---|
| `getID()`, `getStatus()` | Read-only accessors |
| `updateStatus(newStatus)` | Transitions: `OPEN` → `UNDER_REVIEW` → `ASSIGNED` → `RESOLVED` |
| `displayInfo()` | Prints complaint ID, type, status, and date filed |
| `totalComplaints` | Static counter |

---

## OOP concepts demonstrated

| Concept | Where |
|---|---|
| **Inheritance** | `User`, `Staff`, `Broker` all extend `Person` with `: public Person` |
| **Polymorphism** | `showPersonInfo(Person* p)` in `main.cpp` — vtable dispatches to the correct `displayInfo()` at runtime |
| **Encapsulation** | All data fields are `private`; external access only via getters and controlled setters |
| **Static variables** | Every class has a `totalX` static counter incremented in constructor, decremented in destructor |
| **Composition** | `User` owns a `Portfolio` by value; `Portfolio` holds `Stock*` pointers |
| **Constructor chaining** | Subclass constructors call `: Person(name, email)` in the initialiser list |
| **Virtual destructor** | `~Person()` is virtual — ensures correct cleanup when deleting via base pointer |

---

## Complaint status lifecycle

```
OPEN → UNDER_REVIEW (broker handles) → ASSIGNED (staff assigns) → RESOLVED (staff resolves)
```

## Trade order status lifecycle

```
PENDING → EXECUTED (if shares available)
PENDING → CANCELLED (manual or insufficient shares)
```
