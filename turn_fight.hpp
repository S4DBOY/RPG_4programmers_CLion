#include <functional>
#include <map>
#include <iostream>
#include <iterator>

class fight_span {
public:
    using time_type = size_t;
    using action_type = std::function<void()>;
    using actions_map = std::multimap<time_type, action_type>;
    
    fight_span(actions_map const &actions, time_type current_turn = 0): 
        actions(actions),
        current_turn_(current_turn)
    {}
    
    auto current_turn() const {
        return current_turn_;
    }
    
    bool good() const {
        if(!actions.size()) {
            return false;
        }
           
        if(actions.rbegin()->first < current_turn()) {
            return false;
        }
        
        return true;
    }
    
    operator bool() const {
        return good();
    }
    
    bool operator!() const {
        return !good();
    }
    
    bool next_turn() {
        current_turn_ += 1;
        return good();
    }
    
    size_t fire_actions() const {
        auto range = actions.equal_range(current_turn());
        for(auto it = range.first; it != range.second; ++it) {
            it->second();
        }
        return std::distance(range.first, range.second);
    }
private:
    actions_map actions;
    
    time_type current_turn_;
};

int main() {
    using namespace std;
    
    auto fight = fight_span({
        { 0, []{ cout << "~~hello world" << endl; } },
        { 2, []{ cout << "~~burn the world" << endl; } },
        { 2, []{ cout << "~~dude, pick up the flower" << endl; } },
        { 3, []{ cout << "~~c\'mon, pick it up!" << endl; } }
    });
    
    do {
        cout << "#turn: " << fight.current_turn() << endl;
        auto actions_fired = fight.fire_actions();
        cout << "#actions fired: " << actions_fired << endl << endl;
    } while(fight.next_turn());
    return 0;
}
