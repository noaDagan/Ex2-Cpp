#ifndef PROJECTNUM2_STATE_H
#define PROJECTNUM2_STATE_H

template<class VALUE>
class State  {
    VALUE state;
    double cost;
    State<VALUE>* cameFrom;
public:
    State() {
    }

    State<VALUE>* getCameFrom() {
        return this->cameFrom;
    }

    bool equal(State<VALUE>* states) {
        return this->state == states->state;
    }

    void setCameFrom(State<VALUE>* states) {
        this->cameFrom = states;
    }


    void setCost(double cost) {
        State::cost = cost;
    }

    void setState(VALUE state) {
        State::state = state;
    }

    VALUE getState() const {
        return state;
    }

    double getCost() const {
        return cost;
    }

};


#endif //PROJECTNUM2_STATE_H
