#ifndef EVENT_H
#define EVENT_H

#include <iostream>


class Event {
private:

	std::string eventName;
	std::string eventDate;

public:

	Event(std::string eventName, std::string eventDate)
		: eventName(eventName), eventDate(eventDate)
	{}

	Event() {}

	std::string getEventName() {
		return eventName;
	}

	std::string getEventDate() {
		return eventDate;
	}

	void setEventName() {
		this->eventName = eventName;
	}

	void setEventData() {
		this->eventDate = eventDate;
	}
};

class EventCreator {

};
#endif