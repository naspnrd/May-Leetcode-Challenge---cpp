K Closest Points to Origin - 973

We have a list of points on the plane.  Find the K closest points to the origin (0, 0).

(Here, the distance between two points on a plane is the Euclidean distance.)

You may return the answer in any order.  The answer is guaranteed to be unique (except for the order that it is in.)

 

Example 1:

Input: points = [[1,3],[-2,2]], K = 1
Output: [[-2,2]]
Explanation: 
The distance between (1, 3) and the origin is sqrt(10).
The distance between (-2, 2) and the origin is sqrt(8).
Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
We only want the closest K = 1 points from the origin, so the answer is just [[-2,2]].

Example 2:

Input: points = [[3,3],[5,-1],[-2,4]], K = 2
Output: [[3,3],[-2,4]]
(The answer [[-2,4],[3,3]] would also be accepted.)

 

Note:

    1 <= K <= points.length <= 10000
    -10000 < points[i][0] < 10000
    -10000 < points[i][1] < 10000

	code:

// using sorting will take nlogn
struct comparePoints{ 
    bool operator()(const vector<int>& p1 , const vector<int>& p2){
        return (p1[0]*p1[0] + p1[1]*p1[1]) < ( p2[0]*p2[0] + p2[1]*p2[1]);
    }
};
/*
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        sort(points.begin(),points.end(),comparePoints());
        vector<vector<int>>result;
        for(int i = 0;i<K;i++)
            result.push_back(points[i]);
        return result;
    }
};
*/
//using max heap with priority queue takes O(nlogk)
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<vector<int>, vector<vector<int>> , comparePoints> pq;
        for(vector<int>& p : points){
            if(pq.size() < K)
                pq.push(p);
            else{
                const vector<int>& top = pq.top();
                int d1 = top[0]*top[0] + top[1]*top[1];
                int d2 = p[0]*p[0] + p[1]*p[1];
                if(d1 > d2)
                {
                    pq.pop();
                    pq.push(p);
                }
            }    
        }
        
             vector<vector<int>>result;
        while(!pq.empty()){
            result.push_back(pq.top());
            pq.pop();
        }
        return result;
    }
};
