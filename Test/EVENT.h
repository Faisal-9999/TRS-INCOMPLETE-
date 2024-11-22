#ifndef EVENT_H
#define EVENT_H

#include <iostream>


class Event : public Entity {
private:

	std::string eventDate;

public:

	Event(std::string eventName, std::string eventDate)
		: Entity(eventName), eventDate(eventDate)
	{}

	Event() {}

	std::string getEventDate() {
		return eventDate;
	}

	void setEventDate() {
		this->eventDate = eventDate;
	}
};

class EventCreator {

};
#endif