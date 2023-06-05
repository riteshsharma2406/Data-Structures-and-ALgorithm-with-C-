    int kthSmallest(int arr[], int l, int r, int k) {
        //code here
        priority_queue<int>pq;
        
        for(int i=0; i<k; i++)
        {
            pq.push(arr[i]);
        }
        
        for(int i=k; i<=r; i++)
        {
            int element = arr[i];
            if(element<pq.top())
            {
                pq.pop();
                pq.push(element);
            }
        }
        int ans = pq.top();
        return ans;
    }
