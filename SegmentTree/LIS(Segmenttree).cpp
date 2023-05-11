class segtree {
public: 
	int n; 
	vector<int> st ;
	void init(int _n){
		this->n = _n ; 
		st.resize(4 * n , 0); 
	} 	
	int ops(int &a, int &b) {
		return max(a, b); 
	}
	void build(int start , int ending , int node , vector <int> &v){
		if(start == ending){
			st[node] = v[start] ; 
			return ; 
		}
		int mid = (start + ending) /2 ; 
		build(start , mid , 2 * node + 1 , v);
		build(mid + 1 , ending , 2 * node + 2 , v) ; 	
		st[node] = ops(st[2 * node + 1] , st[2 * node + 2]) ; 
	}
	int query(int start , int ending , int l , int r , int node){
		if(start > r or (ending < l)){
			return 0 ; 
		} if(start >= l and ending <= r){
			return st[node] ; 
		}
		int mid = (start + ending )/ 2 ; 
		int q1 = query(start , mid , l , r , 2 * node + 1) ; 
		int q2 = query(mid + 1 , ending , l , r , 2 * node + 2) ; 
		return ops(q1 , q2) ; 
	}
	void build(vector <int> &v){
		build(0 , v.size() - 1 , 0 ,v) ; 
	}
	void update(int start , int ending , int node , int index , int value){
		if(start == ending){
			st[node] = value ; 
			return ; 
		}
		int mid = (start + ending) /2 ; 
		if(index <= mid){
			update(start , mid , 2 * node + 1 , index , value) ; 
		}
		else{
			update(mid + 1 , ending , 2 * node + 2 , index , value) ; 
		}
		st[node] = ops(st[2 * node + 1] , st[2 * node + 2]) ; 
	}
	int query(int l , int r){
		return query(0 , n - 1 , l , r , 0); 
	}
	void update(int x ,int y){
		update(0 , n - 1 , 0, x , y); 
	}
};
class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        int N = (int) a.size(); 
    	vector<pair<int, int>> b (N); 
    	for(int i = 0; i < N; i++) {
    		b[i] = make_pair(a[i], i); 
    	}
        auto comp = [&] (const pair<int, int> &a, const pair<int,int> &b) {
            if(a.first == b.first) {
                return a.second > b.second; 
            }
            return a.first < b.first; 
        }; 
    	sort(b.begin(), b.end(), comp);
        segtree helper; 
	    helper.init(N); 
	    vector<int> dp(N, 0); 
	    vector<int> c (N); 
	    helper.build(c); 
    	for(int i = 0; i < N; i++) {
    		int value = b[i].first;
    		int idx = b[i].second; 
    		dp[idx] = helper.query(0, idx - 1) + 1; 
    		helper.update(idx, dp[idx]);
    	}
        for(auto & val : dp) {
            cout << val << " "; 
        }
        cout << endl; 
    	return *max_element(dp.begin(), dp.end()); 
    }
};
