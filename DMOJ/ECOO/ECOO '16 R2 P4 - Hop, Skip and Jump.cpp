#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <unordered_set>
#include <vector>
 
using namespace std;
 
typedef pair<int, int> pii;
 
const char PLATFORM = '=';
const char LADDER = '#';
const char CLEAR = '.';
 
const char CUP = 'C';
const char FLAG = 'F';
const char TREASURE = 'T';
 
const char HOP = 'h';
const char SKIP = 's';
const char JUMP = 'j';
 
const int maxW = 200;
const int maxH = 200;
 
const int numberOfTestCases = 10;
 
int w, h;
 
char graph[maxW][maxH];
bool visited[maxW][maxH];
 
pii hop, skip, jump, cup, flag, treasure;



void readGraph()
{
    cin >> w >> h;
    for (int a = 0; a < h; a++)
    {
        for (int b = 0; b < w; b++)
        {
            cin >> graph[a][b];
            switch (graph[a][b])
            {
            case HOP:
                hop = make_pair(a, b);
                graph[a][b] = CLEAR;
                break;
            case SKIP:
                skip = make_pair(a, b);
                graph[a][b] = CLEAR;
                break;
            case JUMP:
                jump = make_pair(a, b);
                graph[a][b] = CLEAR;
                break;
            case CUP:
                cup = make_pair(a, b);
                graph[a][b] = CLEAR;
                break;
            case FLAG:
                flag = make_pair(a, b);
                graph[a][b] = CLEAR;
                break;
            case TREASURE:
                treasure = make_pair(a, b);
                graph[a][b] = CLEAR;
                break;
            }
        }
    }
}
 
vector<pii> getBasicMoves(pii startingLocation, bool &falling)
{
    auto moves = vector<pii>();
    char currentLocation = graph[startingLocation.first][startingLocation.second];

    if (currentLocation == CLEAR)
    {
        if (startingLocation.first == h - 1)
        {
            falling = true;
            return moves; 
        }
        if (graph[startingLocation.first + 1][startingLocation.second] == CLEAR)
        {
            moves.push_back(make_pair(startingLocation.first + 1, startingLocation.second));
            falling = true;
            return moves;
        }
    }
 
    if (currentLocation == CLEAR || currentLocation == LADDER)
    {
        if (startingLocation.second > 0 && graph[startingLocation.first][startingLocation.second - 1] != PLATFORM)
        {
            moves.push_back(make_pair(startingLocation.first, startingLocation.second - 1)); 
        }
        if (startingLocation.second < w - 1 && graph[startingLocation.first][startingLocation.second + 1] != PLATFORM)
        {
            moves.push_back(make_pair(startingLocation.first, startingLocation.second + 1)); 
        }
    }

    if (currentLocation == LADDER)
    {
        if (startingLocation.first > 0 && graph[startingLocation.first - 1][startingLocation.second] != PLATFORM)
        {
            moves.push_back(make_pair(startingLocation.first - 1, startingLocation.second)); 
        }
        if (startingLocation.first < h - 1 && graph[startingLocation.first + 1][startingLocation.second] != PLATFORM)
        {
            moves.push_back(make_pair(startingLocation.first + 1, startingLocation.second)); 
        }
    }
    falling = false;
    return moves;
}
 
vector<pii> getHopMoves(pii startingLocation)
{
    auto moves = vector<pii>();

    if (startingLocation.first > 0 && graph[startingLocation.first - 1][startingLocation.second] != PLATFORM)
    {
        moves.push_back(make_pair(startingLocation.first - 1, startingLocation.second)); 
        if (startingLocation.second > 0 && graph[startingLocation.first - 1][startingLocation.second - 1] != PLATFORM)
        {
            moves.push_back(make_pair(startingLocation.first - 1, startingLocation.second - 1)); 
        }
        if (startingLocation.second < w - 1 && graph[startingLocation.first - 1][startingLocation.second + 1] != PLATFORM)
        {
            moves.push_back(make_pair(startingLocation.first - 1, startingLocation.second + 1)); 
        }
    }
    return moves;
}
 
vector<pii> getSkipMoves(pii startingLocation)
{
    auto moves = vector<pii>();

    if (startingLocation.second > 1
        && graph[startingLocation.first][startingLocation.second - 1] != PLATFORM
        && graph[startingLocation.first][startingLocation.second - 2] != PLATFORM)
    {
        moves.push_back(make_pair(startingLocation.first, startingLocation.second - 2)); 
    }
    if (startingLocation.second < w - 2
        && graph[startingLocation.first][startingLocation.second + 1] != PLATFORM
        && graph[startingLocation.first][startingLocation.second + 2] != PLATFORM)
    {
        moves.push_back(make_pair(startingLocation.first, startingLocation.second + 2)); 
    }
    return moves;
}
 
vector<pii> getJumpMoves(pii startingLocation)
{
    auto moves = vector<pii>();

    if (startingLocation.second > 2
        && graph[startingLocation.first][startingLocation.second - 1] != PLATFORM
        && graph[startingLocation.first][startingLocation.second - 2] != PLATFORM
        && graph[startingLocation.first][startingLocation.second - 3] != PLATFORM)
    {
        moves.push_back(make_pair(startingLocation.first, startingLocation.second - 3)); 
    }
    if (startingLocation.second < w - 3
        && graph[startingLocation.first][startingLocation.second + 1] != PLATFORM
        && graph[startingLocation.first][startingLocation.second + 2] != PLATFORM
        && graph[startingLocation.first][startingLocation.second + 3] != PLATFORM)
    {
        moves.push_back(make_pair(startingLocation.first, startingLocation.second + 3)); 
    }

    if (startingLocation.first > 1
        && graph[startingLocation.first - 1][startingLocation.second] != PLATFORM
        && graph[startingLocation.first - 2][startingLocation.second] != PLATFORM)
    {
        moves.push_back(make_pair(startingLocation.first - 2, startingLocation.second)); 
    }

    if (startingLocation.first > 0 && graph[startingLocation.first - 1][startingLocation.second] != PLATFORM)
    {
        if (startingLocation.second > 1
            && graph[startingLocation.first][startingLocation.second - 1] != PLATFORM
            && graph[startingLocation.first - 1][startingLocation.second - 1] != PLATFORM
            && graph[startingLocation.first - 1][startingLocation.second - 2] != PLATFORM)
        {
            moves.push_back(make_pair(startingLocation.first - 1, startingLocation.second - 2)); 
        }
        if (startingLocation.second < w - 2
            && graph[startingLocation.first][startingLocation.second + 1] != PLATFORM
            && graph[startingLocation.first - 1][startingLocation.second + 1] != PLATFORM
            && graph[startingLocation.first - 1][startingLocation.second + 2] != PLATFORM)
        {
            moves.push_back(make_pair(startingLocation.first - 1, startingLocation.second + 2)); 
        }
    }
    return moves;
}
 
vector<pii> getAvailableMoves(pii startingLocation, char player)
{
    auto moves = vector<pii>();
    bool falling = false;
    auto basicMoves = getBasicMoves(startingLocation, falling);
    moves.insert(moves.end(), basicMoves.begin(), basicMoves.end());
    if (falling)
    {
        return moves;
    }
    if (player == HOP || player == JUMP)
    {
        auto hopMoves = getHopMoves(startingLocation);
        moves.insert(moves.end(), hopMoves.begin(), hopMoves.end());
    }
    if (player == SKIP || player == JUMP)
    {
        auto skipMoves = getSkipMoves(startingLocation);
        moves.insert(moves.end(), skipMoves.begin(), skipMoves.end());
    }
    if (player == JUMP)
    {
        auto jumpMoves = getJumpMoves(startingLocation);
        moves.insert(moves.end(), jumpMoves.begin(), jumpMoves.end());
    }
    return moves;
}
 
struct pairhash
{
public:
    template <typename T, typename U>
    std::size_t operator()(const std::pair<T, U> &x) const
    {
        return std::hash<T>()(x.first) ^ std::hash<U>()(x.second);
    }
};
 
void depthFirstSearch(pii startingLocation, char player)
{
    auto nodesToVisit = stack<pii>();
    auto nodesToVisitSet = unordered_set<pii, pairhash>();
    nodesToVisit.push(startingLocation);
    nodesToVisitSet.insert(startingLocation);
    while (!nodesToVisit.empty())
    {
        auto currentNode = nodesToVisit.top();
        nodesToVisitSet.erase(currentNode);
        nodesToVisit.pop();
        visited[currentNode.first][currentNode.second] = true;
        auto moves = getAvailableMoves(currentNode, player);
        for (auto var : moves)
        {
            if (!visited[var.first][var.second] && nodesToVisitSet.find(var) == nodesToVisitSet.end())
            {
                nodesToVisit.push(var);
                nodesToVisitSet.insert(var);
            }
        }
    }
}
 
void clearVisited()
{
    for (int a = 0; a < maxH; a++)
    {
        for (int b = 0; b < maxW; b++)
        {
            visited[a][b] = false;
        }
    }
}

void printResultsOnePlayer(pii startingLocation, char player, string playerName)
{
    clearVisited();
    depthFirstSearch(startingLocation, player);
    cout << playerName << " ";
    if (visited[cup.first][cup.second])
    {
        cout << CUP;
    }
    if (visited[flag.first][flag.second])
    {
        cout << FLAG;
    }
    if (visited[treasure.first][treasure.second])
    {
        cout << TREASURE;
    }
    cout << endl;
}
 
void printAllResults()
{
    printResultsOnePlayer(hop, HOP, "HOP");
    printResultsOnePlayer(skip, SKIP, "SKIP");
    printResultsOnePlayer(jump, JUMP, "JUMP");
    cout << endl;
}
 
int main()
{
   
    for (int i = 0; i < numberOfTestCases; i++)
    {
        readGraph();
        printAllResults();
    }
    return 0;
}