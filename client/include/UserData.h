#pragma once

#include <mutex>
#include <condition_variable>
#include <queue>
#include <list>
#include <unordered_map>


class ConnectionHandler;
class Frame;
class Event;
class Summary;
struct GameReport{
        string reporter;
        string gameName;
        GameReport(string reporter, string gameName) : reporter(reporter), gameName(gameName) {}
};
using namespace std;

class UserData{

    //====================================================================================|
    //================================ Fields ============================================|
    //====================================================================================|

    private:

        static UserData* instance;

        bool shouldTerminateFlag;
        bool connected;
        int nextReceiptNumber;
        int nextSubscriptionNumber;
        string userName;
        mutex m;
        condition_variable cv;
        ConnectionHandler* handler;
        queue<Frame*> frameQueue;
        list<Event*> gameEvents;
        unordered_map<string, int> gameNameToSubId;
        unordered_map<int, string> subIdToGameName;
        //unordered_map<GameReport, Summary> gameSummaries;





    //====================================================================================|
    //================================ Methods ===========================================|
    //====================================================================================|
    
    public:

        // we need these to be deleted functions so the compiler would not
        // allow us to use a copy constructor and a copy assignment operator
        // also it gives warnings because we have pointers and didn't implement these
        // so it's necessary to delete these methods.
        UserData(const UserData&) = delete; 
        UserData& operator=(const UserData&) = delete;

        mutex& getLock();

        bool isConnected();
        void setConnected(bool connected);

        void setUserName(string userName);
        string& getUserName();

        void wait();
        void notifyAll();

        void addAction(Frame* frame);
        queue<Frame*>& getFrameQueue();
        ConnectionHandler& getHandler();
        void setHandler(ConnectionHandler& handler);
        int getReceiptId();
        int generateSubId(string topic);
        int getSubId(string topic);
        string getGameName(int subId);
        void addGameEvent(Event* gameEvent);


        bool shouldTerminate();
        void terminate();

        static UserData& getInstance();
        static void deleteInstance(bool,bool,bool);

    private:
    
        UserData(); // Private constructor. May want to create an actual constructor later. 
        ~UserData();
        
};
