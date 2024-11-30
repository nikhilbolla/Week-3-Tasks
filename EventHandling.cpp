#include <iostream>
#include <queue>
#include <list>
#include <string>
#include <ctime>  // for time function

using namespace std;

struct coordinate
{
    int x;
    int y;

    coordinate(int x, int y) : x(x), y(y) {}
};

struct swipeCoordinate
{
    coordinate a;
    coordinate b;

    swipeCoordinate(coordinate a, coordinate b) : a(a), b(b) {}
};

struct Event
{
    string eventType;
    string timeStamp;
    swipeCoordinate swipe;
    coordinate touch;
    Event(string eT, string tS, swipeCoordinate sC, coordinate t) : eventType(eT), timeStamp(tS), swipe(sC), touch(t) {}
};


class EventHandling
{
    queue<Event> events;

    void calcSwipeDirection(swipeCoordinate sc)
    {
        if ((sc.a.x && sc.a.y) && (sc.b.x && sc.b.y))
        {
            if ((sc.a.y == sc.b.y) && (sc.a.x < sc.b.x))
            {
                cout << "Right Swipe" << endl;
            }

            if ((sc.a.y == sc.b.y) && (sc.a.x > sc.b.x))
            {
                cout << "Left Swipe" << endl;
            }

            if ((sc.a.x == sc.b.x) && (sc.a.y < sc.b.y))
            {
                cout << "Up Swipe" << endl;
            }

            if ((sc.a.x == sc.b.x) && (sc.a.y > sc.b.y))
            {
                cout << "Down Swipe" << endl;
            }
        }
    }

    void addEvent(Event event)
    {
        events.push(event);
    }

public:
    void eventHandler()
    {
        while (!events.empty())
        {
            Event event = events.front();  // Get the front of the queue, not the back
            cout << "Event Type: " << event.eventType << endl;
            cout << "Event Positions: ";
            if (event.eventType == "Swipe")
            {
                calcSwipeDirection(event.swipe);
            }
            else
            {
                cout << "Touch detected: ";
                cout << "X: " << event.touch.x << ", Y: " << event.touch.y << endl;
            }
            cout << "Event Timestamp: " << event.timeStamp << endl;
            events.pop();
        }
    }

    void randomEventGenerator()
    {
        srand((unsigned)time(0));  // Correct the time function
        for (int i = 0; i < 10; i++)
        {
            int ranNum = (rand() % 2) + 1;

            if (ranNum == 1)  // Correct the comparison operator here
            {
                int x1, y1;
                x1 = (rand() % 10);
                y1 = (rand() % 10);

                int x2, y2;
                x2 = (rand() % 10);
                y2 = (rand() % 10);

                coordinate newCoordinate1 = {x1, y1};
                coordinate newCoordinate2 = {x2, y2};

                swipeCoordinate newSwipe = {newCoordinate1, newCoordinate2};
                coordinate newTouch = {0, 0};

                Event newEvent = {"Swipe", "23/01/2024", newSwipe, newTouch};

                addEvent(newEvent);
            }
            else
            {
                int x, y;
                x = (rand() % 10);
                y = (rand() % 10);

                coordinate newCoordinate1 = {0, 0};
                coordinate newCoordinate2 = {0, 0};

                swipeCoordinate newSwipe = {newCoordinate1, newCoordinate2};
                coordinate newTouch = {x, y};

                Event newEvent = {"Touch", "23/01/2024", newSwipe, newTouch};
                addEvent(newEvent);
            }
        }
    }
};

int main()
{
    EventHandling eventLogger;
    eventLogger.randomEventGenerator();
    eventLogger.eventHandler();
}
