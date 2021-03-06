int arr[MAXN], tail_table[MAXN] = {0}, n, indices[MAXN];
int parent[MAXN], last_elem_idx = -1;
vector<int> lis;

// Return index of first element doesn't compare less than
// k in tail_table
int ceil_index(int l, int r, int k) {
	int m;
	while(r - l > 1){
		m = l + (r-l)/2;
		(tail_table[m] >= k?r: l) = m;
	}
	return r;
}

void create_lis() {
	int temp = last_elem_idx;
	while(temp != -1){
		lis.PB(arr[temp]);
		temp = parent[temp];
	}
	reverse(lis.begin(), lis.end());
	cout<<lis;
}

int find_lis() {
	int res = 0;
	tail_table[0] = arr[0];
	res = 1;
    for(int i = 0; i < MAXN; i++)   parent[i] = -1;
	last_elem_idx = 0;
    for(int i = 1; i < n; i++) {
		if(arr[i] < tail_table[0]){
			tail_table[0] = arr[i];
			if(res == 1){
				last_elem_idx = i;
			}
		}
		else if(arr[i] > tail_table[res-1]){
			indices[res] = i;
			tail_table[res++] = arr[i];
			parent[i] = last_elem_idx;
			last_elem_idx = i;
		}
		else{
			// tail_table[ceil_index(-1, res-1, arr[i])] = arr[i];
			int temp = int(lower_bound(tail_table, tail_table+res, arr[i])-tail_table);
			parent[i] = parent[indices[temp]];
			tail_table[int(lower_bound(tail_table, tail_table+res, arr[i])-tail_table)] = arr[i];
			indices[temp] = i;
			if(res == temp+1){
				last_elem_idx = i;
			}
		}
	}
	return res;
}
