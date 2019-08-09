// create compare with lambda C++14 

#include <queue>
#include <vector>

using namespace std;

auto comp = [](const ListNode *a, const ListNode *b ) { return a->val > b->val; };
priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> pq(comp);

// make vector unqiue
vec.erase( unique( vec.begin(), vec.end() ), vec.end() );

// set pricision
#include <iomanip>
cout << setprecision(11) << output << endl;