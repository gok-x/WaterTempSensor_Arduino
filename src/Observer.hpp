#ifndef _OBSERVER_HPP_
#define _OBSERVER_HPP_

class Subject;

class Observer {
    public:
    virtual ~Observer();
    virtual void Update(Subject* theChangedSubject) = 0;

    protected:
    Observer();
};

#endif