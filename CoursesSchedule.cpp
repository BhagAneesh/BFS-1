class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        int indegrees[numCourses];
        unordered_map<int, vector<int>> map;
        int count = 0;

        for(vector<int> pr:prerequisites )
        {
            indegrees[pr[0]]++;
            if(!map.contains(pr[1]))
            {   
                vector<int> temp;
                map.insert(pr[1],temp);
            }
            map.find(pr[1].insert(pr[0]));
        }
        
        queue<int> q;
        for(int i = 0; i<indegrees.size();i++)
        {
            if(indegrees[i] == 0)
            {
                q.insert(i);
                count++;
            }
        }

        if(count == numCourses) return true;

        while(!q.empty())
        {
            int course = q.front();
            q.pop();
            vector<int> li = map.find(course);

            if(li!= NULL)
            {
              for(int i:li )
              {
                  indegrees[i]--;
                  if(indegrees[i] == 0)
                    {
                        q.insert(i);
                        count++;
                    }
              }
              if(count == numCourses) return true;

          
            }

        }
    }
};