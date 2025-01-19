// Credits to HealthyUG for the inspiration.
// Segment Tree with Point Updates and Range Queries
// Supports multiple Segment Trees with just a change in the Node and Update
// Very few changes required everytime
#include<iostream>
#include<vector>
using namespace std;
#define ll long int;
template<typename Node, typename Update>
// Node: Represents what is stored in each segment (e.g., sum, minimum, maximum).
// Update: Represents the type and nature of updates (e.g., increment, assignment, etc.).
#define ll long long 

struct SegTree {
	vector<Node> tree; // store the node of segment tree
	vector<ll> arr; // type may change
	int n; // size of original arrayy 
	int s; // size of segment tree
	SegTree(int a_len, vector<ll> &a) { // change if type updated
		arr = a;
		n = a_len;
		s = 1;
		// size of segement tree should be a power of 2 and it should be at least 2*n - 1, or size of segment tree is 4n
		// defining size of segment treee
		while(s < 2 * n){
			s = s << 1;
		}
		tree.resize(s); 
		fill(all(tree), Node());
		build(0, n - 1, 1);
	}
	void build(int start, int end, int index)  // Never change this
	{
		if (start == end)	{// leaf node
		// if we require the index too with value 
			// tree[index] = Node(arr[start],start); 
			tree[index] = Node(arr[start]);
			return;
		}
		int mid = (start + end) / 2;
		build(start, mid, 2 * index);
		build(mid + 1, end, 2 * index + 1);
		tree[index].merge(tree[2 * index], tree[2 * index + 1]);
	}
	void update(int start, int end, int index, int query_index, Update &u)  // Never Change this
	{
		if (start == end) {//point update , make an update only at leaf node in point update obv
			u.apply(tree[index]);
			return;
		}
		// going to the left or right half
		int mid = (start + end) / 2;
		if (mid >= query_index)
			update(start, mid, 2 * index, query_index, u);
		else
			update(mid + 1, end, 2 * index + 1, query_index, u);
		tree[index].merge(tree[2 * index], tree[2 * index + 1]);
	}
	Node query(int start, int end, int index, int left, int right) { // Never change this
	// tree range lies completly inside query range - 100percent contrubution
	// tree range is disjoint from quwerry range - 0percent 
	// tree range intersects with query range - left+right
		if (start > right || end < left)
			return Node();// for sum we return 0 , pr for ex we need min we would return infinity , so that is signify, 
			// so we dont define here 
		if (start >= left && end <= right) // complete overlap
			return tree[index];
		int mid = (start + end) / 2;
		Node l, r, ans;
		l = query(start, mid, 2 * index, left, right);
		r = query(mid + 1, end, 2 * index + 1, left, right);
		ans.merge(l, r);
		return ans;
		// makes sense till here 
	}
	void make_update(int index, ll val) {  // pass in as many parameters as required
		Update new_update = Update(val); // may change
		update(0, n - 1, 1, index, new_update);
	}
	Node make_query(int left, int right) {
		return query(0, n - 1, 1, left, right);
	}
};

// make changes int he below two parts only 
// if u want to store two nodes in a segment tree node make val1,val2 simple , eg : store range min and index

// identity element I -> operation bw x and i -> x
// x+i  -> x , in this case i shoudl be 0
//min(x,i) -> x , in this case i should be infinity

// range sum querise of sqyares of all values in a rang -> we will be storing sum of squares
// int sumi = accumulate(all(arr),0ll);
struct Node1 {

	ll val; // may change
	// ll index; if index also needed
	Node1() { // Identity element
		val = 0;	// may change
		// index = -1;
	}
	Node1(ll p1) {  // Actual Node
		// signify what u want to store related to that value seea bove eg in that we will be storign squares 
		// index = ind;pass int ind as Node1 argument
		val = p1; // may change 
	}
	// whatever operation u want to do define hered 
	void merge(Node1 &l, Node1 &r) { // Merge two child nodes
		// val = l.val ^ r.val;  // may change
		val = l.val+r.val;
		// if(l.val<r.val){
		// 	val = l.val;
		// 	index = l.index;
		// }else {
		// 	val = r.val ; index = r.index;
		// } in this above case with in identity element has to be define maximum
	}
};
// find your way to the particular leaf node and then update the value at that leaf node 

struct Update1 {
	ll val; // may change
	Update1(ll p1) { // Actual Update
		val = p1; // may change
	}
	// value store it and when u realch leaf node update that node with the value
	void apply(Node1 &a) { // apply update to given node
		a.val = val; // may change
		// for xor it will be a.val ^= val 
		// for inc it would be a.val+=val;
		// for min it would be a.val = val 
		// for change ti would be also a.val = val 
		// for gcd a.val = a.val - val doubt why '-'
	} 
};



void solve(){
	int n = 4;
	vector<ll> arr = {1,2,3,4};
	SegTree<Node1 , Update1> seg = SegTree<Node1 , Update1>(n,arr);
	Node1 ans = seg.make_query(0,3);
	cout<<ans.val<<endl;
	seg.make_update(2,10);
	cout<<seg.make_query(2,2).val<<endl ;
}
