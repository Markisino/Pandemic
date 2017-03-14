#ifndef PANDEMIC_OBSERVER_H
#define PANDEMIC_OBSERVER_H

struct observer {
	virtual inline ~observer() {}

	virtual auto update() -> void = 0;
};

#endif //PANDEMIC_OBSERVER_H
