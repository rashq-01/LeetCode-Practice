class Solution {
struct Node {
        long long sum1 = 0;
        long long sum2 = 0;
        long long lazy = 0;
    };
    
    vector<Node> tree;
    const int MOD = 1e9 + 7;

    void push(int node, int l, int r) {
        if (tree[node].lazy != 0) {
            long long x = tree[node].lazy;
            int mid = l + (r - l) / 2;
            int len1 = mid - l + 1;
            int len2 = r - mid;

            // Left child
            tree[2 * node].sum2 = (tree[2 * node].sum2 + 2 * x * tree[2 * node].sum1 + x * x % MOD * len1) % MOD;
            tree[2 * node].sum1 = (tree[2 * node].sum1 + x * len1) % MOD;
            tree[2 * node].lazy = (tree[2 * node].lazy + x) % MOD;

            // Right child
            tree[2 * node + 1].sum2 = (tree[2 * node + 1].sum2 + 2 * x * tree[2 * node + 1].sum1 + x * x % MOD * len2) % MOD;
            tree[2 * node + 1].sum1 = (tree[2 * node + 1].sum1 + x * len2) % MOD;
            tree[2 * node + 1].lazy = (tree[2 * node + 1].lazy + x) % MOD;

            tree[node].lazy = 0; // Clear lazy value at current node
        }
    }

    void update(int node, int l, int r, int ql, int qr, long long x) {
        if (ql > r || qr < l) return;
        
        if (ql <= l && r <= qr) {
            long long len = r - l + 1;
            tree[node].sum2 = (tree[node].sum2 + 2 * x * tree[node].sum1 + x * x % MOD * len) % MOD;
            tree[node].sum1 = (tree[node].sum1 + x * len) % MOD;
            tree[node].lazy = (tree[node].lazy + x) % MOD;
            return;
        }
        
        push(node, l, r);
        int mid = l + (r - l) / 2;
        update(2 * node, l, mid, ql, qr, x);
        update(2 * node + 1, mid + 1, r, ql, qr, x);
        
        tree[node].sum1 = (tree[2 * node].sum1 + tree[2 * node + 1].sum1) % MOD;
        tree[node].sum2 = (tree[2 * node].sum2 + tree[2 * node + 1].sum2) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        tree.assign(4 * n + 1, Node());
        
        unordered_map<int, int> last_occurrence;
        long long total_sum = 0;
        
        for (int i = 0; i < n; ++i) {
            int start_idx = 0;
            if (last_occurrence.count(nums[i])) {
                start_idx = last_occurrence[nums[i]] + 1;
            }
            
            // Add +1 to the range [start_idx, i]
            update(1, 0, n - 1, start_idx, i, 1);
            
            // Update the last seen index of the current element
            last_occurrence[nums[i]] = i;
            
            // tree[1].sum2 contains the sum of squares of distinct counts for all subarrays ending at index i
            total_sum = (total_sum + tree[1].sum2) % MOD;
        }
        
        return total_sum;
    }
};