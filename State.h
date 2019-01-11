#ifndef PROJECTNUM2_STATE_H
#define PROJECTNUM2_STATE_H

template<class VALUE>
class State {
    VALUE state;
    double cost;
    State<VALUE> *cameFrom;
public:

    //Constructor
    State() {
    }

    /**
     * The function returns the previous state
     */
    State<VALUE> *getCameFrom() {
        return this->cameFrom;
    }

    /**
     * The function compare between the current state to the state received
     */
    bool equal(State<VALUE> *states) {
        return this->state == states->state;
    }

    /**
     * The function set the state the current state came from
     */
    void setCameFrom(State<VALUE> *states) {
        this->cameFrom = states;
    }

    /**
     * The function set the state cost
     */
    void setCost(double cost) {
        State::cost = cost;
    }

    /**
   * The function set the state name
   */
    void setState(VALUE state) {
        State::state = state;
    }

    /**
     * The function returns the name of the sate
     */
    VALUE getState() const {
        return state;
    }

    /**
     * The function returns the cost of the sate
     */
    double getCost() const {
        return cost;
    }

};


#endif //PROJECTNUM2_STATE_H
