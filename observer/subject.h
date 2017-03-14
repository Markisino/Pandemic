#ifndef PANDEMIC_SUBJECT_H
#define PANDEMIC_SUBJECT_H

#include <list>
#include "./observer.h"

struct subject {
	virtual inline ~subject() {}

	virtual inline auto attach(observer *const o) -> void {
		observers.push_back(o);
	}

	virtual inline auto detach(observer *const o) -> void {
		observers.remove(o);
	}

	virtual inline auto notify() -> void {
		for (auto &i : observers) {
			i->update();
		}
	}

private:
	std::list<observer *const> observers;
};

#endif //PANDEMIC_SUBJECT_H
