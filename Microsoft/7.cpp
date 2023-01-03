/*

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

*/

class Solution {
public:
    
    //BFS
    
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        vector<int> adj[numCourses];
        for(auto edge:pre){
            adj[edge[0]].push_back(edge[1]);
        }
        
        vector<int> indegree(numCourses,0);
	    for(int i=0;i<numCourses;i++){
	        for(auto it: adj[i]) indegree[it]++;
	    }
	    
	    queue<int> pq;
	    for(int i=0;i<numCourses;i++){
	        if(indegree[i]==0) pq.push(i);
	    }
	    
        int cnt=0; //only pushing 0 indegrees in queue so node in cycle can never make indegree 0 of each other so they wont get pushed in queue
        
	    while(!pq.empty()){
	        int curr = pq.front();
	        pq.pop();
	        cnt++;
	        
	        for(auto it: adj[curr]){
	            indegree[it]--;
	            if(indegree[it]==0) pq.push(it);
	        }
	    }
	    return cnt==numCourses;
    }
    
    
    
    
    
    
    
    
    //DFS
    
    bool isCycle(int node,vector<int> &vis,vector<int> adj[],vector<int> &visDfs){
        vis[node] =1;
        visDfs[node] = 1;
            for(auto itr : adj[node]){
                if(!vis[itr]){
                    if(isCycle(itr,vis,adj,visDfs)) return true;
                    }
                else{
                   if(visDfs[itr]==1) return true; 
                }
            }
        visDfs[node] = 0;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> vis(numCourses,0);
        vector<int> visDfs(numCourses,0);
        vector<int> adj[numCourses];
        if(!prerequisites.size()) return true;
        
        for(auto edge:prerequisites){
            adj[edge[0]].push_back(edge[1]);
        }
        
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if( isCycle(i,vis,adj,visDfs) ) return false;
            }
        }
        return true;
    }
};
