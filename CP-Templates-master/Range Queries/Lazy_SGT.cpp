// Lazy Segment Tree with Range Updates and Range Queries
// Supports multiple Segment Trees with just a change in the Node and Update
// Very few changes required everytime

template<typename Node, typename Update>
// node represent what are u storign in segemnt tree and u stores what is the nature of the update , majouly they are going to be integeres or sometimes pair or custom strucutre (itne aukaat nhi h mere)
#define ll long long 
struct LazySGT {
    // we have 3 segment trees 
    vector<Node> tree;
    vector<bool> lazy;// make if a node has pendign updatae , if its trur then some update will be present that need to be apply 
    vector<Update> updates;// store pending updates for lazy propogation
    vector<ll> arr; // type may change
    int n; // size of actuall array 
    int s; // sizes of segment tree
    LazySGT(int a_len, vector<ll> &a) { // change if type updated
        arr = a;
        n = a_len;
        s = 1;
        while(s < 2 * n){
            s = s << 1;
        }
        tree.resize(s); fill(all(tree), Node());
        lazy.resize(s); fill(all(lazy), false);
        updates.resize(s); fill(all(updates), Update());
        build(0, n - 1, 1);
    }
    void build(int start, int end, int index) { // Never change this
        if (start == end)   {
            tree[index] = Node(arr[start]);
            return;
        }
        int mid = (start + end) / 2;
        build(start, mid, 2 * index);
        build(mid + 1, end, 2 * index + 1);
        tree[index].merge(tree[2 * index], tree[2 * index + 1]);
    }
    // pushes the lazy update from a node to its children , resets the current nodes lazy status


    //lazy[index] = 1 , means some changes are need to be oushed downn

    void pushdown(int index, int start, int end){
        // checkin some pending changes 
        if(lazy[index]){
            int mid = (start + end) / 2;
            // apply the changes 
            apply(2 * index, start, mid, updates[index]);
            apply(2 * index + 1, mid + 1, end, updates[index]);
            updates[index] = Update();
            lazy[index] = 0;
        }
    }
    // applies an update to the current nod e, if its not a leaf , marks it as lazy and store the update for future propogation 
    void apply(int index, int start, int end, Update& u){
        if(start != end){
            lazy[index] = 1;
            updates[index].combine(u, start, end);
        }
        u.apply(tree[index], start, end);
    }
    //
    void update(int start, int end, int index, int left, int right, Update& u) {  // Never Change this,
        // complete overlap , disjoint , partial overlap 

        // disjoint 
        if(start > right || end < left)
            return;
        // complete overlap
        if(start >= left && end <= right){
            apply(index, start, end, u);
            return;
        }
        // here i am assuming current node is is the most update state and i   pushdown current changes to left and right so we are making sure when we are going to left and right , they will be in teh most updated state , we dont only push down but also apply ut 
        pushdown(index, start, end);
        int mid = (start + end) / 2;
        update(start, mid, 2 * index, left, right, u);
        update(mid + 1, end, 2 * index + 1, left, right, u);
        tree[index].merge(tree[2 * index], tree[2 * index + 1]);
    }
    Node query(int start, int end, int index, int left, int right) { // Never change this
        if (start > right || end < left)
            return Node();
        if (start >= left && end <= right){
            pushdown(index, start, end); // even if you comm it out it will work , its in updated state only 
            return tree[index];
        }
        pushdown(index, start, end);
        int mid = (start + end) / 2;
        Node l, r, ans;
        l = query(start, mid, 2 * index, left, right);
        r = query(mid + 1, end, 2 * index + 1, left, right);
        ans.merge(l, r);
        return ans;
    }
    void make_update(int left, int right, ll val) {  // pass in as many parameters as required
        Update new_update = Update(val); // may change
        update(0, n - 1, 1, left, right, new_update);
    }
    Node make_query(int left, int right) {
        return query(0, n - 1, 1, left, right);
    }
};

struct Node1 {
    ll val; // may change
    Node1() { // Identity element
        val = 0;    // may change
    }
    Node1(ll p1) {  // Actual Node
        val = p1; // may change
    }
    void merge(Node1 &l, Node1 &r) { // Merge two child nodes
        val = l.val + r.val;  // may change
        //identifier max undefined aa rha ha check kro
        // val = max(l.val, r.val); // may change
        // val - gcd(l.val, r.val); // may change
    }
};

struct Update1 {
    ll val; // may change
    Update1(){ // Identity update
        val = -1;
    }
    Update1(ll val1) { // Actual Update
        val = val1;
    }
    // function which apply update to an node 

    void apply(Node1 &a, int start, int end) { // apply update to given node
        if(val == -1) return;
        a.val = val * (end - start + 1); // may change
        // if increment range by value
    }
    // it combines the result of two node in teh segment tree
    void combine(Update1& new_update, int start, int end){
        val = new_update.val;
    }
};
// we can make muktilple segemttn tree just make another node and update 

void solve(){
    int n = 4;

}