func evaluate(s string, knowledge [][]string) string {
    mp := make(map[string]string)

    for i:=0;i<len(knowledge);i++{
        mp[knowledge[i][0]] = knowledge[i][1]
    }

    ans := ""
    n := len(s)
    for i:=0;i<n;i++{
        if s[i] == '(' {
            var start int = i+1
            for i<n && s[i]!=')'{
                i++
            }

            var end int = i
            var key string = s[start : end];

            if value,ok := mp[key];ok{
                ans += value
            }else{
                ans += "?"
            }
        }else{
            ans += string(s[i])
        }
    }

    return ans
}