//Vedant Dhamecha-BVM
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// Function for valid course order
vector<string> findCourseOrder(vector<string>& courses, vector<pair<string, string>>& prerequisites) {
    // i make a graph for courses and their prerequisites
    unordered_map<string, vector<string>> graph;  // Map krke store kiya adjacency list
    unordered_map<string, int> inDegree;          // Map krke store kiya degrees of each course

    // graph ko populate krke indegree edge banaya
    for (const auto& prerequisite : prerequisites) {
        graph[prerequisite.second].push_back(prerequisite.first);  // Add directed edge
        inDegree[prerequisite.first]++;                             // Increment in-degree
    }

    //  queue banaya topological sort k liye
    queue<string> q;
    for (const string& course : courses) {
        if (inDegree.find(course) == inDegree.end()) {
            q.push(course);  // course add krte gaye degree 0 rkhke
        }
    }

    // topological sort perform kiya
    vector<string> order;
    while (!q.empty()) {
        string currentCourse = q.front();
        q.pop();
        order.push_back(currentCourse);  // add kiya course ko result order me

        // Update in-degrees of neighbors and add to queue if in-degree becomes 0
        for (const string& neighborCourse : graph[currentCourse]) {
            inDegree[neighborCourse]--;
            if (inDegree[neighborCourse] == 0) {
                q.push(neighborCourse);
            }
        }
    }

    //check kiya valid course hai ya nahi
    if (order.size() == courses.size()) {
        return order;  // return kiya valid course order
    } else {
        return {};  
    }
}

int main() {
    // Input kiya courses and prerequisite
    vector<string> courses = {"A", "B", "C", "D"};
    vector<pair<string, string>> prerequisites = {{"A", "B"}, {"C", "B"}, {"D", "B"}};

    // function call kiya
    vector<string> result = findCourseOrder(courses, prerequisites);

    // Output the result
    if (!result.empty()) {
        cout << "Valid course order:";
        for (const string& course : result) {
            cout << " " << course;
        }
        cout << endl;
    } else {
        cout << "No valid course order exists." << endl;
    }

    return 0;
}
