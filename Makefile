CXX      = g++
CXXFLAGS = -std=c++11 -Wall -g

SRCS = main.cpp Person.cpp Stock.cpp Portfolio.cpp \
       Complaint.cpp TradeOrder.cpp User.cpp Staff.cpp Broker.cpp

OBJS   = $(SRCS:.cpp=.o)
TARGET = trading_system

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
