#include "../include/Summary.h"
#include "../include/event.h"

Summary::Summary(string userName, const string& gameName)
        : userName(userName), team_a_name(gameName.substr(0,gameName.find('_')))
        , team_b_name(gameName.substr(gameName.find('_')+1)), general_stats(),
          team_a_stats(), team_b_stats(), gameEvents(){}


void Summary::addEvent(Event &event)
{
    gameEvent gameEvent(event.get_time(), event.get_name(), event.get_description());

    sortedEventInsert(gameEvents, gameEvent);

    // update general stats
    for (auto &update : event.get_game_updates()) {
        general_stats[update.first] = update.second;
    }

    // update team a stats
    for (auto &update : event.get_team_a_updates()) {
        team_a_stats[update.first] = update.second;
    }

    // update team b stats
    for (auto &update : event.get_team_b_updates()) {
        team_b_stats[update.first] = update.second;
    }
}

string Summary::printSummary() {
        string summary = team_a_name + " vs " + team_b_name + "\n";
        summary += "Game Stats:\n";
        summary += "General Stats:\n";
        // Probably sorted alphabetically - need to make sure
        for (auto &general_stat: general_stats) {
                summary += general_stat.first + ": " + general_stat.second + "\n";
        }
        summary += "Team A Stats:\n";
        for (auto &team_a_stat: team_a_stats) {
                summary += team_a_stat.first + ": " + team_a_stat.second + "\n";
        }
        summary += "Team B Stats:\n";
        for (auto &team_b_stat: team_b_stats) {
                summary += team_b_stat.first + ": " + team_b_stat.second + "\n";
        }
        summary += "Game Events:\n";
        for (auto &gameEvent: gameEvents) {
                summary += to_string(gameEvent.time) + " - " + gameEvent.name + "\n" +
                           gameEvent.description + "\n";
        }
        return summary;
}

void Summary::sortedEventInsert(list<gameEvent>& eventList, gameEvent& event) {

    if(eventList.empty() || eventList.back().time < event.time) {
        eventList.push_back(event);
    }
    else {
        for (auto it = eventList.begin(); it != eventList.end(); it++) {
            if (it->time >= event.time) {
                eventList.insert(it, event);
                break;
            }
        }
    }

    /*
     * this is an optimized insertion sort algorithm, but it's more complex and
     * I figured it's not worth the hassle for this assignment, so I commented it out
     * and left a less efficient but simpler implementation.

    // first item inserted
    if(eventList.empty()){
        eventList.push_back(event);
    }

    // optimization for last item
    else if (eventList.back().time < event.time){
        eventList.push_back(event);
    }

    // optimization for first item
    else if (eventList.front().time > event.time){
        eventList.push_front(event);
    }

    else{
        // optimization for deciding whether to start from the start or end
        // based on the average time value
        int avgTime = (eventList.front().time + eventList.back().time)/2;

        // start from the beginning
        if(event.time <= avgTime)
        {
            for(auto it = eventList.begin(); it != eventList.end(); ++it) {
                if (it->time >= event.time) {
                    eventList.insert(it, event);
                    return;
                }
            }
        }

        // start from the end
        else{
            for(auto it = eventList.rbegin(); it != eventList.rend(); ++it) {
                if (it->time <= event.time) {
                    it--;
                    eventList.insert(it.base(), event);
                    return;
                }
            }
        }
    }
    */
}



