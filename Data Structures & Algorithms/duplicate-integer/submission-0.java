class Solution {
    public boolean hasDuplicate(int[] nums) {
        HashMap<Integer,Integer> hashMap = new HashMap<Integer,Integer>();
        for(Integer num : nums){
            hashMap.put(num,hashMap.getOrDefault(num,0)+1);
        }
        for (Integer key : hashMap.keySet()){
            Integer value = hashMap.get(key);
            if(value>1){
                return true;
            }
        }
        return false;
        
    }
}
