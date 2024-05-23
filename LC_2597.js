/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var beautifulSubsets = function(nums, k) {
    var n=nums.length;
    var rec = (i,arr) => {
        if(i===n) return 1;

        var ct=rec(i+1,arr);
        if(!arr.includes(nums[i]-k) && !arr.includes(nums[i]+k)){
            arr.push(nums[i]);
            ct += rec(i+1,arr);
            arr.pop();
        }
        return ct;
    }
    return rec(0,[])-1;
};