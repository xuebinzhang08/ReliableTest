class Solution {
public:
    vector<int> twoSum_BruteForce(vector<int>& nums, int target) {
        int size = nums.size();

        for(int i=0; i<size; i++){
            for(int j=i+1; j<size; j++){
                if(nums[i]+nums[j] == target){
                    return {i, j};
                }
            }
        }
        return {};
    }
    vector<int> twoSum_HashMap(vector<int>& nums, int target) {
        int size = nums.size();

        unordered_map<int, int> sorted;
        for(int i = 0; i<size; i++){
            auto index = sorted.find(target - nums[i]);
            if(index!=sorted.end()){
                return vector<int> {i, index->second};
            }
            sorted[nums[i]] = i;
        }
        return {};
    }
    vector<int> twoSum_HashMapWithout_iterator(vector<int>& nums, int target) {
        int size = nums.size();
        unordered_map<int, int> hash;
        for(int i=0; i<size; i++){
            if(hash.find(target - nums[i]) != hash.end()){
                return {hash[target - nums[i]], i};
            }
            hash[nums[i]] = i;
        }
        return {};
    }
};
