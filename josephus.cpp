#include <iostream>
#include <queue>

using namespace std;

int josephus(int n, int k) {
    queue<int> q;

    // Add all people to queue
    for (int i = 1; i <= n; i++) {
        q.push(i);
    }

    // Eliminate people until only one remains
    while (q.size() > 1) {
        for (int i = 0; i < k - 1; i++) {
            q.push(q.front());
            q.pop();
        }
        q.pop(); // Eliminate k-th person
    }

    // Return the number of the last remaining person
    return q.front();
}

int main() {
    int n, k;
    cout << "Enter the number of people: ";
    cin >> n;
    cout << "Enter the elimination interval: ";
    cin >> k;

    int survivor = josephus(n, k);
    cout << "The last remaining person is #" << survivor << endl;

    return 0;
}
