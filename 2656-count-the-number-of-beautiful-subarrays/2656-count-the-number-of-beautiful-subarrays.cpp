class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
    unordered_map<int, int> cnt{{0, 1}};
    partial_sum(begin(nums), end(nums), begin(nums), bit_xor<>());
    return accumulate(begin(nums), end(nums), 0LL, [&](long long s, int n){ return s + cnt[n]++; });
}
};