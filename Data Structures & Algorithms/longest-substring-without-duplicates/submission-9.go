func lengthOfLongestSubstring(s string) int {
    mp := make(map[byte]int)
    var n int = len(s)
    var max_len = 0
    var start = 0

    for i:=0;i < n;i++{
        _,ok := mp[s[i]]
        if ok && mp[s[i]] >= start{
            start = mp[s[i]] + 1
        }
        mp[s[i]] = i
        max_len = max(max_len, i - start + 1)
    }

    return max_len
}
